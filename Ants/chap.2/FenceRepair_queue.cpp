
#include<iostream>
#include<vector>
#include<queue>
typedef long long ll;
using namespace std;

const int MAX_N=20000;

int N,L[MAX_N];

void solve()
{
    ll ans=0;

    //priority_queueを用意(小さいものから順に取り出せるようにする)
    //２番目引数はContainerに利用するものでvectorがデフォ
    //３番目はCompareはデフォはstd::less<T>,降順
    //今回は昇順にするため   std::greater<int>  を入れた
    priority_queue<int,vector<int>,greater<int>>que;

    for(int i=0;i<N;++i)
    {
        que.push(L[i]);
    }

    //板が１本になるまで適用
    while(que.size()>1)
    {
        //一番短い板,次に短い板を取り出す
        int l1,l2;
        l1=que.top();
        que.pop();
        l2=que.top();
        que.pop();

        //それらを併合
        ans+=l1+l2;
        que.push(l1+l2);
    }

    printf("%lld\n",ans);
}

int main()
{
    cin>>N;
    for(int i=0;i!=N;++i)
    {
        cin>>L[i];
    }
    solve();
}