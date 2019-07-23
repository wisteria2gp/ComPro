
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

int main()
{
    int N,L;
    vector<string> S(110);

    cin>>N>>L;
    for (int i=0;i<N;i++)
    {
        cin>>S[i];
    }

    sort(S.begin(),S.end());

    for (auto x : S)
        cout << x;


    cout<<endl;
    return 0;
}