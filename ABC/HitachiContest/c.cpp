#include <vector>
#include <cstdio>

using namespace std;

vector<pair<int, int> > G[40000];

class LCA {
public:
    int V, logV;
    vector<int> depth, len;
    vector<vector<int> > parent;
    
    LCA(int V) {
        this->V = V;
        logV = 0;
        while (V > (1LL<<logV)) logV++;
        this->depth = vector<int>(V);
        this->len = vector<int>(V);
        this->parent = vector<vector<int> >(logV, vector<int>(V));
    }
    
    void init(int v, int par, int d, int l) {
        depth[v] = d;
        parent[0][v] = par;
        len[v] = l;
        for (int i = 0; i < (int)G[v].size(); i++) {
            int w = G[v][i].first;
            int lc = G[v][i].second;
            if (w == par) continue;
            init(w, v, d+1, lc + l);
        }
    }
    
    void build() {
        for (int k = 0; k + 1 < logV; k++) {
            for (int v = 0; v < V; v++) {
                if (parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }
    
    int query(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int k = 0; k < logV; k++) {
            if ((depth[v] - depth[u]) >> k & 1)
                v = parent[k][v];
        }
        if (u == v) return u;
        
        for (int k = logV-1; k >= 0; k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }
};

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N-1; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        --x, --y;
        G[x].push_back(make_pair(y, 1));
        G[y].push_back(make_pair(x, 1));
    }

    LCA lca(N);
    lca.init(0, -1, 0, 0);
    lca.build();

    for(int i=0;i<N;i++)
    {
        for(int j=i+1;j<N;j++)
        {
            int x=i, y=j;
            int z = lca.query(x, y);
            int ret = lca.len[x] + lca.len[y] - 2 * lca.len[z];
            if(ret==3){
                printf("%d %d\n",x+1,y+1);
            }
        }
    }
    return 0;
}