
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


int n;
map<int,ll> m;
map<int,ll>done;

int main()
{
    cin>>n;
    vec<int> a(n,-1);
    rep(i,n){
        cin>>a[i];
        m[a[i]]++;
    }

    ll res=0;
    ll val=0;
    for(auto v=m.begin() ; v!=m.end() ; ++v){
        val=v->second;
        res+=val*(val-1)/2;
    }
    for(auto v=m.begin() ; v!=m.end() ; ++v) done[v->first]=res-(v->second)+1;
    


    rep(i,n){
        // cout<<"already done it"<<endl;
        cout<<done[a[i]]<<endl;
    }
    return 0;

}


