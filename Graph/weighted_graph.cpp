#include <iostream>
#include <vector>
using namespace std;

struct Edge{
    int to; //グラフのつながる先
    long long weight; //エッジの重み
    Edge(int to, long long weight) : to(to), weight(weight){}
};

using Graph = vector<vector<Edge>>;

int main()
{
    int N, M; //頂点の数と辺の数
    cin >> N >> M;

    // グラフの初期化 
    Graph G(N);
    for(int i=0; i<M; ++i){
        int a,b;
        long long w;
        cin >> a >> b >> w;
        G[a].push_back(Edge(b, w));
    }
}