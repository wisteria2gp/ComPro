#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

static const int N=1000;

int lcs(string x,string y) //文字列 X,Y
{
    int c[N+1][N+1];
    int m=x.size();
    int n=y.size();
    int maxl=0;

    x=' '+x;
    y=' '+y;

    for(int i=1;i<=m ;i++) c[i][0]=0;
    for(int j=1;j<=n;j++) c[0][j]=0;

    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(x[i]==y[j])
            {
                c[i][j]=c[i-1][j-1]+1;
            }
            // x_i !=
            else if( c[i-1][j]>=c[i][j-1] )
            {
                c[i][j]=c[i-1][j];
            }
            else
            {
                c[i][j]=c[i][j-1];
            }
            
        }
    }
}


int main()
{
    int q,i;
    string s1,s2;
    int c[1100][1100];
    
    scanf("%d",&q);
    for(i=0;i<q;i++)
    {
        scanf("%s",s1);
        scanf("%s",s2);
        printf("%d\n",&lcs(s1,s2))
    }



}