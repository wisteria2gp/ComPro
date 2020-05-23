

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
    int n,W;cin>>n>>W;
    vec<int> weight(n+10);
    vec<int> val(n+10);
    rep(i,n){
        cin>>weight[i]>>val[i];
    }
    vec<vec<ll>> dp(n+100,vec<ll> (W+100,0)); //dp[(商品id)][(総重量w以下)]

    rep(i,n){
        rep(w,W+1){
            if(w<weight[i]) dp[i+1][w]=dp[i][w];
            else dp[i+1][w]=max(dp[i][w],dp[i][w-weight[i]]+val[i]);
            
        }
    }

    cout<<dp[n][W]<<endl;

    return 0;

}


