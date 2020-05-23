

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

int n,m,x;
vec<int> c(12,0);
vec<vec<int>> a(12,vec<int>(12,0));


int main()
{
    cin>>n>>m>>x;

    rep(i,n){
        cin>>c[i];
        rep(j,m){
            cin>>a[i][j];
        }
    }

    vec<int> learn(m,0);
    int Min=10000000;
    int cost=0;

    for(int bit=0;bit<(1<<n);++bit){ // bit全探索による部分組み合わせ全列挙 2^n パターン
        
        cost=0;
        rep(i,m) learn[i]=0;

        rep(i,n){
            if(bit & (1<<i)){// i番目が1(存在)する場合
                rep(j,m){
                    learn[j]+=a[i][j];
                    
                }
               cost+=c[i];
            }
        }


        bool flag=true;
        rep(i,m){
            //cout<<learn[i]<<endl;
            if(learn[i]<x) flag=false;
        }
         //cout<<endl;
        if(flag){
            Min=min(cost,Min);
        }
    }

    if(Min==10000000) Min=-1;


    cout<<Min<<endl;


    

    return 0;

}




