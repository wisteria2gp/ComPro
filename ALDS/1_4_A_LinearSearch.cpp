//LinearSearch

#include<iostream>
#include<stdio.h>


using namespace std;

#define MAX_N 10100
#define MAX_Q 510


bool Search(int A[],int n,int key)
{
    /*
        A[] : 探索する配列
        n : Aの要素数
        key : 探索対象の値
    */
   A[n]=key;
   int i=0;

   while(A[i]!=key)
   {
       i++;
   }
   return i!=n;

}


int main(){
    int i,n,q,key,sum=0;
    int S[MAX_N];

    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&S[i]);
    }

    scanf("%d",&q);
    for(i=0;i<q;i++){
        scanf("%d",&key);
        if(Search(S,n,key)) sum++;
    }

    printf("%d\n",sum);

    return 0;

}
