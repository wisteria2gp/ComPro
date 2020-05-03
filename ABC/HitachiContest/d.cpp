

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


const int MAX_H=10000;
const int MAX_N=1000;

int N,ans;
ll T,total,time;
bool flag,flag_index;
vec<int> index_list;

flag=false;

bool vector_finder(std::vector<int> vec, int number) {
  auto itr = std::find(vec.begin(), vec.end(), number);
  size_t index = std::distance( vec.begin(), itr );
  if (index != vec.size()) { // 発見できたとき
    return true;
  }
  else { // 発見できなかったとき
    return false;
  }
}

int main()
{
    cin>>N>>T;
    vec<ll> a(N),a(N);
    time=1;

    rep(i,N)
    {
        cin>>a[i]>>b[i];
    }

    ll min_t;
    while(time>=T)
    {
        min_t=INF
        rep(i,N){
            if(min_t>= a[i]*time+b[i])
            {
                flag=(min_t==a[i]*time+b[i])
                min_t=a[i]*time+b[i]
                if(flag)
                {
                    if(a[flag_index]<a[i])
                    {
                        
                    }
                    else
                    {
                        flag_index=i;
                    }
                    
                }
                else
                {
                    flag_index=i;
                }
                flag=false;
            }
        }
        time+=min_t
        min_t=INF
        index_list.push_back(flag_index)

    }



    cout<<"No"<<endl;
    return 0;

}


