

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

vector<ll> v;
//kが桁数
//xがルンルン数
//解答候補のすべて入ったベクトルを作成
void dfs(int k,ll x){
    v.push_back(x); //適格数を雑に入れる
    //問題でmax kのときの最大値が4x10^9以下であると示されているので
    // 0-9までの数字から初めてyx10^9に届いたら探索終了.これで解答候補はすべてみたことになる。
    if(k>=9) return; 

    int a=x%10;
    // x (mod 10)=0,9のときは少し特殊
    //たとえばx=34として
    // 340+ {4-1,4,4+1}=343,344,345はルンルン数になる
    // 一方でx=10とすると
    // 100+{0-1,0,0+1}=99,100,101となるが,99は9からの探査で登場するため被ることが確定しているため探査不要
    // x=99とすると
    // 990+{9-1,9,9+1}=998,999,1000となるが,1000は100からの探査で登場するため探査不要
    // したがって、a=0のときはa-1の探査不要,a=9のときはa+1の探査不要
    if(a){
        dfs(k+1,x*10+a-1);
    }
    dfs(k+1,x*10+a);
    if(a<9){
        dfs(k+1,x*10+a+1);
    }
}



int main()
{
    int k;
    cin>>k;
    rep(i,10) dfs(0,i);
    sort(v.begin(),v.end());//ソート
    //uniqueは隣り合った重複要素を後ろに寄せたイテレータを返す(なので完全に重複を消すなら事前ソートが必要)
    //uniqueを実行すると返り値(result)が得られ、(v.begin(),result)の範囲に非重複要素が,(result,v.end())の部分に重複要素が...となる
    //v.erase(result,v.end())とすることで重複部分を削除することができる
    v.erase(unique(v.begin(),v.end()),v.end());
    cout<<v[k-1]<<endl;
    return 0;

}


