
#define MAX 200100;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int k, n;
    int tmp;
    cin >> n >> k;

    vector<int> memo(n);
    for (int i = 0; i < n; ++i)
    {
        memo[i]=0;
    }

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &tmp);
        memo[tmp]++;
    }

    sort(memo.begin(),memo.end(),greater<int>());

    int res=0;
    for (int i = 0; i < k; ++i)
    {
        res+=memo[i];
    }

    cout<<n-res<<endl;
}