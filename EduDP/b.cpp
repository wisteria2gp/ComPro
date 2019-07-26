//Frog2
#include<iostream>
#include<vector>
using namespace std;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF=1LL<<60;

long long h[100010];
long long dp[100010];


int main()
{
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;++i) cin>>h[i];

    for(int i=0;i<100010;++i)dp[i]=INF;
    dp[0]=0;

    for(int i=0;i<n;++i)
    {
        for(int j=1;j<=k;++j)
        {
            chmin(dp[i+j],dp[i]+abs(h[i]-h[i+j]));
        }

    }

    cout<<dp[n-1]<<"\n";    
}