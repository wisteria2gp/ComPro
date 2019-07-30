
/*
ナップザック問題

 */
#include <iostream>
#include <string.h>
#include <vector>
#define ll long long
using namespace std;


template <class T>
inline bool chmax(T &a, T b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class T>
inline bool chmin(T &a, T b)
{
    if (a > b)
    {
        a = b;
        return true;
    }
    return false;
}


const long long INF = 1LL << 60;

const int MAX_N = 110;
const int MAX_W = 100100;

int n, w;
ll weight[MAX_N], value[MAX_N];
//dpの初期化 正数だけの条件で最大化なので0か-1あたりが良い
ll dp[MAX_N][MAX_W]={0};

int main()
{
    cin >> n >> w;
    for (int i = 0; i < n; ++i)
        cin >> value[i]>> weight[i] ;

    /*
    dp[i][sum_w]:品0-(i-1)までで重量sum_w以下のときの最大価値
    weight,valueの品番は0インデックスだがdpはi=0のときは品なし、i=1で品番0(問題文なら１)までであることに注意
    解はdp[n][w]
    */
    for (int i = 0; i < n; ++i)
    {
        // cout<< "i="<<i <<"\n";
        for (int sum_w = 0; sum_w <= w; ++sum_w)
        {
            /*
            dp[i+1][sum_w]の更新

            dp[i+1][sum_w]は未探査なら0
            イテレータiでdp[i+1]を更新していく
            */

            //品iを選べるときは　選ぶ or 選ばない　で比較
            if(sum_w-weight[i]>=0)
                chmax(dp[i+1][sum_w],dp[i][sum_w-weight[i]]+value[i]);
            
            //品iを選ばなかったときの比較
            //これを常に行わないと品iを選ばなかったときの過去の部分最適との比較が行われない
            chmax(dp[i+1][sum_w],dp[i][sum_w]);
           
        //    cout<<"sum_w="<<sum_w<<"\n";
        //    cout<<dp[i+1][sum_w]<<"\n";
           
        }
    }


    cout<<dp[n][w]<<"\n";
}
