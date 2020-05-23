// AOJ GRL_1_A 

#include<bits/stdc++.h>
#include <algorithm>
#include <vector>


#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template <class T>
// using vec = std::vector<T>;
// typedef long long ll;
// template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
// template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// const long long INF = 1LL<<60;
const int INF = 1<<30;
int lcm(int a,int b){
    //最小公倍数
    return a/__gcd(a,b) * b;
}

struct edge{int from, to,cost;};

int MAX_E=500000;
int MAX_V=100000;
// int型の2次元配列(3×4要素の)の宣言
// vector<vector<int>> data(3, vector<int>(4));

vector<edge> es(MAX_E); //辺
vector<int> d(MAX_V); // 最短距離
int V,E; //Vは頂点数,Eは辺数


void shortest_path(int s){
    for(int i=0;i<V;i++) d[i]=INF;
    d[s]=0;
    while(true){
        bool update=false;
        for(int i=0;i<E;i++){
            edge e=es[i];
            if(d[e.from]!=INF && d[e.to] > d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;
                update=true;
            }
        }
        if(!update)break;
    }
}

int main()
{
    int s;
    cin>>V>>E>>s;
    rep(i,E){
        cin>>es[i].from>>es[i].to>>es[i].cost;
    }
    shortest_path(s);

    rep(i,V){
        if(d[i]==INF){
            cout<<"INF"<<endl;
        }else{
            cout<<d[i]<<endl;
        }
    }
    

    return 0;

}


