



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

string s;

int main()
{
    cin>>s;
    int n=s.size();
    string former,latter;
    former=s.substr(0,(n-1)/2);
    latter=s.substr((n+1)/2);
    reverse(latter.begin(),latter.end());
    if(former==latter){

        int m=former.size();
        string subf,subl;
        if(m%2==0){
            subf=former.substr(0,m/2);
            subl=former.substr(m/2);
        }else{
            subf=former.substr(0,(m-1)/2);
            subl=former.substr((m+1)/2);
        }
        reverse(subl.begin(),subl.end());
        if(subf==subl){
            cout<<"Yes"<<endl;
            return 0;
        }else{
            cout<<"No" <<endl;
            return 0;
        }
    }else{
        cout<<"No" <<endl;
        return 0;
    }

    return 0;

}


