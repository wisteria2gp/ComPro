// AOJ GRL_1_A 

#include<bits/stdc++.h>
#include <algorithm>
#include <vector>


#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template <class T>
using vec = std::vector<T>;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL<<60;
const int int_INF = 100100100;
int lcm(int a,int b){
    //最小公倍数
    return a/__gcd(a,b) * b;
}


struct edge{int from, to,cost;};

int MAX_N=1000; //edge
int MAX_M=2000; // node
// int型の2次元配列(3×4要素の)の宣言
// vector<vector<int>> data(3, vector<int>(4));

vec<edge> es(MAX_M); //辺
vec<ll> d(MAX_N,INF); // 各点への最短距離
int V,E; //Vは頂点数,Eは辺数
vec<bool> negative(MAX_N,false);

int N,M,s;

void shortest_path(int s){
    for(int i=0;i<N;i++) d[i]=INF;
    d[s]=0;
    for(int loop=0;loop<N-1;++loop){ //任意の頂点にたどり着くのに、
        for(int i=0;i<M;++i){
            edge e=es[i];
            if(d[e.from]!=INF && d[e.to] > d[e.from]+e.cost){
                // cout<<d[e.from]<<" > "<<d[e.from]<<"+"<<e.cost<<endl;
                d[e.to]=d[e.from]+e.cost;
            }
        }
        
    }
}

void find_negative_loop(int s){
    for(int i=0;i<N;i++) negative[i]=false;
    d[s]=0;
    for(int loop=0;loop<N;++loop){
        for(int i=0;i<M;++i){
            edge e=es[i];
            
            if(d[e.from]!=INF && d[e.to] > d[e.from]+e.cost){
                
                d[e.to]=d[e.from]+e.cost;
                negative[e.to]=true;
            }
            if(negative[e.from]==true){
                negative[e.to]=true;
            }
        }
        
    }
}


int main()
{
    
    cin>>N>>M;
    rep(i,M){
        cin>>es[i].from>>es[i].to>>es[i].cost;
        es[i].from--; //頂点番号を0-indexに
        es[i].to--;
        es[i].cost*=-1;
    }
    shortest_path(s);
    ll ans=d[N-1];
    find_negative_loop(s);




    if(negative[N-1]){
        cout<<"inf"<<endl;
    }else{
        cout<<-ans<<endl;
    }
    

    return 0;

}


