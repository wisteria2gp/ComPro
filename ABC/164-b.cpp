

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


int a,b,c,d;


int main()
{
    cin>>a>>b>>c>>d;

    while(true){
        c-=b;
        if(c<=0){
            cout<<"Yes"<<endl;
            return 0;
        }
        a-=d;
        if(a<=0){
            cout<<"No"<<endl;
            return 0;
        }
    }

    return 0;

}


