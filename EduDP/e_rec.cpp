/*
Knapsack 2  ナップザック問題2
メモ再帰による解法
W<10^9なのでこれを第２インデックスにするとDPテーブルが巨大化し計算量が爆発する
dp[index][sum_value]=sum_weight　に転換する
 */

#include <string.h>
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
const int MAX_N=110;
const int MAX_V=100100;

const long long INF=1LL<<60;

int N;

long long W,weight[110],value[110];

long long dp[MAX_N][MAX_V];

//i番目以下のindexの品から重量がsum_wになるように選んだときの
//取りうる価値の総和の最大値を返す関数
long long rec(long long i,long long sum_v)
{
    if(sum_v==0)
    {
        return 0;
    }

    if(i==-1)
    {
        return INF;
    }

    //すでに探索していたら結果を再利用
    if(dp[i][sum_v]!=-1)
    {
        return dp[i][sum_v];
    }

    //現在重量を表す変数
    long long res;

    if(sum_v<value[i]) res=rec(i-1,sum_v);
    else
    {
        res=min(
        rec(i-1,sum_v),
        rec(i-1,sum_v-value[i])+weight[i]);
    }

    return dp[i][sum_v]=res;
}

int main()
{   
    // メモ化テーブルを-1で初期化　以下のforループと等価
    //<string.h>をincludeすると利用可能
    memset(dp, -1, sizeof(dp));
            

    cin>>N>>W;
    for(int i=0;i<N;++i)
    {
        cin>>weight[i]>>value[i];
    }

    long long ans=0;
    for(long long sum_v=0;sum_v<=100*1000;++sum_v)
    {
        if(rec(N-1,sum_v) <=W)ans=max(ans,sum_v);
    }
    cout <<  ans << endl;
}

