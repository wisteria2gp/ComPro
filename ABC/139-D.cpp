

#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;


int main()
{
    long long N;
    cin>>N;
    if(N==1)
    {
        cout<<0<<"\n";
    }
    else
    {
        cout<< N*(N-1)/2 <<"\n";
    }

}