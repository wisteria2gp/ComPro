//diff commandの核であるレーベンシュタイン距離を求める問題
// 二次元dpの例題



#include<bits/stdc++.h>



#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template <class T>
using vec = std::vector<T>;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// const long long INF = 1LL<<60;
const int INF=1<<29;

int lcm(int a,int b){
    //最小公倍数
    return a/__gcd(a,b) * b;
}



string s,t;

int dp[1010][1010];

int main(){
    cin>>s>>t;


    rep(i,1010){rep(j,1010){ dp[i][j]=INF;}}
    dp[0][0]=0;

    loop(i,-1, (int)s.size()){
        loop(j,-1,(int)t.size()){
            if(i==-1 && j==-1) continue; //dp[0][0]はすでに考慮した
            
            if(i>=0 && j>=0){
                if(s[i]==t[j]) dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                else dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+1);
            }

            if(i>=0)dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j+1]+1);
            if(j>=0)dp[i+1][j+1]=min(dp[i+1][j+1],dp[i+1][j]+1);
        }
    }

    cout<<dp[s.size()][t.size()]<<endl;
}
