

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

int vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return 1;
  }
  else { // 発見できなかったとき
    return 0;
  }
}

int n,k;

int main()
{
    cin>>n>>k;
    vec<int> A(n,0);
    rep(i,n){
        cin>>A[i];
        A[i]--;
    }
    bool flag=false;
    int next=0;
    vec<int> done;
    int loop=0;
    

    while(true){
        
        done.push_back(next);
        next=A[next];
        flag=vector_finder(done,next)
        if(flag){
            loop=done.size();
            break;
        }
    }


    return 0;

}


