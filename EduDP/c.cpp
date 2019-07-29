/* 
Vacation
巡回セールスマン同様に次の選択uを考えるのに
それまでの部分集合Sの最後vがなにであるかの仮定が必要なタイプ
今回はvによってはv-uの経路が存在しない形式
*/
#include <cstring>
#include<iostream>
#include<vector>
using namespace std;

template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF=1LL<<60;

int n;
int happy[100100][3];
long long dp[100010][3];

int main()
{

    cin >> n;
    for(int i=0;i<n;++i)
    {
        cin>>happy[i][0]>>happy[i][1]>>happy[i][2];
    }

    for(int i=0;i<n;++i)
    {   
        //dp[i][j]に用いるj
        for(int j=0;j<3;++j)
        {
            //dp[i][j]+a[i][k](or b or c)に用いるk
            for(int k=0;k<3;++k)
            {
                //i+1にk(=0ならa,１ならb,2ならc)を行ったときの幸福度更新
                if(j!=k) chmax(dp[i+1][k],dp[i][j]+happy[i][k]);
            }
        }
    }

    long long res=0;
    for(int i=0;i<3;++i) chmax(res,dp[n][i]);
    cout<<res<<"\n";
}