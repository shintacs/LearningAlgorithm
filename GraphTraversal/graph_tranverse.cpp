#include <iostream>
#include <vector>

using Graph = vector<vector<int>>; //グラフ型
Graph G;

void search(const Graph &G, int s){
    int N = (int)G.size(); //グラフの頂点数

    //グラフ探索のためのデータ構造
    vector<bool> seen(N, false); //前頂点を「未訪問」に初期化
    queue<int> todo; ///空の状態で初期化(queueだと幅優先，stackだと深さ優先)

    //初期条件
    seen[s] = true; //sは探索済みとする
    todo.push(s); //todoはsのみを含む状態となる

    //todoが空になるまで探索をする
    while(!todo.empty()){
        //todoから頂点を取り出す
        int v = todo.front();
        todo.pop();

        //vから辿れる頂点を全て調べる
        for(int x : G[v]){
            //すでに発見済みの頂点は探索しない
            if(seen[x]) continue;

            //新たな頂点xを探索ずみとしてtodoに挿入
            seen[x] = true;
            todo.push(x);
        }
    }
}