#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

//INF
const long long INF = pow(10,9);

void chmin(int &a, int b){if (a > b) a = b;}

int N, A, B, C;
vector<int> L;

//再帰
//i は竹の添字
int rec(int i, int a, int b, int c)
{
    //竹をi=0-Nまで見終わったとき
    if(i==N)
    {
        if(!a || !b || !c) return INF;//a,b,cどれか1つでも0のときは竹をつかっていないのでNG
        return abs(a-A)+abs(b-B)+abs(c-C); //合体してできるa,b,cをA,B,Cにするコスト
    }

    //今ある竹を採用しない場合
    int res=rec(i+1,a,b,c);

    //A,B,Cに使う場合
    //(a?10:0)　は三項演算子
    //a==0のときのみFalseなので0,それ以外は10になる
    //これは最初の一本目だけは合体ではないのでコストが0であることを意味する
    chmin(res,rec(i+1,a+L[i],b,c)+(a?10:0));
    chmin(res,rec(i+1,a,b+L[i],c)+(b?10:0));
    chmin(res,rec(i+1,a,b,c+L[i])+(c?10:0));

    //再帰の途中経過を返す
    return res;
}

int main()
{
    cin >> N >> A >> B >> C;
    L.resize(N);
    for(int i=0;i<N;++i)cin>>L[i];

    cout << rec(0,0,0,0) << endl;
}




