

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;cin>>n;
    vector<int> A(n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    int res=0;
    for(int i=0;i<n;++i)
    {
        //sameを抜ける
        while(i+1<n && A[i]==A[i+1])++i;

        //単調非減少
        if(i+1<n && A[i]<A[i+1])
        {
            while(i+1<n && A[i]<=A[i+1])++i;
        }
        //単調非増加
        else if(i+1<n && A[i]>A[i+1])
        {
            while(i+1<n && A[i]>=A[i+1]) ++i;
        }
        ++res;
    }

    cout<<res<<"\n";

}