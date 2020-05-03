

#include<bits/stdc++.h>



#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template <class T>
using vec = std::vector<T>;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

// const long long INF = 1LL<<60;
#define INF 1e+9
#define MAX_V 10

int lcm(int a,int b){
    //最小公倍数
    return a/__gcd(a,b) * b;
}

struct edge{
    int to;
    int cost;
};
// <最短距離, 頂点の番号>
using P = pair<int, int>;
int V;
vector<edge> G[MAX_V];
int d[MAX_V];

void dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d+V, INF);
    d[s] = 0;
    que.push(P(0, s));

    while (!que.empty()) {
        P p = que.top();
        que.pop();
        int v = p.second;
        if (d[v] < p.first) continue;

        for (int i=0; i<G[v].size(); ++i) {
            edge e = G[v][i];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main()
{
    int n,x,y;
    cin>>n>>x>>y;
    x--;
    y--;

    rep(i,n){
        edge e={i+1};
        G[i].push_back(e);
    }

    dijkstra(0);
    for (int i=0; i<V; ++i) {
        if(d[i] != INF)
            cout << "0から" << i << "までのコスト: " << d[i] << endl;
    }
    return 0;

}


