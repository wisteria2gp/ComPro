
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

int lcm(int a,int b){
    //最小公倍数
    return a/__gcd(a,b) * b;
}

ll solve(ll x){
    ll a,b;
    a=x/500;
    x-=a*500;
    b=x/5;
    return a*1000+5*b;
}

int main()
{
    ll x;
    cin>>x;
    cout<<solve(x)<<endl;


    return 0;

}


