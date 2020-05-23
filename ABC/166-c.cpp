

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


int n,m;

int main()
{
    cin>>n>>m;
    vec<int> h(n,0);
    rep(i,n){cin>>h[i];}
    vec<int> v(n);
    iota(v.begin(), v.end(), 0); //1からはじめるm要素の列
    set<int> s;

    int a,b;
    rep(i,m){
        cin>>a>>b;
        a--;
        b--;

        if(h[a]>=h[b]){
            s.insert(b);
        }
        
        if(h[b]>=h[a]){
            s.insert(a);
        }
    }
    int ans=n-s.size();
    // for(auto e:s){
    //     cout<<e+1<<" ";
    // }
    // cout<<endl;

    cout<<ans<<endl;

    return 0;

}


