/*
2-6 p73
実直にシミュレーションするとN数から難しい
まずできるだけ進み、その後、通過していたガソリンスタンドから最も多いガソリンを補給する
あとから補償するという考え方をする
 */

#include<iostream>
#include<queue>

using namespace std;

const int MAX_N=10000;

int N,L,P;
int A[MAX_N],B[MAX_N];


void solve()
{
    //簡単のためゴールをガソリンスタンドに追加
    A[N]=L;
    B[N]=0;
    N++;

    priority_queue<int> que;

    //ans:補給回数,pos:今いる場所,tank:タンクのガソリンの量
    int ans=0,pos=0,tank=P;

    for(int i=0; i<N;++i)
    {
        //次にすすむ距離
        int d=A[i]-pos;

        //十分な量になるまでガソリンを補給
        while(tank-d<0)
        {
            //queが空なら走破不可
            if(que.empty())
            {
                puts("-1");
                return;
            }

            tank+=que.top();
            que.pop();
            ans++;
        }

        //走行処理
        //燃料の消費・位置の更新・queへの燃料追加
        tank-=d;
        pos=A[i];
        que.push(B[i]);
    }
    printf("%d\n",ans);

}


int main()
{
    cin>>N>>L>>P;
    for(int i=0; i!=N ; ++i)
    {
        cin>>A[i]>>B[i];
    }

    solve();
}