//つくりかけ

//https://atcoder.jp/contests/atc001/tasks/fft_c

//参考
https://qiita.com/bellbind/items/ba7aa07f6c915d400000

//離散フーリエ変換

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <algorithm> // sort
#include <map> // pair
#include <cmath>// cos,sin,pi

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

typedef struct{float cos,sin;} Euler;

//オイラーの公式から複素expをcos+i*sin形式に変換
Euler expi(float theta) //theta[rad] ,pi/nで書くとラク
{return (Euler){cos(theta),sin(theta)} ;}


//複素数計算
void iadd(float a[2],float b[2],float res[2])
{   res[0]=a[0]+b[0];
    res[1]=a[1]+b[1];
    return ; 
}

void isub(float a[2],float b[2],float res[2])
{   res[0]=a[0]-b[0];
    res[1]=a[1]-b[1];
    return ; 
}

void imul(float a[2],float b[2],float res[2])
{   res[0]=a[0]*b[0]-a[1]*b[1];
    res[1]=a[0]*b[1]+a[1]*b[0];
    return ; 
}

//csは複素数配列
void isum(vector<float>& cs,int size,float res[2])
{
    float x=0,y=0;
    for(int i=0;i<size;i++)
    {
        x+=cs.at(i).at(0);
        y+=cs.at(i).at(1);
    }
    res[0]=x;
    res[1]=y;
    return ;
}




int main()
{


    return 0;
}

