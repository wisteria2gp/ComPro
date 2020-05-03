

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



ll x,k;

int main()
{
    cin>>x>>k;

    ll div=x/k;
    

    ll a,b;
    a=abs(k*div-x);
    b=abs(k*div+k-x);

    if(a<b){
        cout<<a<<endl;
    }else{
        cout<<b<<endl;
    }

    return 0;

}


