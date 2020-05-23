

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

int lcm(int a,int b){
    //最小公倍数
    return a/__gcd(a,b) * b;
}

struct edge{int from, to,cost;};

// int型の2次元配列(3×4要素の)の宣言
// vector<vector<int>> data(3, vector<int>(4));

const int INF=100000000;
const int MAX_R=50;
const int MAX_C=50;


// 座標情報：<y,x> を示すpair 
typedef pair<int,int> P;

int R,C;
int sy,sx;
int gy,gx;

// 列・行の順なのでy・xであることに注意
vec<vec<char>> maze(MAX_R+5,vec<char> (MAX_C+5,'#'));
vec<vec<int>> d(MAX_R+5,vec<int> (MAX_C+5,INF));

// 上右下左
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};

int bfs(){
    queue<P> que;

    que.push(P(sy,sx));
    d[sy][sx]=0;

    // queがからになるまでループ
    while(que.size()){
        // que先頭取り出し、削除
        P p=que.front(); que.pop();
        // 取り出してきた状態がゴールなら探索終了
        if(p.first==gy && p.second==gx) break;
        rep(i,4){
            
            int ny=p.first+dy[i];
            int nx=p.second+dx[i];

            //移動可能判定 移動できなければskip
            if( nx<0 || nx>=C || ny<0 || ny>=R ) continue;

            // 既に訪問済みかの判定(d[nx][ny]!=INFなら訪問済み)
            if( maze[ny][nx]!='#' && d[ny][nx]==INF){
                //移動可能な場合queに入れ、その点の距離をpからの距離+1で確定する
                que.push(P(ny,nx));
                d[ny][nx]=d[p.first][p.second]+1;

            }
        }

    }
    return d[gy][gx];
}

int main()
{
    cin>>R>>C>>sy>>sx>>gy>>gx;
    sx--;sy--;gx--;gy--;

    rep(i,R){
        rep(j,C){
            cin>>maze[i][j];
        }
    }

    cout<<bfs()<<endl;
    return 0;

}


