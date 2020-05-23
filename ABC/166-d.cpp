

#include<bits/stdc++.h>
#include<cmath>


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

// nに５乗で最も近くなるmを返す
ll pow_search(ll n){
    ll m=0;
    while (!(pow(m,5) <= n && n < pow(m+1,5))){
        m++;
    }
    return m;
}

int main()
{
    ll x;
    cin>>x;
    ll match=0;
    for(ll a=-300;a<=300;a++){
        for(ll b=-300;b<=300;b++){
            match=pow(a,5)-pow(b,5);
            if(match==x){
                cout<<a<<" "<<b<<endl;
                return 0;
            }
        }
    }

    return 0;

}


