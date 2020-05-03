

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

int lcm(int a,int b){
    //最小公倍数
    return a/__gcd(a,b) * b;
}



int main()
{
    int k,n;
    cin>>k>>n;

    vector<int> a (n);
    rep(i,n) cin>>a [i];

    sort(a.begin(),a.end());

    int tmp=10000000;
    rep(i,n-1){
        tmp=min(tmp,k-(a[i+1]-a[i]));
    }
    tmp=min(tmp,a[n-1]-a[0]);

    cout<<tmp<<endl;

    

    return 0;

}


