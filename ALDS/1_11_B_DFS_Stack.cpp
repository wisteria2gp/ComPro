/* DeapthFirstSearch　With　Stack*/

#include<iostream>
#include<stdio.h>
#include<stack>
#define N_MAX 100
#define WHITE 0
#define GRAY 1
#define BLACK 2
using namespace std;

int n;//頂点数
int M[N_MAX][N_MAX];//隣接行列
int color[N_MAX];//各頂点の探索状態
int d[N_MAX];//頂点の発見時刻
int f[N_MAX];//頂点の完了時刻
int tt;//時刻
int nt[N_MAX];//nextで隣接頂点を探すためのダミー変数みたいな雰囲気

//uに隣接するvを番号順に取得
int next(int u)
{
    for(int v=nt[u];v<n;v++)
    {
        nt[u]=v+1;
        /* 
        v++かつnt[u]=v+1で、for文内でuが不変なので
        たとえばu=0から始めると
        nt[u]=0->1->2->3...
        とnまで順に見ていくことになる
        */
        if(M[u][v]) return v;
        /* 
        エッジu-vが存在すれば、vを隣接頂点として返す
        このときnt[u]=v+1である
        ということは、もし次にnext(u)となったときはv+1から探査してくれる。なるほど
        */
    }
    return -1;
}

//スタックを用いた深さ優先探索
void dfs_visit(int r)
{
    //探索経過の初期化
    for (int i = 0; i <n; i++)nt[i]=0;

    stack<int> S;
    
    S.push(r);
    color[r]=GRAY;
    d[r]=++tt;

    while(! S.empty())
    {
        int u=S.top();
        int v=next(u);

        if(v!=-1)
        {
            if(color[v]==WHITE)
            {
                color[v]=GRAY;
                d[v]=++ tt;
                S.push(v);
            }
        }
        else
        {
            S.pop();
            color[u]=BLACK;
            f[u]=++tt;
        }
    }
}

void dfs()
{
    //初期化
    for(int i=0;i<n;i++)
    {
        color[i]=WHITE;
        nt[i]=0;
    }
    tt=0;
    
    //未訪問のuを始点として深さ優先探索
    for(int u=0;u<n;u++)
    {
        if(color[u]==WHITE)dfs_visit(u);
    }
    for(int i=0;i<n;i++)
    {
        cout<<i+1<<" "<<d[i]<<" "<<f[i]<<endl;
    }

}



int main()
{
    int u,k,v;

    cin>>n;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)M[i][j]=0;
    }

    for(int i=0;i<n;i++)
    {
        cin >> u >> k;
        u--;
        for(int j=0;j<k;j++)
        {
            cin>>v;
            v--;
            M[u][v]=1;
        }
    }

    dfs();

    return 0;
}