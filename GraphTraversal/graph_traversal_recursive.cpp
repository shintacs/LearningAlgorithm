#include <iostream>
#include <vector>
using namespace std;
using Graph = vector<vector<int>>;

//深さ優先探索
vector<bool> seen;
void dfs(const Graph &G; int v){
    seen[v] = true; // vを訪問済みにする

    // vからいける各頂点について
    for(auto next_v : G[v]){
        if(seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main(){
    int N,M;
    cin >> N >> M;

    //グラフ入力受け取り
    Graph G(N);
    for(int i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }

    //探索
    seen.assign(N,false);
    for(int v=0; v<N; ++v){
        if(seen[v]) continue;
        dfs(G,v);
    }
}