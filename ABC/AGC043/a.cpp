

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


int H,W;


void dfs(string s,char mx){
    if(s.length()==N){
        cout<<s<<endl;
        //return;
    }else{
        for(char c='a';c<=mx;c++){
            dfs(s+c,
                    ((c==mx)? (char)(mx+1):mx)  );
        }
    }
}

int main()
{
    cin>>H>>W;
    vec<vector<char>> stage(H,vector<char>(W,'.'));
    rep(i,H){
        rep(j,W){
            cin>>stage[i][j];
        }
    }
    // dfs("",'a');
    for(auto v : stage){
        for(auto e:v){
            cout<<e;
        }
        cout<<endl;
    }

    return 0;

}


