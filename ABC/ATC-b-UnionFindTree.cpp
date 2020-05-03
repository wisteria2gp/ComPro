

#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // sort
#include <map> // pair

#define loop(i,a,b) for(int i=a;i<b;i++) 
#define rep(i,a) loop(i,0,a)

using namespace std;



struct UFT //Union-Find-Tree
{
    vector<int> par;  // par[i]:iの親の番号　(例) par[3] = 2 : 3の親が2

    UFT(int N) : par(N)
    {
        rep(i,N) par[i]=i;
    }

    int root(int x)  // データxが属する木の根を再帰で得る：root(x) = {xの木の根}
    {
        if (par[x]==x) return x;
        return par[x]=root(par[x]);
    }

    void unite(int x,int y) // xとyの木を併合
    {
        int rx=root(x);
        int ry=root(y);

        if(rx==ry)return ;
        par[rx]=ry; //xとyの根が同じでない(=同じ木にない)時：xの根rxをyの根ryにつける

    }

    bool same(int x,int y) // 2つのデータx, yが属する木が同じならtrueを返す
    {
        int rx=root(x);
        int ry=root(y);
        return rx==ry;
    }

};



int main()
{
    int n,q;
    int p,a,b;
    int res;

    cin>>n>>q;

    UFT tree(n);

    rep(i,q)
    {
        cin>>p>>a>>b;
        if(p==0) tree.unite(a,b);
        else 
        {
            res=tree.same(a,b);
            if(res) cout<<"Yes"<<"\n";
            else cout<<"No"<<"\n";
        }

    }


    return 0;
}