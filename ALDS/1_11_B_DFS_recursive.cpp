#include<iostream>
#include<stdio.h>

#define N 100
#define WHITE 0
#define GRAY 1
#define BLACK 2

int n;
int M[N][N];
int color[N];
int d[N];
int f[N];
int tt;

//再帰関数によるDFS
void dfs_visit(int u)
{
    int v;
    color[u]=GRAY;
    d[u]=++tt;//最初の訪問

    for(v=0;v<n;v++)
    {
        if(M[u][v]==0) continue;
        if(color[v]==WHITE)
        {
            dfs_visit(v);
        }
    }

    //探索終了の記録
    //再帰初期のuほど遅く探索が終了する
    color[u]=BLACK;
    f[u]=++tt;
}

void dfs()
{
    int u;
    //初期化
    for(u=0;u<n;u++) color[u]=WHITE;
    tt=0;

    for(u=0;u<n;u++)
    {
        //未訪問のuを始点としてとしてDFS
        if(color[u]==WHITE) dfs_visit(u);
    }
    for(u=0;u<n;u++)
    {
        printf("%d %d %d\n",u+1,d[u],f[u]);
    }
}


int main()
{
    int u,v,k,i,j;

    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)M[i][j]==0;
    }

    for(i=0;i<n;i++)
    {
        scanf("%d %d",&u,&k);
        u--;
        for(j=0;j<k;j++)
        {
            scanf("%d",&v);
            v--;
            M[u][v]=1;
        }
    }

    dfs();
    return 0;
}