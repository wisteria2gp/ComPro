#define MAX 101010
#include<iostream>
using namespace std;


int main()
{
    int N;
    int t[MAX],x[MAX],y[MAX];
    int dt,dist;

    scanf("%d",&N);
    t[0]=x[0]=y[0];
    for(int i=0;i<N;i++)
    {
        scanf("%d %d %d",&t[i+1],&x[i+1],&y[i+1]);
    }

    bool can=true;
    for(int i=0;i<N;i++)
    {
        dt=t[i+1]-t[i];
        dist=abs(x[i+1]-x[i])+abs(y[i+1]-y[i]);
        if(dt<dist)can=false;
        if(dist%2 != dt%2) can=false;
    }

    if(can) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}