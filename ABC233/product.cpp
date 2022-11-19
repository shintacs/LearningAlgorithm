// DFSを使った全探索.理解しながら自分で書くように取り組んだ
#include <iostream>
#include <vector>

using namespace std;

long long ans=0;
long long N, X;
vector<vector<long long>> A;

void dfs(long long pos, long long prod){

    if(pos == N){ //最後はN-1ではなく、N（dfs(pos+1,a*prod)で最終的にはNで再帰が終わるようになっているため)
        if(prod == X) ans++;
        return;
    }
    for(long long a:A[pos]){ //pos番目の袋に入ってるaを順に見ていく
        if(prod > X/a) continue; //prod*a > Xの変形（もし、Xより大きければ、それ以上見る必要はないのでスキップ）
        dfs(pos+1, a*prod);
    }
}

int main(){
    cin >> N >> X;
    A.resize(N); //Aを要素Nのベクトルにする   
    for(int i=0; i<N; ++i){
        int l; cin >> l;
        A[i].resize(l); //Aの要素に大きさlのベクトルを入れ込んで、可変な2次元配列にする
        for(int j=0; j<l; ++j){
            long long a; cin >> a;
            A[i][j] = a;
        }
    }
    dfs(0,1); //場所0、積1からスタート
    cout << ans << endl;
    return 0;
}