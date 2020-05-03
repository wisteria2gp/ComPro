

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

int k;

int main()
{
    cin>>k;
    ll sum=0;
    int tmp;
    loop(a,1,k+1)loop(b,1,k+1)loop(c,1,k+1){
        tmp=__gcd(a,b);
        sum+=__gcd(tmp,c);
    }
    cout<<sum<<endl;

    return 0;

}


