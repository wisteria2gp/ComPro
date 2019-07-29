/*
 Knapsack 1  ナップザック問題１
深さ優先探索による解法
全探索なのでほぼ確実にTLEに陥る
TLEじゃないWAも出る、どこの条件で間違ってるかわかってない
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
int w[110],v[110];
// int dp[110][100100];

//i=0,sum_w=0からスタート
long long rec(int i,int sum_w)
{
    int res;
    //1から始まるインデックスでN+1にたどり着く->もう商品がないので選択として存在しない->価値最大値0
    if(i==N+1)  res=0;
    //総重量W-現在重量sum_w<品iの重さw[i]のとき、iを選ぶことは不可能
    else if(W-sum_w<w[i]) res=rec(i+1,sum_w);
    //品iを選ぶことができるとき、選ぶor否 で分岐する
    else
    {
        res=max(
            rec(i+1,sum_w),
            rec(i+1,sum_w+w[i])+v[i]
        );
    }
    return res;
}

int main()
{
    cin>>N>>W;
    for(int i=0;i<N;++i)
    {
        cin>>w[i]>>v[i];
    }

    cout << rec(0, 0) << endl;
}