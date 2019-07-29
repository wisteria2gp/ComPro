/*
Knapsack 1  ナップザック問題１
メモ再帰による解法
 */


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

int N,W;

int weight[100100],value[100100];

int dp[110][100100];

//i番目以下のindexの品から重量がsum_wになるように選んだときの
//取りうる価値の総和の最大値を返す関数
int rec(int i,int sum_w)
{
    //すでに探索していたら結果を再利用
    if(dp[i][sum_w]!=-1)
    {
        return dp[i][sum_w];
    }

    int res;
    // 
    if(i==N)
    {
        res=0;
    }
    //
    else if(sum_w<weight[i])
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
    memset(dp, -1, sizeof(dp)); // メモ化テーブルを-1で初期化　以下のforループと等価
    cout << rec(0, 0) << endl;
}

