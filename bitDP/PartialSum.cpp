
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int main()
{
    int n;
    vector<int> a(20);
    int K;

    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    cin>>K;

    bool exist=false;
    for(int bit=0;bit<(1<<n);++bit)
    {
        int sum=0;
        for(int i=0;i<n;++i)
        {
            if(bit &(1<<i))
            {
                sum+=a[i];
            }
        }

        if(sum==K) 
        {
            exist=true;
        }
    }

    if(exist) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
    return 0;

}