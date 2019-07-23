//集計処理　バケット法 std::map

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
    int n,m;
    string tmp;
    map<string,int> mp;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>tmp;
        mp[tmp]+=1;
    }

    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>tmp;
        mp[tmp]-=1;
    }

    int ans=-1000;
    /* 
    mapのiteration
    key,valueそれぞれにitr->first,itr->secondでアクセスできる
    */
    for(auto itr=mp.begin();itr != mp.end(); ++itr)
    {
        ans=max(ans,itr->second);
    }

    //カードとは全く違う文字列を言うことで損失を防ぐケースを忘れて１ミス
    if(ans<=0)cout<<0<<endl;
    else cout<<ans<<endl;;

    
}