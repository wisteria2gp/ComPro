//std::setを用いたバケット法

#include<iostream>
#include<set>

using namespace std;

int main()
{
    int N;
    int d[110];
    cin >> N;
    for(int i=0;i<N;i++)cin>>d[i];

    set<int> values;
    for(int i=0;i<N;++i)
    {
        values.insert(d[i]);//挿入すると重複は無視してくれる
    }

    cout<<values.size()<<endl;
}