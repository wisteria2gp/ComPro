
#include<iostream>
#include<vector>
#include<algorithm>
 using namespace std;

 int main()
 {
     int N,K;
     vector<int> l(100);
     
     scanf("%d %d",&N,&K);
     for(int i=0;i<N;i++)
     {
         scanf("%d",&l[i]);
     }

     sort(l.begin(),l.end());

     int ans=0;
     for(int j=0;j<K;j++)
     {
         ans+=l.back();
         l.pop_back();
     }
     cout << ans << endl;
 } 