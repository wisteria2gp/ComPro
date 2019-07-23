
#include<iostream>
#include<vector>
#include<algorithm>
using ll=long long;
using namespace std;

int main()
{
    int n;
    cin>>n;
    vector<int> a(3*100000);

    for(int i=0;i<3*n;++i)
    {
        scanf("%d",&a[i]);
    }
    sort(a.begin(),a.end(),greater<int>());

    ll ans=0LL;
    for(int i=1;i<2*n;i+=2)
    {
        ans+=a[i];
    }

    cout<<ans<<"\n";


}