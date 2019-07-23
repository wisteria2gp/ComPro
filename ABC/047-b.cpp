//集計処理・バケット法・ソート？

#define MAX_N 100;
#include<iostream>

#include<vector>
using namespace std;


int main()
{
    int W,H,N;
    scanf("%d %d %d",&W,&H,&N);
    int left=0,right=W,lower=0,upper=H;
    int x,y,a;
    for(int i=0;i<N;++i)
    {
        scanf("%d %d %d",&x,&y,&a);
        if(a==1)
        {
            left=max(left,x);
        } 
        else if(a==2)
        {
            right=min(right,x);
        }
        else if(a==3)
        {
            lower=max(lower,y);
        }
        else if(a==4)
        {
            upper=min(upper,y);
        }

    }
    // cout<<left<<" "<<right<<" "<<lower<<" "<<upper<<endl;

    int dx=max(right-left,0);
    int dy=max(upper-lower,0);

    int ans=dx*dy;
    cout<<ans<<endl;

    return 0;


}