

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

int a,b,last;



int main()
{

    cin>>a>>b;
    last=ceil(max(a/0.08+13,b/0.1+11));
    //cout<<last<<endl;

    rep(i,last)
    {
        //cout<<floor(i*0.08)<<endl;
        if(floor(i*0.08)==a and floor(i*0.1)==b){
            cout<<i<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
    return 0;

}


