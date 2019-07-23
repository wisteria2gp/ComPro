

#include<iostream>
#include<vector>
#include<algorithm>
using ll=long long;
using namespace std;


int main()
{
    int n,x;
    cin>>n>>x;
    vector<int> A(n);

    for(int i=0; i<n;++i)
    {
        scanf("%d",&A[i]);
    }
    sort(A.begin(),A.end());

    int count=0;
    if(x<A[0]) ;
    else
    {
    
        for(;count<n;)
        {
            x-=A[count];
            count++;
            if(count==n)
            {
                if(x==0)count=n;
                else count=n-1;
                break;
            }
            if(x<A[count]) break;
        }

    }

    cout<<count<<"\n";
    
    return 0;

}