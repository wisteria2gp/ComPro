

#include<bits/stdc++.h>
#include <cmath>


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

ll a,b,c;

int main()
{
    cin>>a>>b>>c;

    // sqrt(a)+sqrt(b)<sqrt(c)を
    // c-a-b>0 and (c-a-b)^2>4ab に分解する

    ll one,two;
    one=c-a-b;
    two=one*one-4*a*b;

    if(one>0 and two>0){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    return 0;

}



