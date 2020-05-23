

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

struct edge
{
    int from, to,cost;
    edge() :from(-1),to(-1),cost(1){}
};

// int型の2次元配列(3×4要素の)の宣言
// vector<vector<int>> data(3, vector<int>(4));

// vec<vec<bool>>  G (100100,vec<bool> (100100,false));
using Graph = vector<vector<int>>; // グラフ型


int main()
{
    int n,m;cin>>n>>m;
    Graph G(n); // グラフ

    int a,b;
    rep(i,m){
        cin>>a>>b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vec<int> dist(100100,-1);
    vec<int> prev (100100,-1);
    dist[0]=0;

    queue<int> Q;

    int now=0;
    Q.push(now);
    while(!Q.empty()){
        now=Q.front();
        Q.pop();
        for(auto& e:G[now]){
            int node=int(e);
            if(dist[node]==-1){
                Q.push(node);
                dist[node]=dist[now]+1;
                prev[node]=now;
            }
        }
    }

    cout<<"Yes"<<endl;
    loop(i,1,n){
        cout<<prev[i]+1<<endl;
    }

    return 0;

}


