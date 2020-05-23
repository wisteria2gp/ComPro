

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

struct edge{int from, to,cost;};

// int型の2次元配列(3×4要素の)の宣言
// vector<vector<int>> data(3, vector<int>(4));

static const  double pi = 3.14159265358979323846;
double sp_l=2*pi/12; //longの1時間の速度
double sp_l_min=sp_l/60; //longのminuteの速度
double sp_s=2*pi; // shortの1時間の速度
double sp_s_min=sp_s/60; // shortのminuteの速度
double a,b;
int h,m;

int main()
{
    cin>>a>>b>>h>>m;
    double l_pos,s_pos;
    l_pos=h*sp_l+m*sp_l_min;
    s_pos=m*sp_s_min;
    
    double x,y;
    x=max(l_pos,s_pos);
    y=min(l_pos,s_pos);
    double rad;
    if(x-y>pi) rad=2*pi-(x-y);
    else if (x-y<pi) rad=x-y;
    else {
        cout<<a+b<<endl;
        return 0;
    }
    // cout<<rad<<endl;


    double c,c2;
    c2=a*a+b*b-2*a*b*cos(rad);
    c=sqrt(c2);
    cout<< std::fixed << std::setprecision(20)<<c<<endl;

    return 0;

}


