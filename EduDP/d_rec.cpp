/*
Knapsack 1  ナップザック問題１
メモ再帰による解法
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

const long long INF=1LL<<60;

long long N,W;

long long weight[100100],value[100100];

long long dp[110][100100];

//i番目以下のindexの品から重量がsum_wになるように選んだときの
//取りうる価値の総和の最大値を返す関数
long long rec(int i,int sum_w)
{
    //すでに探索していたら結果を再利用
    if(dp[i][sum_w]!=-1)
    {
        return dp[i][sum_w];
    }
    //現在価値を表す変数
    long long res;
    //品番N+1以降は存在しないのでres=0
    if(i==N)
    {
        res=0;
    }
    //重量の余りが品iの重さを下回っていたら選択できない
    else if(W-sum_w-weight[i]<0)
    {
        res=rec(i+1,sum_w);
    }
    else
    {
        res=max(
            rec(i+1,sum_w),
            rec(i+1,sum_w+weight[i])+value[i]
        );   
    }
    return dp[i][sum_w]=res;
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
    cout << rec(0, 0) << endl;
}

