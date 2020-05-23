

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


// int型の2次元配列(3×4要素の)の宣言
// vector<vector<int>> data(3, vector<int>(4));



// まずin-place dp でやる=>品物番号省略
// 制約からweightは添字にしない
// 価値DPをする

int main()
{
    ll n,W;cin>>n>>W;
    vec<ll> dp(100100,INF);//その価値だすための値の最小重量を記録する
    dp[0]=0; //val=0 <=> weight=0 初期条件
    ll weight,value;
    loop(i,1,n+1){ //次のvのfor文で1000*1から始めるためにi=1,2,...,n 
        cin>>weight>>value;
        for(ll v=1000*i;v>=value;v--){
            dp[v]=min(dp[v],dp[v-value]+weight);
            // dp[0]から積んでいく
            // i=0のループで、v==valueのとき
            // dp[v]=min(dp[v],dp[0]+weight)=min(INF,weight)=weight
            // ここでv=value+1以降は実現不可なため重さINFと定義する
        }
    }
    // valueの総和はたかだか10^3**10^2=10^5なので
    // 100000までみてW以下の最大の値を回答とする
    ll ans=0;
    for(ll i=0;i<=100000;i++)if(dp[i]<=W)ans=i;
    cout<<ans<<endl;
    return 0;

}


