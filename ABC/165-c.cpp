

#include<bits/stdc++.h>



#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template <class T>
using vec = std::vector<T>;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL<<60;

int lcm(int a,int b){
    //最小公倍数
    return a/__gcd(a,b) * b;
}


// 配列からk個の要素の組み合わせを取り出すための関数
// これをかけた後の入力vectorの先頭k要素を取るとそのCombinationの１つとなっている
// 全列挙ならwhile文に入れて使う。
// この問題が
template <typename Iterator>
inline bool next_combination(const Iterator first, Iterator k, const Iterator last)
{
   /* Credits: Thomas Draper */
   if ((first == last) || (first == k) || (last == k))
      return false;
   Iterator itr1 = first;
   Iterator itr2 = last;
   ++itr1;
   if (last == itr1)
      return false;
   itr1 = last;
   --itr1;
   itr1 = k;
   --itr2;
   while (first != itr1)
   {
      if (*--itr1 < *itr2)
      {
         Iterator j = k;
         while (!(*itr1 < *j)) ++j;
         iter_swap(itr1,j);
         ++itr1;
         ++j;
         itr2 = k;
         rotate(itr1,j,last);
         while (last != j)
         {
            ++j;
            ++itr2;
         }
         rotate(k,itr2,last);
         return true;
      }
   }
   rotate(first,k,last);
   return false;
}


int n,m,q;



int main()
{
    cin>>n>>m>>q;
    vec<ll> a(q),b(q),c(q),d(q);
    rep(i,q){
        cin>>a[i]>>b[i]>>c[i]>>d[i];
        a[i]--;
        b[i]--;
    }
    vector<ll> A(n),v(n*m+100);
    ll ans=0;
    // iota(v.begin(), v.end(), 1); //1からはじめるm要素の列

    rep(i,m){
        rep(j,n+1){
            v[i*n+j]=i+1;
        }
    }
    do{
        copy(v.begin(),v.begin()+n,A.begin());
        ll tmp=0;
        rep(i,q){
            if(A[b[i]]-A[a[i]]==c[i]){
                tmp+=d[i];
            }
        }
        ans=max(tmp,ans);

    }while(next_combination(v.begin(),v.begin() + n,  v.end()-100));

    cout<<ans<<endl;

    return 0;

}


