


// コンペ中に思ったとおりABC164_Dによく似ている。

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



int n;
int main()
{
    cin>>n;
    vec<int> v(n);
    iota(v.begin(), v.end(), 1); //1からはじめるm要素の列
    
    map<int,int> mp;
    ll tmp=0;
    ll ans=0;
    rep(i,n){
        cin>>tmp;
        ans+=mp[i-tmp];　//記録した値と一致するものがいればその分合致する組数が増える
        mp[i+tmp]++;//今回の入力を記録
    }
    


    cout<<ans<<endl;

    return 0;

}


