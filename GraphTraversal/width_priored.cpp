#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

vector<int> BFS(const Graph &G, int s){
    int N = (int)G.size(); //頂点数
    vector<int> dist(N, -1); //全ての頂点を未訪問で初期化
    queue<int> que;

    //初期条件
    dist[0] = 0;
    que.push(0); //根を確認済みにする

    //BFS開始
    while(!que.empty()){
        int v = que.front(); //キューの先頭を取り出す
        que.pop();

        //vから辿れる頂点を調べる
        for(int x : G[v]){
            if(dist[x] != -1) continue;
            dist[x] = dist[x] + 1;
            que.push(x);
        }
    }
    return dist;
}

int main(){
    //頂点数と辺の数
    int N,M;
    cin >> N >> M;

    Graph G(N);
    for(int i=0; i<M; ++i){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //頂点0を支点としたBFS
    vector<int> dist = BFS(G,0);

    for(int v=0; v<N; ++v){
        cout << v << ": " << dist[v] << endl;
    }
}