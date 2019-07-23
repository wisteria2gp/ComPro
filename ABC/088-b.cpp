

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;


int main()
{
    int N;
    vector<int> a(110);
    int alice=0;
    int bob=0;

    scanf("%d",&N);
    for(int i=0;i<N;i++)
    {
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    int turn=0;
    int add;
    while(!a.empty())
    {
        add=a.back();
        a.pop_back();
        if(turn%2==0) alice+=add;
        else bob+=add;

        turn++;
    }

    int ans=alice-bob;
    cout<<ans;
}
