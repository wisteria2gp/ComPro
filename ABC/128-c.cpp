
// bit探索
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



int main()
{
    int n,m;
    cin>>n>>m;
    vec<int> s(m,0);
    vec<int> p(m,0);

    int k,digit;
    rep(i,m){
        cin>>k;
        rep(j,k){
            cin>>digit;
            digit--;
            s[i]|=(1<<digit);
        }
    }
    rep(i,m){
        cin>>p[i];
    }

    bool rem=false;
    int ans=0;
    for(int bit=0;bit<(1<<n);++bit){
        rep(i,m){
            // intからbit flagを数える__builtin_popcount
            rem=(((__builtin_popcount(bit&s[i])) %2)==p[i]);
            if(!rem) break;
        }
        ans+=rem;
    }

    cout<<ans<<endl;
    return 0;

}


