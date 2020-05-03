
//https://webbibouroku.com/Blog/Article/atcoder-abc153

#include<bits/stdc++.h>

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;

struct magic
{
    int at;
    int mp;
};

int main(){
    int H,N;
    cin>>H>>N;
    vector<int> dp(H+1,INT_MAX);
    dp[0]=0;
    vector<magic> S(N);

    for(int i=0; i<N;i++){
        cin>>S[i].at>>S[i].mp;
    }

    for(int i=0;i<H+1;i++)
    {
        if(dp[i]==INT_MAX) continue;

        for(int j=0;j<N;j++)
        {
            int next=min(H,i+S[j].at);
            dp[next]=min(dp[next],dp[i]+S[j].mp);
        }
    }

    cout<<dp[H]<<endl;
}