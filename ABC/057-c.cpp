

#include <iostream>
#include <vector>
#include <algorithm>
#include<cmath>
#define MAX 100
using ll=long long;
using namespace std;

int cnt_digits(ll N)
{
    int digits=0;
    while(N>0)
    {
        N/=10;
        digits++;
    }
    return digits;
}

int main(void)
{
    ll n;
    cin>>n;

    int ans=cnt_digits(n);

    //1LL はlong longの1であることを明示した書き方
    //1LL<<40 のようなbitずらしなどのときに使うといい？
    for(ll a=1LL ; a*a<=n ; ++a)
    {
        if(n%a!=0)continue;
        const ll b=n/a;
        const int cur=max(cnt_digits(a),cnt_digits(b));

        ans=min(ans,cur);

    }

    cout<<ans<<"\n";
    return 0;
}