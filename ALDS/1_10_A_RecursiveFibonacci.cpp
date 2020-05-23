
//DP-1

#include<iostream>
#include<stdio.h>


using namespace std;

//メモ化のための配列
int dp[50];

int solve(int n)
{
    if (n==0||n==1) return dp[n]=1;
    if(dp[n]!=-1) return dp[n];
    return dp[n]=solve(n-1)+solve(n-2);
    //最後のreturnでもdp[n]=とメモ化することを忘れない.メモ化の効果がなくなる
}

int main()
{
    int i,n;
    for(i=0;i<50;i++) dp[i]=-1;

    scanf("%d",&n);
    printf("%d\n",solve(n));

    return 0;
}