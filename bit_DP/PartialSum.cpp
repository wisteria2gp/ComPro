//部分和問題のbitDP
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

    vector<int> S;
    for(int bit=0;bit<(1<<n);++bit)
    {
        for(int i=0;i<n;++i)
        {
            if(bit &(1<<i))
            {
                S.push_back(a[i]);
            }
        }

        int sum=accumulate(S.begin(),S.end(),0);
        if(sum==K) 
        {
            cout<<"Yes"<<"\n";
            return 0;
        }
    }

    cout<<"No"<<"\n";
    return 0;

}