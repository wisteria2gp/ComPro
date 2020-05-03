

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


ll h,w;

int main()
{
    cin>>h>>w;
    ll ans=0;
    if(h<2 or w<2){
        ans=1;
    }
    else if(h%2==1 and w%2==1){
        ans=(h/2+1)*w-(w/2);
    }else if(h%2==1 or w%2==1){
        if(w%2==1)swap(h,w);
        ans=(h/2+1)*w-(w/2);
    }else{
        ans=(h/2)*w;
    }

    cout<<ans<<endl;

    return 0;

}


