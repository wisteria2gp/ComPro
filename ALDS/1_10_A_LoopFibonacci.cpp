
//DP-1

#include<iostream>
#include<stdio.h>


using namespace std;


int main()
{
    int i,n;
    //メモ化のための配列
    int dp[50];
    scanf("%d",&n);
    dp[0]=1;
    dp[1]=1;

    for(i=2;i<=n;i++)
    {
        dp[i]=dp[i-1]+dp[i-2];
    }
    printf("%d\n",dp[n]);

}