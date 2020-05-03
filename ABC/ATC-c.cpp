//https://atcoder.jp/contests/atc001/tasks/fft_c

//参考
//https://qiita.com/bellbind/items/ba7aa07f6c915d400000

//高速フーリエ変換

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair
#include <cmath>// cos,sin,pi

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;

typedef struct{float cos,sin;} Euler;

Euler expi(float theta) //theta[rad] ,pi/nで書くとラク
{return (Euler){cos(theta),sin(theta)} ;}


