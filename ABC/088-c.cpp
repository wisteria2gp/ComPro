
#define MAX 110;
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int c[3][3];
    for(int i=0;i<3;++i)
    {
        scanf("%d %d %d",&c[i][0],&c[i][1],&c[i][2]);
    }

    int a1,a2,a3,b1,b2,b3;

    bool can=false;

    a1=0;
    b1=c[0][0]-a1;
    b2=c[0][1]-a1;
    b3=c[0][2]-a1;

    a2=c[1][0]-b1;
    a3=c[2][0]-b1;
    if(a2==c[1][1]-b2 && a2==c[1][2]-b3 && a3==c[2][1]-b2 && a3==c[2][2]-b3) can=true;

    if(can) cout<<"Yes"<<"\n";
    else cout<<"No"<<"\n";

}