//https://atcoder.jp/contests/kupc2015/tasks/kupc2015_a


#include <iostream>
#include <vector>
#include <algorithm>
#include <string>


#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

const int MAX_q=160;
const int MAX_L=1010;
bool done[MAX_L][MAX_L];
int memo[MAX_L][MAX_L];
int t;
string s;

int search(string s)
{
    int res=0;
    string tmp;
    rep(i,s.length())
    {
        tmp=s.substr(i,5);
        if (tmp=="kyoto" or tmp=="tokyo")
        {
            res++;
            i+=4;
        }
    
    }
    return res;
}



int main()
{
    int res;
    cin>>t;
    rep(i,t)
    {
        cin>>s;
        res=search(s);
        cout<<res<<"\n";

    }


    return 0;
}