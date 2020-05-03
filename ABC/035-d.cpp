

#include<bits/stdc++.h>



#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template <class T>
using vec = std::vector<T>;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const int INF = 1e+9;

int lcm(int a,int b){
    //最小公倍数
    return a/__gcd(a,b) * b;
}

const int MAX_V=100000;

struct edge{
    int to;
    int cost;
};

// <最小コスト, 頂点の番号>
typedef pair<int,int> P;

vec<edge> G[MAX_V];
vec<int> dist(MAX_V,INF); //dist[i]が0->iの時間コスト


int V,E,T;

vec<int> dijkstra(int s){
    priority_queue<P,vector<P>,greater<P>> que;
    dist[s]=0;
    que.push(P(0,s));

    while(!que.empty()){
        P p=que.top();
        que.pop();
        int v=p.second;
        if(dist[v]<p.first)continue;

        rep(i,int(G[v].size())){
            edge e=G[v][i];
            if(dist[e.to]>dist[v]+e.cost){
                dist[e.to]=dist[v]+e.cost;
                que.push(P(dist[e.to],e.to));
            }
        }
    }

    return dist;
}


int main()
{
    cin>>V>>E>>T;
    vector<int> A(V);
    rep(i,V) cin>>A[i];


    vec<int> a(E),b(E),c(E);


    rep(i,E){
        cin>>a[i]>>b[i]>>c[i];
        a[i]--,b[i]--;
        edge e={b[i],c[i]}; // {to,cost}
        G[a[i]].push_back(e); //from a[i] to b[i] cost:c[i]
    }
    // 行きのdijkstra
    auto dist1=dijkstra(0);
    
    rep(i,MAX_V){
        G[i].clear();
    }

    // 帰りのdijkstra 
    // 帰りであってもエッジの向きを逆にすれば行きと同じ形式で求まる
    rep(i,E){
        edge e={a[i],c[i]};
        G[b[i]].push_back(e);
    }
    auto dist2=dijkstra(0);

    ll ans=0;
    rep(i,V){
        if(dist1[i]+dist2[i] <= T){
            ll d=(T-dist1[i]-dist2[i])*A[i];
            chmax(ans,d);
        }
    }

    cout<<ans<<endl;

    return 0;

}


