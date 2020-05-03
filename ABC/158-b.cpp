

#include<bits/stdc++.h>

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template <class T>
using vec = std::vector<T>;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL<<60;


const int MAX_H=10000;
const int MAX_N=1000;

ll a,b;
ll n;

vec<ll> v;

int main()
{

    cin>>n>>a>>b;
    ll time=n/(a+b);
    ll rem=n%(a+b);
    ll rem_blue=min(rem,a);

    ll ans=time*a + rem_blue;

    cout<<ans<<endl;

    return 0;
}


