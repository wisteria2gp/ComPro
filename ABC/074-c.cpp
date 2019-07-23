

#define MAX 200100;
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;

    int a_time, b_time, c_time, d_time;

    //100あたりe溶ける
    //fまで入れることができる

    double tmp_per = 0, ans_per = -100;
    int ans_1 = 0, ans_2 = 0;

    for (a_time = 0; a_time * 100 * a <= f; ++a_time)
    {
        // cout<<"a"<<endl;
        for (b_time = 0; b_time * 100 * b + a_time * a * 100 <= f; ++b_time)
        {
            // cout<<"b"<<endl;
            int water = 100 * (a * a_time + b * b_time);

            for (c_time = 0; c_time * c <= f - water && c_time * c * 100 <= water * e; ++c_time)
            {
                for (d_time = 0; d_time * d + c_time * c <= f - water && (d_time * d + c_time * c) * 100 <= water * e; ++d_time)
                {

                    if (water != 0)
                    {
                        //桁をましてやらないと小数点の下の方の桁が潰れてしまっている可能性がある
                        //そのためかかなりよくわからないWAを食らってしまった
                        tmp_per = (c_time * c + d_time * d) * 1000000 / (a_time * a + b_time * b);

                        if (ans_per < tmp_per)
                        {
                            ans_per = tmp_per;
                            ans_2 = c_time * c + d_time * d;
                            ans_1 = water + ans_2;
                            // cout<<ans_per<<endl;
                        }
                    }
                }
            }
        }
    }

    cout << ans_1 << " " << ans_2 << "\n";

    return 0;
}