

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

int a,b,k;

int main()
{
    cin>>k>>a>>b;
    if(a%k==0){
        cout<<"OK"<<endl;
        return 0;
    }
    int c=a/k*k+k;
    
    

    if(c<=b){
        cout<<"OK"<<endl;
    }else{
        cout<<"NG"<<endl;
    }

    return 0;

}


