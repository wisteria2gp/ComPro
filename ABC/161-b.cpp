

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

double n,m;


int main()
{
    cin>>n>>m;
    double all=0;
    vec<double> a(n,0);
    rep(i,n){
        cin>>a[i];
        all+=a[i];
    }
    double line=all/(4*m);

    double count=0;
    rep(i,n){
        if(a[i]>=line){
            count++;
        }
    }

    if(count>=m){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

    // cout<<line<<endl;

    return 0;

}


