

//順番が問題でないときはまずソートしてみる


#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

const int MAX_N=100100;
const int MAX_M=100100;

int n,m;
int a,b;

int main()
{
    int res=0;
    cin>>n>>m;

    vector<pair<int, int> > pairs(m);

    rep(i,m)
    {
        cin>>a>>b;
        pairs[i]=make_pair(b,a);
    }

    sort(pairs.begin(), pairs.end());

    int tmp=pairs[0].first-1;
    res++;

    int i=1;
    while(i<m)
    {
        if(pairs[i].second>tmp)
        //直前の橋カットでは要求を満たさない場合
        {
            tmp=pairs[i].first-1;
            res++;
        }
        i++;
        // cout<<res<<"\n";

    }
    cout<<res<<"\n";


    return 0;
}