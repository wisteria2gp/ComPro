
//文字列全探索　探索する場合の数を減らす枝刈りが必要

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
    string s;
    int n;
    cin>>n;
    cin>>s;
    vec<int> num(3,-1);
    set<string> st1{};//１桁目の履歴
    set<string> st2{};//2
    set<string> st3{};//3
    set<string> st{};//パスワードの履歴

    
    string a,b,c;

    rep(i,n){
        a=s[i];
        if (!st1.count(a)){
            st1.insert(a);
            loop(j,i+1,n){
                b=a+s[j];
                if(!st2.count(b)){
                    st2.insert(b);
                    loop(k,j+1,n){
                        c=b+s[k];
                        if(!st3.count(c)){
                            st3.insert(c);
                        }
                    }
                }
            }
        }
    }
    // for(auto v :st3){
    //     cout<<v<<endl;
    // }
    cout<<st3.size()<<endl;
    return 0;

}


