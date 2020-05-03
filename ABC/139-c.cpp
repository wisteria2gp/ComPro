#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main()
{
    int N;
    // vector<int> a(100100);
    int former,latter;
    int tmp=0;
    int score=0;

    scanf("%d",&N);
    if(N<=1){
        cout<<0<<"\n";
    }
    else if(N==2)
    {
        cin>>former;
        cin>>latter;
        if (former>=latter)
        {
            cout<<1<<"\n";
        }
        else
        {
            cout<<0<<"\n";
        }
    }
    else{
        cin>>former;
        cin>>latter;
        for(int i=2;i<N;i++)
        {
            if(former>=latter)tmp++;
            else 
            {
                if(score<tmp) score=tmp;
                tmp=0;
            }
            
            former=latter;
            cin >> latter;
        }
        // cout<<tmp<<" "<<former<<" "<<latter<<"\n";
        if(former>=latter)tmp++;
        if(score<tmp) score=tmp;

        cout<<score<<"\n";
    }    
}

