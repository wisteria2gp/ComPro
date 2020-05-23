

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

struct edge{int from, to,cost;};

// int型の2次元配列(3×4要素の)の宣言
// vector<vector<int>> data(3, vector<int>(4));


int main()
{
    int n;cin>>n;
    int res=n%10;
    if(res==2 ||res==4||res==5||res==7||res==9){
        cout<<"hon"<<endl;
    }else if (res==3)
    {
        cout<<"bon"<<endl;
    }else{
        cout<<"pon"<<endl;
    }
    

    return 0;

}


