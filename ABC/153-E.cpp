

#include<bits/stdc++.h>

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
const long long INF = 1LL<<60;


const int MAX_H=10000;
const int MAX_N=1000;

int H,N;
int a[MAX_N+10];
int b[MAX_N+10]; 



int main()
{

    cin>>H>>N;
    for (int i=0;i<N;i++)
    {
        cin>>a[i]>>b[i];
    }

    vector<vector<long long>> memo(N+1,vector<long long>(H+1,INF));
    memo[0][0]=0;

    //DPループ
    for(int i=0;i<N;++i){
        for(int j=0;j<=H;++j){
            chmin(memo[i+1][j],memo[i][j]);
            chmin(memo[i+1][min(j+a[i],H)],memo[i+1][j]+b[i]);
        }
    }


    cout<< memo[N][H]<<endl;
    return 0;
}


