#include <iostream>
using namespace std;

int main()
{
    int a,b,c;
    int Y;
    int N;
    cin>>N>>Y;
    Y=Y/1000 ;
    for (a=0; 10*a<=Y && a<=N;a++)
    {
        for(b=0; 10*a+5*b<=Y && a+b<=N;b++)
        {
            c=N-a-b;
            if(a+b+c==N && 10*a+5*b+c==Y)
            {
                cout<<a<<" "<<b<<" "<<c<<"\n";
                return 0;
            }
        }
    }

    cout<<-1<<" "<<-1<<" "<<-1<<"\n";
    return 0;
}

