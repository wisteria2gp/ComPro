
# アルゴリズムまとめノート

勉強したアルゴリズムとデータ構造を、使い所や使うための条件などの重要トピックと、典型コードをセットにして残すノートにする予定。

たぶん長くなるので目次つけてほしいところに飛ぶ感じで。


- [アルゴリズムまとめノート](#アルゴリズムまとめノート)
  - [必携標準ライブラリ](#必携標準ライブラリ)
  - [アルゴリズム](#アルゴリズム)    
    - [全探索](#全探索)   
      - [bit全探索](#bit全探索)
    - [貪欲法](#貪欲法)
      - [区間スケジューリング問題](#区間スケジューリング問題)
    - [動的計画法 DP](#動的計画法-dp)        
      - [ナップザック DP](#ナップザック-dp)            
        - [基本のナップザック](#基本のナップザック)            
        - [chmin,chmax](#chminchmax)        
      - [区間 DP](#区間-dp)        
      - [bit DP](#bit-dp)    
    - [二分探索](#二分探索)    
    - [深さ優先探索](#深さ優先探索)    
    - [幅優先探索](#幅優先探索)    
    - [最短経路問題](#最短経路問題)        
      - [ベルマンフォード](#ベルマンフォード)
      - [ダイクストラ](#ダイクストラ)         
      - [ワーシャルフロイド](#ワーシャルフロイド)    
    - [最小全域木問題](#最小全域木問題)    '
    - [累積和](#累積和)    
    - [高速な素数判定法](#高速な素数判定法)    
    - [べき乗を高速に計算するアルゴリズム](#べき乗を高速に計算するアルゴリズム)    
    - [逆元を計算するアルゴリズム](#逆元を計算するアルゴリズム)
  - [データ構造](#データ構造)    
    - [グラフ](#グラフ)    
    - [木](#木)    
    - [Union-Find木](#union-find木)
  - [その他重要概念](#その他重要概念)
    - [iterator](#)iterator
    - [圧縮座標](#圧縮座標)
  - [標準ライブラリだけ対応できないので用意するやつ](#標準ライブラリでは対応できないので用意するやつ)
    - [Combination](#Combination)
    - [重複あり昇順数列](#重複あり昇順列)
    - [pair,struct等のソート](#pair,struct等のソート)
  

まず項目列挙等で参考したのは以下の資料である。

[プログラミングコンテスト攻略のためのアルゴリズムとデータ構造](www.amazon.co.jp/dp/B00U5MVXZO
)

[レッドコーダーが教える、競プロ・AtCoder上達のガイドライン【中級編：目指せ水色コーダー！】](https://qiita.com/e869120/items/eb50fdaece12be418faa#2-2-3-3-%E5%80%8B%E3%81%AE%E5%9F%BA%E6%9C%AC%E3%83%87%E3%83%BC%E3%82%BF%E6%A7%8B%E9%80%A0%E3%82%92%E3%83%9E%E3%82%B9%E3%82%BF%E3%83%BC%E3%81%99%E3%82%8B)


# 必携標準ライブラリ

[厳選！C++ アルゴリズム実装に使える 25 の STL 機能【前編】](https://qiita.com/e869120/items/518297c6816adb67f9a5#3-15-map)

# アルゴリズム

## 全探索

### bit全探索

２進数表記を用いた全探索。　101101

おもに、1が存在する、0が存在しないことを示す。

基本的には、N種類のものが１つずつあるときにそこからN個まで好きに選び取るパターンを全列挙できる。

これは{0,...,N}までの部分集合全列挙である。

ここで部分集合とは{0,1,3},{2,8,16,22},...など

$O(2^N)$なのでN=25前後が$O(10^8)$に収まる境界線である。

```cpp
int main() {
    int n = 3;

    // {0, 1, ..., n-1} の部分集合の全探索
    for (int bit = 0; bit < (1<<n); ++bit) { //2^n パターン全列挙
        vector<int> S;
        for (int i = 0; i < n; ++i) {
            if (bit & (1<<i)) { // 列挙に i が含まれるか
                // iについての処理が可能
                // 処理
            }
        }
    }
}
```

**<例題>**
[C - Skill Up](https://atcoder.jp/contests/abc167/tasks/abc167_c)

### DFSでやる全探索

[参考リンク](https://drken1215.hatenablog.com/entry/2020/05/04/190252)

基本的な想定ケースは下の問題のような状況。

言葉にすると「N種類のものから、重複をゆるして選択し、M個並べる列の全列挙」

たとえば0-9で5個並べる=> 01234,1235,01236,...

問題の方では0-9でつくられる、重複有り昇順列全列挙が必要であった。そのため、dfsにおいて１個前に追加した数を記録して、その先の探索ではその数字以上のものについてのfor文で全探索した。

[C - Many Requirements](https://atcoder.jp/contests/abc165/tasks/abc165_c)

この全列挙をfor文やbit全探索で設置するのはなかなか大変だが、再帰を用いるとスッキリ書ける。

**<コード>**

```cpp
void dfs(vector<int> &A) {
    // 数列の長さが N に達したら打ち切り
    if (A.size() == N) {
        // 処理
        return;
    }

    for (int v = 0; v < M; ++v) {
        A.push_back(v);
        dfs(A);
        A.pop_back();
    }
}

int main() {
    vector<int> A;
    dfs(A);
}

```

## 貪欲法



貪欲法とは、常にそのとき最善の選択を繰り返すアルゴリズム設計技法である。

問題の構造的が、常にその場最善の手を選び続けることで、全体としても最善であることを見抜く必要がある。また、それに付随して、最善の定義をする必要がある。

以降、有名典型例を載せていくが、例えば、ナップザック問題は最善を単位重さあたり価値(価値/重さ)で定義することで貪欲法にできそうだが、これでは真に価値最大化ができない問題の例である。このように、最善をどのように定義すれば、貪欲法に持ち込めるかというところが難しい。

### 区間スケジューリング問題

[参考リンク](http://www.prefield.com/algorithm/misc/interval_scheduling.html)

典型問題は次のようなもの

>仕事がn個あり、各仕事iには開始時刻s[i],終了時刻f[i]が決まっている。同時に複数の仕事は実行できない(時間数直線上に仕事を書き込んだとき、重なりがあってはいけない)。このとき、実施できる仕事の最大数を求めよ（交差しない仕事の最大個数を求めよ）。

この問は、もっとも終了時刻の早い仕事を選び、それと交差するものを除く、という操作を繰り返すことで解くことができる。

証明は必須ではないが、雰囲気は次のようになる

命題：最も終了時刻の早い仕事を行う最適解が存在する

補題：任意の最適解について、その最適解の中で最も早く終わる仕事を、最も終了時刻の早い仕事に置換したものもまた最適解である。

この補題により，最も早い仕事を選び，それによって選べなくなる仕事を除去し，残りの問題（もとの問題と相似構造を持つ）を再帰的に解けばよいことがわかる．

```cpp
struct interval {
  int s, f;
  interval(int s, int f) : s(s), f(f) { }
};
bool compare_f(const interval &x, const interval &y) {
  return x.f < y.f;
}
vector<interval> interval_scheduling(vector<interval> J) {
  vector<interval> A;
  sort(J.begin(), J.end(), compare_f);
  int f = 0;
  for (int i = 0; i < J.size(); ++i) {
    if (J[i].s >= f) {
      A.push_back(J[i]);
      f = J[i].f;
    }
  }
  return A;
}
```

## 動的計画法(DP)

代表的なものは下部項目に続けるので、ここでは概念だけ確認しよう。

Wikiで動的計画法の定義を見ると次のようになっている。

>細かくアルゴリズムが定義されているわけではなく、下記2条件を満たすアルゴリズムの総称である。
>帰納的な関係の利用：より小さな問題例の解や計算結果を帰納的な関係を利用してより大きな問題例を解くのに使用する。
計算結果の記録：小さな問題例、計算結果から記録し、同じ計算を何度も行うことを避ける。帰納的な関係での参照を効率よく行うために、計算結果は整数、文字やその組みなどを見出しにして管理される。

問題に帰納的構造があり、より小さな問題へと分解していくことができるマトリョーシカのような性質があり、さらにその小さな問題に関する計算結果を記録しておくことで大きな問題を簡単に解くのに利用できる。

というのが動的計画法のようだ。

### ナップザック DP
[参考リンク](https://qiita.com/drken/items/a5e6fe22863b7992efdb)

#### 基本のナップザック

ナップザック問題が典型の動的計画法。部分和問題・最小共通部分列もここに含まれるらしい。典型問題は次のようなもの。

> n個の品物があり、i番目の品の重さと価値はweight[i],value[i]で表される。
> ここから総重量がW以下で選んだときの価値の総和の最大値を求めよ。$(n\leq100)$

品の組み合わせ総当りをすると$2^n$通りなので良い方法が必要。

この典型では、i番目までの品から選択し、総重量が$w(0\leq w \leq W)$以下のときの価値総和の最大値を記録する配列dpを作成することを目指す。

```dp[i+1][w]= value```　$(i=0,1,...,n-1,w=0,1,...,W)$

dp[i+1][w]の値を求めるに当たって、dp[i]がすでにわかっていると仮定すると次のように求められる。

**<DP漸化式>**

$$
\rm{dp}[i+1][w]= 
\left\{
\begin{array}{ll}
    \max(\rm{dp}[i][w-weight[i]]+value[i] , \rm{dp}[i][w]) & (w \ge \rm{weight[i]}) \\
    dp[i][w] & (w < \rm{weight}[i])
\end{array}
\right.
$$

また、本問での初期条件はdp[0]、すなわち品なしで考えたとき、いかなる重量でも価値は0であること。

```dp[0][w]=0 (w=0,1,...,W)```

以上から、dp[0]を始点とした、iとwについてｎforループでdpを埋めることができる。このとき時間計算量はO(nW)まで削減できた。

**<コード>**
```cpp
#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// 入力
int n, W;
int weight[110], value[110];
// DPテーブル
int dp[110][10010];

int main() {
  cin >> n >> W;
  for (int i = 0; i < n; ++i) cin >> value[i] >> weight[i];

  // DP初期条件: dp[0][w] = 0
  for (int w = 0; w <= W; ++w) dp[0][w] = 0;

  // DPループ
  for (int i = 0; i < n; ++i) {
    for (int w = 0; w <= W; ++w) {
      if (w >= weight[i]) dp[i+1][w] = max(dp[i][w-weight[i]] + value[i], dp[i][w]);
      else dp[i+1][w] = dp[i][w];
    }
  }

  cout << dp[n][W] << endl;
}
```

**<要点>**

問題構造として、$\rm{dp}[i+1][w]$は本問の部分問題である。そして、この問題の分解では、$\rm{dp}[i+1][w]$以降の問題の状況によって$\rm{dp}[i+1][w]$が変化することがない。

このように、ある部分問題の答えが、それを包括する部分問題の状況によって変わらないような分解方法を見つけたとき、動的計画法が使用できる。

#### chmin,chmax

値の大小ををもとに値を交換したい場合が多いので次のようなテンプレートが頻繁に利用される。

```cpp
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
```

#### in-placeなナップザックDP

[参考リンク](https://qiita.com/drken/items/68b8503ad4ffb469624c#3-lis-%E3%81%AE%E8%A7%A3%E6%B3%951-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-ver)

上で解いたナップザックは２次元DPで解けたが、１次元でもできる。

状態変数をWだけにする。このときiについて選ばない場合の更新は不要になるため、選択する場合のみ更新を行う。

次のような形になる。

**<コード>**

```cpp
#include <iostream>
#include <vector>
using namespace std;

template<class T> void chmax(T &a, T b) {
    if (a < b) a = b;
}

int main() {
    int N, W;
    cin >> N >> W;
    vector<int> weight(N), value(N);
    for (int i = 0; i < N; ++i) cin >> weight[i] >> value[i];

    vector<long long> dp(W+1, 0);
    for (int i = 0; i < N; ++i) {
        for (int w = W; w >= 0; --w) {
            if (w - weight[i] >= 0) {
                chmax(dp[w], dp[w - weight[i]] + value[i]);
            }
        }
    }
    cout << dp[W] << endl;
}
```

wに関するfor文の進み方がW--になっていることに注意。

0から積んでいく場合には、 $dp[w]$ を更新するために用いる $dp[w−weight[i]]$ の値は、すでに $dp[w−2×weight[i]]$ を用いて更新されているというような状態になる。

 $dp[w]$ を更新するために用いる $dp[w−weight[i]]$ の値は更新前である必要があるため、Wをへらす方向でforを回す。

左から順にシーケンシャルに見ていくDPでは

>dp[i][j]dp[i][j] から dp[i+1][k]dp[i+1][k] への遷移において、常に k>jk>j となっているとき

をみたすとき最初の添字iの省略ができる場合がある。

**<貰うDP>**
```cpp
for (int k = W; k >= 0; --k) {
    int j = k - (何か); // k に遷移する元
    chmax(dp[k], dp[j] + (何か));
}
```

**<配るDP>**

```cpp
for (int j = W; j >= 0; --j) {
    int k = j + (何か); // j から遷移する相手
    chmax(dp[k], dp[j] + (何か));
}
```

#### 制約を見抜くDP

E問以上では単純に状態を表す変数をすべて添字にしたDPを使うだけでは時間計算量的に間に合わない問になってくる。

このような場合には条件を整理し、計算量を削減する必要がある。

ダイクストラもDPが内在している手法であるが、近年のAtcoderではダイクストラを使うだけの問題は少ない。

例えば

[E - Two Currencies](https://atcoder.jp/contests/abc164/tasks/abc164_e)

は最短経路を求める問題だが費用の制限があるため単純な最短経路問題ではない。また状態は頂点・所持金・時間あたりになるが全てを添え字にすると計算量が間に合わない。この問題では頂点・所持金を軸にして最小時間を記録するDPを行う必要があり、また頂点をたどる計算にはダイクストラの手法を用いることになる。

このような高度な複合問題も存在することを覚えておこう。

#### LIS(最長増加部分列)

[参考リンク](https://qiita.com/drken/items/68b8503ad4ffb469624c#3-lis-%E3%81%AE%E8%A7%A3%E6%B3%951-%E4%BA%8C%E5%88%86%E6%8E%A2%E7%B4%A2-ver)

動的計画法における所見だと無理めだから覚えておけ的ポジの問題。

技術的になかなか教育的なので記録。

**<典型問題>**

>長さ N の数列 a[0],a[1],…,a[N−1]が与えられます。この数列の部分列であって、単調増加であるようなものの最長の長さを答えてください。

制約は$1\leq N \leq 10^5$ , $0\leq a[i] \leq 10^9$

### 区間 DP

### bit DP




## 二分探索

[参考リンク](https://pyteyon.hatenablog.com/entry/2019/02/20/194140#library)

ここでは標準ライブラリを用いた二分探索活用についてメモする。

対称とする配列・ベクトルはソートされている前提。

```cpp
std::sort(vec.begin(),vec.end());
```

標準ライブラリalgorithmには

- std::binary_search()
- std::lower_bound()
- std::upper_bound()

があり、それぞれ最悪計算量$O(logN+1)$

おもに使うのは

- lower_bound()
  指定された要素**以上**の値が現れる最初の位置のイテレータを取得する。
- upper_bound()
  指定された要素**より大きい**値が現れる最初の位置のイテレータを取得する。 

このイテレータが示すインデックスはstd::distanceを用いることで求めることができる。


```cpp
auto iter = lower_bound(vec.begin(), vec.end(), key);
unsigned int idx = distance(vec.begin(), iter);
```

なお、binary_search()はkeyと一致する要素があるか探査するだけなのであまり旨味がない。

これと同じことがlower_boundの結果のiterの要素とkeyの一致を調べるだけでできてしまう。iterはポインタで要素にアクセス可能。

```cpp
auto iter = lower_bound(vec.begin(), vec.end(), key);
cout<<*iter==key<<endl

```

これらを用いて、ある要素keyを基準により大きい、以上、より小さい、以下の要素の数を数えることができる。

**<コード>**

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> vec = {1, 1, 2, 2, 4, 5, 5, 6, 8, 8, 8, 10, 15};
    size_t len = vec.size();
    int key = 6;

    // 二分探索
    auto iter_lower = lower_bound(vec.begin(), vec.end(), key);
    auto iter_upper = upper_bound(vec.begin(), vec.end(), key);

    // インデックスを取得
    long idx_lower = distance(vec.begin(), iter_lower);  // vec[idx_lower] = vec[7] = 6
    long idx_upper = distance(vec.begin(), iter_upper);  // vec[idx_upper] = vec[8] = 8

    // lower_bound で要素数を数える
    cout << "6 未満の要素数は " << idx_lower << "\n";  // 6 までの要素数 (idx_lower + 1) - 1
    cout << "6 以上の要素数は " << len - idx_lower << "\n";  // 6 までの要素数 (idx_lower + 1) - 1

    // lower_bound で要素数を数える
    cout << "6 以下の要素数は " << idx_upper << "\n";  // 6 までの要素数 (idx_lower + 1) - 1
    cout << "6 より大きい数の要素数は " << len - idx_upper << "\n";  // 6 までの要素数 (idx_lower + 1) - 1

    return 0;
}
```

注意点としてbound系は条件に当てはまる要素が見つからなかった場合配列末尾(vec.end())のイテレータが帰ってくるらしく、アクセスすると配列外参照がおこる可能性がある。

そのため、keyとの一致をたしかめる際には末尾との一致も確かめる必要がある。

```cpp
 if (iter != vec.end() && *iter == key) {
    // 何らかの処理
 }
```

同様の理由で、x未満の数、xより大きい数などをを求める際には以下のようなチェックが必要になる。

```cpp
// 1 段目: x 未満の数を求める
auto iter_A = lower_bound(A.begin(), A.end(), x);
idx_bound_A = distance(A.begin(), iter_A);
num_A = (iter_A == A.end())? N: (idx_bound_A + 1) - 1;

// 3 段目: now_B より大きい数
auto iter_C = upper_bound(C.begin(), C.end(), x);
idx_bound_C = distance(C.begin(), iter_C);
num_C = (iter_C == C.end())? 0: N - idx_bound_C;

```

## 深さ優先探索


## 幅優先探索



## 最短経路問題

重み付きグラフ(ネットワーク)においてノード間を最小コストで渡る経路やそのコスト自体を求めるアルゴリズム。代表的なものとしてベルマンフォード・ダイクストラ・ワーシャルフロイドが挙げられる。

- 単一始点最短経路問題
  - ベルマンフォード
  - ダイクストラ
- 全点対最短経路問題
  - ワーシャルフロイド
  
どの手法もおおむねDPを利用しているため、特定の１点対最短経路を求めるときの計算量はある点から全点への最短経路(単一始点最短経路)を求めることと計算量が変わらない。そのため、最短経路問題はこの２つに分けられる。

それぞれの特徴は以下節で

なお、以下ではノード数を$|V|$ or $N$、エッジ数は$|E|$ or $M$で表す。

ネットワークの表現と最短コストの表現には以下のようなものを準備しておくと良い。

隣接行列や隣接リストなどの方法がある。

**<隣接行列>**

```cpp
const long long INF = 1LL<<60;

// edge構造体 : from , to , costをもつ
struct edge{int from, to,cost;}; 

int MAX_N=1000; //edge 適宜書き換え
int MAX_M=2000; // node　適宜書き換え

vec<edge> es(MAX_M); //辺
vec<ll> d(MAX_N,INF); // 各点への最短距離
int N,M; //Vは頂点数,Eは辺数
vec<bool> negative(MAX_N,false); //負の閉路検出用
```


### ベルマンフォード

単一始点最短経路問題：始点から全点への最小コストを求める

負の辺があっても利用可能

負コストの閉路検出が可能な手法であることが特徴。負の閉路とは閉路の周回コストが負であるため、そこを回り続けることで、コストをいくらでも小さくすることができてしまう構造。


アルゴリズムの流れとしては、まず全点へのコストをINF、始点コストのみ0として初期化。

全ての辺を対象としたfor文をまわし、その中で$\rm{d}[e.from]!=INF$な辺(その辺までのコストが既に１度は探索済み)についてのみ

$\rm{d}[e.to]=min(\rm{d}[e.to] , \rm{d}[e.from]+e.cost)$

で更新する。こうすることで１回目のfor文ではまず始点周辺のコストは１度更新されることがわかる。これをコスト更新がなくなるまでwhile文などで繰り返して更新して求める。


ここで計算量を考える。

もし負の閉路がなければ、最短経路は同じノードを１度しか通らない。つまりノードは$|V|$個以下しか登場しない。エッジも$|V|-1$個以下しか通らない。

すると、while文は$|V|-1$回以下しかおこらない。for文が毎回$|E|$であるから負の閉路がなければ計算量は$O(|V|\times|E|)$である。


**<コード>**

```cpp
const long long INF = 1LL<<60;
struct edge{int from, to,cost;};

vec<edge> es(MAX_E); // 辺の集合
vec<ll> d(MAX_V,INF);  // 始点から各頂点への距離
int V,E;

void shortest_path(int s){
  for(int i=0;i<V;++i) d[i]=INF; // 初期：各頂点へのコストINF
  d[s]=0; // 初期条件：始点コスト0

  for(int i=0;i<V-1;++i){
    bool update=false;//更新確認 whileでやるなら必須
    for(int j=0;i<E;++j){
      edge e=es[j];
      if(d[e.from]!=INF && d[e.to]>d[e.from]+e.cost){
        d[e.to]=d[e.from]+e.cost;
        update=true;
      }
    }
    if(!update) break; //更新がなければ終了
  }
}
```

これがベルマンフォード法である。

また、先程のwhile文のループ回数考察から$|V|$回目のループで更新があれば負の閉路が存在することがわかる。これを負の閉路検出とする。

こちらでは最小コスト記録配列の初期値は全て0とすることですべての負の閉路検出も可能。

```cpp
bool find_negative_loop(int s){
    for(int i=0;i<V;i++) d[i]=0;

    for(int loop=0;loop<V;++loop){
        for(int i=0;i<E;++i){
            edge e=es[i];
            if(d[e.to] > d[e.from]+e.cost){
                d[e.to]=d[e.from]+e.cost;

                // V-1回目でも更新があれば負の経路が存在
                if(i==V-1) return true;
            }
        }
    }
    return false;
}
```

### ダイクストラ

単一始点最短経路問題：始点から全点への最小コストを求める

こちらは負の辺には対応しない。

ベルマンフォードとの違いは、非負コストのみの仮定からくる計算量削減にある。

ベルマンフォードでは

$\rm{d}[e.to]=min(\rm{d}[e.to] , \rm{d}[e.from]+e.cost)$

この更新は$\rm{d}[e.from]$が最小コストでなくとも行われるが、このときの$\rm{d}[e.to]$は最小とはなりえない。また、辺についてのforループでは、各頂点について全ての辺を見ている。これはある程度の無駄をはらんでいる。そこで、次の改善を施す

1. 最小コストが確定した頂点と隣接している頂点を更新する
2. 1で使った「最短コストが確定した頂点」は以降使わない

最小コストが確定した頂点をどのように見つけるかということが問題になる。

これについては、最小コスト経路にまだ利用されていない頂点のうち、探索中のコスト$\rm{d}[i]$が最小の頂点を最小コスト確定とする。これは負の辺がない場合、$\rm{d}[i]$があとから小さくなることがないことからできるものである。


全辺をみてまわる **"辺中心の探索"** なベルマンフォードに比べると、ダイクストラは **"頂点中心な探索"** であると感じる。

**<アルゴリズムの流れ>**

1. 初期条件:始点コスト$\rm{d}[s]=0$
2. 次の最小コスト頂点v確定(初回ならv=sとなる)
3. vを起点に各頂点のコスト更新、２へループ
4. すべての頂点を使用したら終了

隣接行列を利用した実装では、

全頂点を見終わるまでに$|V|$回(while文)

whileの中で、2のために全頂点をみる$|V|$回ループ、3は全辺をみる$|E|$回ループする。

とくに、2で全頂点を見るのがボトルネックであり、次の最小コスト頂点確定に全頂点を見なくて済むようにすることで、これを削減する。

代表的にはSTLのpriority_queを利用する。priority_queは要素をソートして出すことができるque。(正確な定義は調べて)

このqueに、3でコスト更新した頂点をpushし、次の2ではpopしたものを利用することで計算量を省ける。

priority_queを使った実装の計算量は$O((|V|+|E|)log|V|)$

priority_queの内部、ヒープの構造で計算量はある程度変わる。

**<コード>**

```cpp
#include <set>
#include <queue>
#include <vector>

struct edge {
  int u,v;
  int dist;
};

std::vector<int> dijkstra(const std::vector<std::vector<edge>>& g, int s) {
  std::vector<int> dist(g.size(), 1e9);
  using node = std::pair<int,int>;
  std::priority_queue<node,std::vector<node>, std::greater<node>> Q;
  dist[s] = 0;
  Q.push(node(dist[s], s));

  while(!Q.empty()) {
    int v = Q.top().second;
    int d = Q.top().first;
    Q.pop();
    if(dist[v] < d) continue;
    for(const auto& e: g[v]) {
      if(dist[e.u] + e.dist < dist[e.v]) {
        dist[e.v] = dist[e.u] + e.dist;
        Q.push(node(dist[e.v], e.v));
      }
    }
  }

  return std::move(dist);
}
```

### ワーシャルフロイド


## 最小全域木問題


## 累積和
[参考リンク](https://qiita.com/drken/items/56a6b68edef8fc605821)

配列のある範囲の和がほしいという場面がそこそこあるが、それに対応したものが累積わである。

単純に範囲を示すleft,rightをすべて尽くして記憶するとしたとき、前処理で計算量が$O(N^2)$かかってしまう。(大雑把にfor(i=1...N)の二重が必要)

累積和を用いると前処理を **$O(N)$** で済ませることが可能。

技術としては数列の知識を用いる。
$$
\begin{array}{l}
S_0=0\\
S_1=0+a_0\\
S_2=0+a_0+a_1\\
...\\
S_N= 0+a_0+a_1+a_2+a_3+...+a_{N-1} \\
\end{array}
$$

のように定義したとき

$$
S_{left}-S_{right}=a_{left}+a_{left+1}+...+a_{right-1}
$$

が成立する。すなわち、配列の各インデックス$i$に対してそこまでの総和をあらかじめ用意しておけば$[left,right)$の部分和を$O(1)$で取得できる。


**<コード>**

この前処理は次のようなコードで実現できる。

```cpp
int N;cin>>N;
vec<int> a(N);
rep(i,N)cin>>a[i]; //対象の配列を取得
//累積和
vec<int> s(N+1,0); //s[0]=0,aより要素数は１大きい
rep(i,N)s[i+1]=s[i]+a[i];
```

また定まったleft,rightに対して次の形でクエリを実行する。

```cpp
int left,right;
cin>>left>>right;
cout<<s[right]-s[left]<<endl;
```




## 高速な素数判定法

## べき乗を高速に計算するアルゴリズム


## 逆元を計算するアルゴリズム


# データ構造

## グラフ

## 木

### 基本の木構造

### セグメント木

## Union-Find木


# その他重要概念

## 0LL

関数の戻り値の型などはその関数への入力値の型によって決まる。たとえば0を入れると型はintになるわけだ。

制約的に値がintで収まらない場合には0LLを使うと良い。

0LLはlong long型での0として扱うため、上述の内容から関数の返り値がlonglong型になってくれる。

## iterator
データ型レベルの話だが有用性が高いので。

```cpp
auto itr = v.begin(); 
```

## 座標圧縮

[参考リンク](https://drken1215.hatenablog.com/entry/2019/03/21/234900)

数値の集まりがあるとき、その数たちが集合内で何番目に小さい数値なのかを割り振る。

> 10,2,2,500,1000,500

とあったときに

> 1,0,0,2,3,2

のように変換する。同じ値は同じ位置に変換される。

この手法には参考リンクにあるように、かんたんに実装する方法があるのでそれを記録する。

**<コード>**

```cpp
// まず数の集まりをvectorに収納
vector<int> vals;
for (int i = 0; i < n; ++i) vals.push_back(a[i]);
// sort
sort(vals.begin(), vals.end());
// 要素の重複除去(元が同じ値なら同じ位置)
vals.erase(unique(vals.begin(), vals.end()), vals.end());
// 二分探索を利用して先頭からの位置を求める
for (int i = 0; i < N; ++i) {
  int id = lower_bound(vals.begin(), vals.end(), a[i]) - vals.begin();
}
```


# 標準ライブラリでは対応できないので用意するやつ

## Combination
C++には順列列挙(next_permutation)はあるが組み合わせ列挙(nCk)は標準ライブラリにない。そのため自分で用意する必要がある。



## 重複あり昇順列
　[C - Many Requirements](https://atcoder.jp/contests/abc165/tasks/abc165_c)

C問なのに水色一歩手前のdifficultyを記録した名問だ。

結論から言うとこの問題では重複あり昇順数列を制約内で全列挙する必要があった。

重複あり昇順数列はこの問では$A_0 \leq,A_1 \leq ... \leq A_n$を用いて

$A_0A_1A_2...A_n$のように並べた数列を指す。

たとえば1111,1112,1223,3579のように重複を許し、後ろの桁の数が前の桁の数以上で並んだ数列である。

まず、数学的な考察としては

N個の仕切りとM個のボールを並び替えた列と、数列が一対一に対応する。

$A_i=i$番目の仕切りより左側に存在するボールの個数

とすると一対一対応が得られる。

N個の仕切りとM個のボールを並び替える列の数は${}_{N+M}\mathrm{C}_{N}$通りとなる。


プログラムとしては再帰・DFSを使うのがスマートなようなのでそれを記録しておく。

１つ数列をつくるのにNループ必要なので、全列挙には$O(N*{}_{N+M}\mathrm{C}_{N})$かかる。

[参考リンク](https://null-mn.hatenablog.com/entry/2020/05/03/074917?_ga=2.251700430.672253753.1588448542-2118017014.1557058971)

**<コード>**

```cpp
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

int n, m, q;
int a[50], b[50], c[50], d[50];

int dfs(vector<int> &v)
{
  if (v.size() == n)
  {
    // 数を選び終わったのでシミュレート
    int sum = 0;
    for (int i = 0; i < q; i++)
    {
      if (v[b[i]] - v[a[i]] == c[i])
        sum += d[i];
    }
    return sum;
  }

  int last = (v.empty() ? 1 : v.back());
  int Max = 0;
  for (int i = last; i <= m; i++)
  {
    // 追加 -> 先を探索 -> 削除
    v.push_back(i);
    Max = max(Max, dfs(v));
    v.pop_back();
  }
  return Max;
}

int main()
{
  cin >> n >> m >> q;
  for (int i = 0; i < q; i++)
  {
    cin >> a[i] >> b[i] >> c[i] >> d[i];
    a[i]--, b[i]--;
  }
  vector<int> v;
  cout << dfs(v) << endl;
  return 0;
}
```

コードの考え方としては
1. 空ベクトルの参照をDFSに渡す
2. 長さが要求nに達するまで要素を足していく
   1. vectorの末尾要素をlastとし。i=last,last+1,...,Mから順に選ぶ
   2. iをvecに追加
   3. このvecに対してdfsを呼ぶ
   4. この再帰DFSで１サンプルごとのスコアを得て、maxを更新
   5. vec末尾削除
   6. 2-1へ戻り、i++でまたループ


## pair,struct等のソート

[参考リンク](https://dai1741.github.io/maximum-algo-2012/docs/cpp-sort/)

２つ以上の異なる(同一も可)型の要素で構成される組が複数あり、それをなんらかの規則でソートしたい状況がある。そのためこの項目を記録する。

例としてstd::pairを用いる。

pairは異なる型の要素２つを１組にして扱うことのできるクラスである。

次のように使える。

```cpp
#include <iostream>
#include <utility>
#include <string>

int main()
{
  // pairオブジェクトの構築
  std::pair<int, std::string> p = std::make_pair(1, "hello");

  // 要素の参照
  std::cout << p.first << std::endl;
  std::cout << p.second << std::endl;
}
```

 似たようなことは構造体で自作でもできる。

 このpairを要素とするvectorに、例えばint型の要素を基準にsortかけたい。