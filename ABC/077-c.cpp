

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



int main()
{
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];
    sort(a.begin(),a.end());
    
    vector<int> b(n);
    rep(i,n) cin>>b[i];
    sort(b.begin(),b.end());
    
    vector<int> c(n);
    rep(i,n) cin>>c[i];
    sort(c.begin(),c.end());

    // std::upper_bound()を用いてbの各要素を基準に
    // そのbの各要素xより小さいaの要素、xより大きいcの要素のindexを取得する(正確にはiterator)
    // それをもとに条件を満たす組を数える
    // 計算量としては
    // bについてのforでO(N),その中でa,cについての二分探索でO(2*logN)
    // 以上からO(NlogN) , N=10^5なので、OK

    vec<int>::iterator lower_a,upper_c; 
    
    ll idx_lower,idx_upper;
    ll ans=0;
    ll len_c=c.size();

    for(const auto& e:b){
        lower_a=lower_bound(a,begin(),a.end(),e);
        upper_c=upper_bound(c.begin(),c.end(),e);
        idx_lower=distance(a.begin(),lower_a);
        idx_upper=distance(c.begin(),upper_c);
        
        ans+=idx_lower*(len_c-idx_upper);
    }




    return 0;

}


