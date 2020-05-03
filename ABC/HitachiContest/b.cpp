

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

int A,B,M,tmp_a,tmp_b,tmp_coupon;
vec<int>  a(100010,1000000),b(100010,1000000),val(10010,1000000);
int x,y,c;

int main()
{

    cin>>A>>B>>M;
    int min_a=100000;
    int min_b=100000;
    rep(i,A)
    {
        cin>>tmp_a;
        a[i]=tmp_a;
        min_a=min(min_a,tmp_a);
    }
    rep(i,B)
    {
        cin>>tmp_b;
        b[i]=tmp_b;
        min_b=min(min_b,tmp_b);
    }
    int tmp_min=min_a+min_b;

    rep(i,M)
    {
        cin>>x>>y>>c;
        tmp_min=min(tmp_min,a[x-1]+b[y-1]-c);
    }
    cout<<tmp_min<<endl;
    return 0;

}


