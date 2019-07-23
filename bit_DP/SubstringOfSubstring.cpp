//部分集合の部分集合列挙
#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n=10;
    int A=(1<<2)|(1<<3)|(1<<5)|(1<<7);

    for (int bit=A; ; bit=(bit-1)&A)
    {
        vector<int> S;
        for(int i=0;i<n;++i)
        {
            if(bit &(1<<i))
            {
                S.push_back(i);
            }
        }

        // bit の表す集合の出力
        cout << bit << ": {";
        for (int i = 0; i < (int)S.size(); ++i) {
            cout << S[i] << " ";
        }
        cout << "}" << endl;

        if(!bit) break;
    }
}