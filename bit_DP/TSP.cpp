//traveling salesman problem

#include<iostream>
#include<bitset>
using namespace std;
nst int INF=100000000;

int N;
int dist[21][21];

int dp[(1<<20)+1][21];

/*
メモ再帰
bitが部分集合Sを表すフラグ,vは再帰における前回
*/
int rec(int bit,int v)
{
    //探索済みはリターン
    if(dp[bit][v]!= -1) return dp[bit][v];

    //初期条件
    if(bit == (1<<v))
    {
        return dp[bit][v]=0;
    }

    //解となるコストを記録する変数
    int res=INF;

    /* 
    prev_bit : bitのvを除いたもの 
    部分集合Sの最後がvである、というDPテーブルを仮定する
    そのためuはvを選択できない,S-{v}から選ぶことを表す
    */
    int prev_bit = bit& ~(1<<v);
    //vの手前のノードとしてuを全探索
    for(int u=0;u<N;++u)
    {
        if(!(prev_bit &(1<<u))) continue;

        //再帰の中核
        if(res>rec(prev_bit,u)+dist[u][v])
        {
            res=rec(prev_bit,u)+bist[u][v];
        }
    }

    return dp[bit][v]=res;//メモしながらリターン
}

int main()
{
    // 入力
    cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> dist[i][j];
        }
    }

    // テーブルを全部 -1 にしておく (-1 でなかったところは探索済)
    for (int bit = 0; bit < (1<<N); ++bit) for (int v = 0; v < N; ++v) dp[bit][v] = -1;

    // 探索
    int res = INF;
    for (int v = 0; v < N; ++v) {
        if (res > rec((1<<N)-1, v)) {
            res = rec((1<<N)-1, v);
        }
    }
    cout << res << endl;
}
