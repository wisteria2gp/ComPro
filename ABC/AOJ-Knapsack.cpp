//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_B&lang=jp
//https://www.slideshare.net/iwiwi/ss-3578511


#include <iostream>
#include <vector>
#include <algorithm>

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

const int MAX_N=100;
const int MAX_W=10000;
bool done[MAX_N+10][MAX_W+10];
int memo[MAX_N+10][MAX_W+10];
int N,W;
int v[MAX_N];
int w[MAX_N]; 

int search(int i,int u)
{
    if (done[i][u]) return memo[i][u];
    int res;
    if(i==N) res=0;
    else if(u<w[i])
    {
        res=search(i+1,u);
    }
    else{
        int res1=search(i+1,u);
        int res2=search(i+1,u-w[i])+v[i];
        res=max(res1,res2);
    }
    done[i][u]=true;
    memo[i][u]=res;
    return res;
}

int main()
{

    cin>>N>>W;
    for (int i=0;i<N;i++)
    {
        cin>>v[i]>>w[i];
    }
    int res=search(0,W);
    cout<<res<<endl;
    return 0;
}