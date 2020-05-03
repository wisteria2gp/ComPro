
//https://atcoder.jp/contests/atc001/tasks/dfs_a
//幅優先探索


#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

const int MAX_H=510;
const int MAX_W=510;
int W,H;
int res=false;

vector<vector<char>> graph(MAX_H,vector<char>(MAX_W));
vector<vector<bool>> reached(MAX_H,vector<bool>(MAX_W));



void search(int x,int y)
{
    //壁・迷路外の判定
    if(x<0||W<=x||y<0||H<=y||graph.at(y).at(x)=='#')return;
    //到達判定
    if(reached.at(y).at(x)) return;    

    //到達を記録
    reached.at(y).at(x)=true;

    //Goal判定
    if(graph.at(y).at(x)=='g')res=true;

    //４方向を探索
    search(x+1,y);//右
    search(x-1,y);//左
    search(x,y+1);//下
    search(x,y-1);//上

}



int main()
{
    int sy,sx;
    cin>>H>>W;

    char tmp;
    rep(i,H)
    {
        rep(j,W)
        {
            cin>>tmp;
            if(tmp=='s')
            {
                sy=i;
                sx=j;
            }
            graph.at(i).at(j)=tmp;

        }
    }

    search(sx,sy);

    if(res) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";
}