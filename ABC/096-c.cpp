

#define MAX 200100;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;

    int ans;
    if(2*c>a+b)
    {
        ans=x*a+y*b;
    }
    else
    {
        if(x>y)
        {
            if(2*c<a)
            {
                ans=2*x*c;
            }
            else
            {
                ans=2*y*c+(x-y)*a;
            }
            
        }
        else
        {
            if(2*c<b)
            {
                ans=2*y*c;
            }
            else
            {
                ans=2*x*c+(y-x)*b;
            }
        }
        
    }

    cout<<ans<<"\n";
    
}