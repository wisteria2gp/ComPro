

#include<bits/stdc++.h>

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

template <class T>
using vec = std::vector<T>;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL<<60;


const int MAX_H=10000;
const int MAX_N=1000;

string in;



int main()
{

    cin>>in;


    if(in=="hi" or in=="hihi" or in =="hihihi" or in=="hihihihi" or in=="hihihihihi")
    {
        cout<<"Yes"<<endl;
        return 0;
    }


    cout<<"No"<<endl;
    return 0;

}


