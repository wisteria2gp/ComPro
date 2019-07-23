#include <iostream>
#include<string>
#include<algorithm>
using namespace std;

//文字列を後ろから見ていくGreedy法

string divide[4]={"dream","dreamer","erase","eraser"};

int main()
{
    string S;
    cin >> S;

    //後ろから見る操作を簡単にするために左右反転
    reverse(S.begin(),S.end());
    for(int i=0;i<4;++i)reverse(divide[i].begin(),divide[i].end());

    bool can=true;//全体判定
    for(int i=0;i<S.size();)
    {
        bool can2=false;//部分列の判定
        for(int j=0;j<4;++j)
        {
            string d=divide[j];
            if(S.substr(i,d.size())==d)
            {
                can2=true;
                i+=d.size();
            }
        }
        if(!can2)
        {
            can=false;
            break;
        }
    }

    if(can)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

}