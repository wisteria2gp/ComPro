#include <bits/stdc++.h>

//rep(i,n) : for(int i=0 ; i < n ; i++) : i=0 ~ n-1
#define rep(i, n) for (int i = 0, i##_len = (n); i < i##_len; ++i)
//reps(i,n) : for(int i=1 ; i <= n ; i++) : i=1 ~ n
#define reps(i, n) for (int i = 1; i##_len = (n); i <= i##_len; ++i)
//ALL(x) : sort(v.begin(), v.end()); == sort(ALL(v));
#define ALL(x) (x).begin(), (x).end()
//pb
#define pb push_back
//SZ(x)
#define SZ(x) ((int)(x).size)

using namespace std;

//DP用の関数　chminとchmax
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

//INF
const long long INF = 1LL << 60;

const int MAX_N = 110000;

// DP テーブル
long long memo[MAX_N];

//メモ化DPの必要があるらしいのでメモ化再帰する
int rec(int n)
{
    if (n == 0)
        return 0; //終端条件 満たすべき額が0になったら終わり
    if (memo[n] != -1)
        return memo[n]; //すでに探索済みなら終わり
    int res = n;        //金額の残量=1だけで構成したときの枚数=最大枚数

    //1,6^1,6^2,...を試す(n以下)
    //pow6が１回の引きおとし額、1から順に総額n以下で探索
    //あるnのとき残額を最小化する引き落とし額をメモしていく
    for (int pow6 = 1; pow6 <= n; pow6 *= 6)
    {
        res = min(res, rec(n - pow6) + 1);//ここでrec使用
    }
    //ここで言っているのは6^x+yと1+yは等価であるということ
    //いまのnに対してn-pow6を再帰recに渡し、各ループでのn-pow6に対する最小resを返す

    //1,9^1,9^2,...
    //6系列で探索したresが残っているので９のときさらに小さくできるか調べている
    for(int pow9=1; pow9<=n;pow9*=9)
    {
        res=min(res,rec(n-pow9)+1);//ここでrec使用
    }
    //6系列で書いたことと同じことを9についてもやる
    //6,9両方について、現在のnに対する最小引き落とし回数を調べることができた

    //結果のres(枚数)を記録
    //再帰することで標準入力のnより小さい金額についてもメモされていることになる
    return memo[n]=res;
        
}

int main()
{
    int N;
    scanf("%d",&N);
    // DP テーブル全体を初期化 (最小化問題なので INF に初期化)
    rep(i, MAX_N) memo[i] = -1;

    cout << rec(N) << endl;

}
