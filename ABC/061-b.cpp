//集計処理・バケット法

#define MAX 50
#include<iostream>

using namespace std;

int main()
{
    int N,M;
    int  city[MAX];

    cin>>N>>M;
    for(int i=0;i<N;++i)
    {
        city[i]=0;
    }

    int a,b;
    for(int i=0;i<M;i++)
    {
        scanf("%d %d",&a,&b);
        city[a-1]++;
        city[b-1]++;
    }

    for(int i=0;i<N;i++)
    {
        printf("%d \n",city[i]);
    }
    return 0;

}