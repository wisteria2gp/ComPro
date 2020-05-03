

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


ll func(ll a,ll b,ll x){
    return floor(a*x/b)-a*floor(x/b);
}

ll a,b,n;

int main()
{
    cin>>a>>b>>n;
    ll ans=0;
    // ll tmp;
    // loop(i,0,a){
    //     tmp=func(a,b,i);
    //     ans=max(ans,tmp);
    // }
    if(n>=b-1){
        ans=func(a,b,b-1);
    }else{
        ans=func(a,b,n);
    }
    
    cout<<ans<<endl;
    return 0;

}


