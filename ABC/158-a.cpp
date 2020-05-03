

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
string str;



int main()
{

    cin>>str;
    if (str[0]==str[1] and str[0]==str[2])
    {
        cout << "No"<<endl;
    }
    else
    {
        cout<<"Yes"<<endl;
    }
    return 0;
}


