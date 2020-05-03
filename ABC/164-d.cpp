

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

const int m=2019;
string S;

int main(){
    cin>>S;
    reverse(S.begin(),S.end());
    int x=1,tot=0;
    int n=S.size();
    //cnt(2019):累積和(mod2019)が何個有るかを数える。(0-2018)
    //同じ値のものが２つあれば、そのセットでmod2019が0になる
    vec<ll> cnt(m);
    ll ans=0;
    rep(i,n){
        cnt[tot]++;
        tot+=(S[i]-'0')*x;//各桁の数を取得
        tot%=m; //modにする
        ans+=cnt[tot];
        x=x*10%m; 
    }
    // loop処理をS=3141592で少し考えてみる
    // まずS=2951413となっている(reverse)
    // x=1,tot=0
    // loop{
        // cnt[tnt=0]=1
        // tot= 2*1 =2
        // tot%2019=2
        // ans += cnt[2] =>0 , ans=0
        // x= 1*10 %2019 =10 
    // }
    // loop{ (x=10,tnt=2)
        // cnt[2]++ =>1
        // tot += 9*10 =>2+90=92
        // tot%2019 = 92
        // ans+=cnt[92]=>0 ,ans=0
        // x= 10*10%2019 =100
    // }
    // loop{(x=100,tnt=92)
        // cnt[tnt=92]=1 
        // tot=92+5*100=>592
        // tot%2019=512
        // ans+=cnt[512] =>0 ,ans=0
        // x=100*10%2019=>1000
    // }
    // 結果的にこのloopではxは10^x(mode2019)
    // tntは累積和(mod2019)を表す変数であることがわかる
    // cntは前述の通りある値(0-2018)のtntの個数を記録する
    // 毎loopで、求めたtntが過去のloopで出てきたなら、そこで2019で割り切れるものが存在する
    // たとえばあまり2がすでに１回でていて、ふたたび出現したらそこで１回、2019で割り切れる
    // もし2回出ていたら,2個, p回でていたらp個できる
    // これはすべて数えた後にcntの各値p(0-2018)について
    // Sigma(p)=p(p-1)/2のpについての総和を求めるのと同じ処理になる

    cout<<ans<<endl;
    return 0;

}


