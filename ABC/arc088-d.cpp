

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


string S;



int main()
{
    cin>>S;
    int len=S.size();
    int ans=len;
    rep(i,len-1){
        if(S[i]!=S[i+1]){
            chmin(ans,max(i+1,len-i-1));
        }
    }

    cout<<ans<<endl;
    

    return 0;

}


