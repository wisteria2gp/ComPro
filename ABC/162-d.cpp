

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

/*--- *n1≦*n2≦*n3となるように並べ替える ---*/
void sort3(int *n1, int *n2, int *n3)
{
    if (*n1 > *n2) swap(*n1, *n2);
    if (*n2 > *n3) swap(*n2, *n3);
    if (*n1 > *n2) swap(*n1, *n2);
}

int n;
string s;

int main()
{
    cin>>n>>s;
    ll sum=0;

    vec<int> r={};
    vec<int> g={};
    vec<int> b={};

    rep(i,n){
        if(s[i]=='R')r.push_back(i);
        else if(s[i]=='G')g.push_back(i);
        else if(s[i]=='B')b.push_back(i);
    }

    int tmp_i,tmp_j,tmp_k;    

    for(auto& i:r){
        for(auto& j:g){
            for(auto& k:b){
                tmp_i=i;
                tmp_j=j;
                tmp_k=k;
                sort3(&tmp_i,&tmp_j,&tmp_k);
                //cout<<s[tmp_i]<<" "<<s[tmp_j]<<" "<<s[tmp_k]<<endl;
                if(tmp_j-tmp_i!=tmp_k-tmp_j)sum++;
            }
        }
    }



    cout<<sum<<endl;


    return 0;

}


