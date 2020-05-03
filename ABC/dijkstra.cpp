#include <iostream>
#include <queue>
#include <vector>


#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template <class T>
using vec = std::vector<T>;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int INF=1e+9;


const int MAX_V=100000;

struct edge{
    int to;
    int cost;
};

// <最短距離, 頂点の番号>
typedef pair<int,int> P;


vector<edge> G[MAX_V];
int d[MAX_V];

int V;

void dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>> que;
    fill(d,d+V,INF);
    d[s]=0; // 開始点はコスト0
    que.push(P(0,s)); //queに開始点を追加

    while(!que.empty()){
        P p=que.top(); // 降順queの先頭を取得
        que.pop();//queの先頭を廃棄
        int v=p.second; //次の開始ノード
        //次に調べる頂点へのコストが(p.first ,p.second==v)
        //現状わかっている最小コスト(d[v])より大きければ無視
        if(d[v]<p.first)continue;
        

        rep(i,int(G[v].size())){
            edge e=G[v][i];
            if(d[e.to]>d[v]+e.cost){
                d[e.to]=d[v]+e.cost;
                que.push(P(d[e.to],e.to));
            }
        }


    }
}


int main()
{
    int E,r;
    cin>>V>>E>>r;
    rep(i,E){
        int s,t,d;
        // from s to t ,cost = d
        cin>>s>>t>>d;
        edge e={t,d};

        G[s].push_back(e);
    }

    dijkstra(r);
    rep(i,V){
            cout<<d[i]<<endl;
    }


    return 0;

}


