/* primのアルゴリズム */
#include<iostream>
#include<stdio.h>
using namespace std;


static const int N_MAX=100;
static const int INFTY=(1<<21);
static const int WHITE=0;
static const int GRAY=1;
static const int BLACK=2;

int color[N_MAX];
int M[N_MAX][N_MAX];
int d[N_MAX];
int p[N_MAX];
int n;


int prim()
{
    int i,minv,u,v;
    for(i=0;i<n;i++)
    {
        color[i]=WHITE;
        d[i]=INFTY;
        p[i]=-1;
    }
    d[0]=0;

    while(true)
    {
        minv=INFTY;
        //T(最小全域木)に追加するノードuの探索
        for(i=0;i<n;i++)
        {
            //未選択でT-Vの接続がもっとも小さいノードの選択
            if(color[i]!=BLACK && d[i]<minv)
            {
                minv=d[i];
                u=i;
            }
        }

        //もし最小接続コストがINFTYなら探索終了
        if(minv==INFTY) break;

        //Tに追加されたuは選択済みのフラグを立てる
        color[u]=BLACK;

        //元グラフVからu-vで最小のコストのエッジをd[v]に保存
        //親も保存
        //探査はした証拠にGRAYにする
        //ここでの代入操作は次のループで上のfor文内で使われる
        for(v=0;v<n;v++)
        {
            //未選択でuとのエッジが存在するvについて
            if(color[v]!=BLACK && M[u][v]!=INFTY)
            {
                //そのエッジコストがvが記録する
                //T - (V-T)間の最小コストより小さければ
                //エッジコスト更新
                //vの親の更新
                if(M[u][v]<d[v])
                {
                    d[v]=M[u][v];
                    p[v]=u;
                    color[v]=GRAY;
                }
            }
        }

    }

    int sum=0;
    for(i=0;i<n;i++)
    {
        //親が存在すれば、i-p[i]間コストを加算
        if(p[i]!=-1) sum+=M[i][p[i]];
    }
    return sum;
}


int main()
{
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            int e;
            scanf("%d",&e);
            M[i][j]=(e==-1) ? INFTY : e ;
        }
    }

    printf("%d",prim());
    printf("\n");

    return 0;
}



