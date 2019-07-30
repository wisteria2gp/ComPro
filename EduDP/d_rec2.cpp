#include <string.h>
#include<iostream>
#include<vector>
#define ll long long
using namespace std;


const int MAX_N=110;
const int MAX_W=100100;
const ll MAX_V=1000000000;

ll weight[MAX_N],value[MAX_N];
int N,W;
 

const ll INF=1LL<<60;

ll dp[MAX_N][MAX_W];

/*
    品0-iまでで重量sum_wとなるときの最大価値をdpに保存
    return でdp[i][sum_w]　を返すことで部分問題に分解する

    solveに際してはrec(N-1,W)で用いて解を返す
    (0indexなので品番は0-N-1)
 */
ll rec(int i,int sum_w)
{
    //負の品番は存在しないので価値0でリターン
    if(i==-1 ) return 0;

    //探索済みならそのまま返す
    if(dp[i][sum_w]!=-1) return dp[i][sum_w];

    ll res;
    //重量的に品iを選択できるとき
    if(sum_w-weight[i]>=0)
    {
        /*
            (i非選択)品i-1まででsum_w以下最大価値と
            (i選択)品i-1まででsum_w-weight[i]以下の最大価値+品iの価値
            の比較をして大きい方を取る
         */
        res=max(rec(i-1,sum_w),rec(i-1,sum_w-weight[i])+value[i]);
    }
    /*
        品iを選ぶ重量的余裕がなければ
        (i非選択)品i-1まででsum_w以下最大価値
        のみとりうる
    */
    else res=rec(i-1,sum_w);

    return dp[i][sum_w]=res;


}

int main()
{
    memset(dp,-1,sizeof(dp));

    cin>>N>>W;

    for(int i=0;i<N;++i)
    {
        cin>>weight[i]>>value[i];
    }

    cout<<rec(N-1,W)<<endl;
}