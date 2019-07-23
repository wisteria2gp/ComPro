#include <bits/stdc++.h>

//rep(i,n) : for(int i=0 ; i < n ; i++) : i=0 ~ n-1 
#define rep(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)


//reps(i,n) : for(int i=1 ; i <= n ; i++) : i=1 ~ n 
#define reps(i,n) for(int i=1 ; i##_len=(n) ; i<=i##_len ; ++i)


//ALL(x) : sort(v.begin(), v.end()); == sort(ALL(v));
#define ALL(x) (x).begin(),(x).end()

//pb
#define pb push_back

//SZ(x)
#define SZ(x) ((int)(x).size)



using namespace std;

int
main()
{
    int N;
    int sum=0;
    scanf("%d",&N);

    int A[N];
    
    rep(i,N)
    {
        scanf("%d",&A[i]);
        while(A[i]%2==0){A[i]/=2;sum++;}
    }
    cout<<sum<<endl;

    return 0;




}
