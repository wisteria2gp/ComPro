
// bit探索
#include<bits/stdc++.h>
#include<set>
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
    int n,a;
    cin>>n;

    vec<int> s(n,0);
    vec<int> p(n,0);
    set<int> st{};

    int y,digit;

    rep(i,n){
        cin>>a;
        rep(j,a){
            s[i]|=(1<<i);
            cin>>digit>>y;
            digit--;
            if(y==1){
                s[i]|=(1<<digit);
            }
        }
    }

    int start=0;    
    rep(i,n){
        start|=(1<<i);
    }

    for(int bit=start;bit>0;--bit){
        st={};
        rep(i,n){
            if(bit&(1<<i)){
                if(!st.count(bit&s[i])){
                    st.insert(bit&s[i]);
                }
            }
        }

        if(st.size()<1){
            cout<<__builtin_popcount(bit)<<endl;
            return 0;
        }
    }

    cout<<-1<<endl;
    return 0;

}


