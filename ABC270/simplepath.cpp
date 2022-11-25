#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> v;
vector<bool> flag;
vector<int> path;
int N, X, Y;
bool stop;

void dfs(int curr, int goal)
{
    flag[curr] = true;
    if(!stop) path.push_back(curr+1);
    if(curr == goal){
        stop = true;
    }
    for(int i : v[curr]){
        if(!flag[i-1]) dfs(i-1, goal);
    }
    if(!stop) path.pop_back();
    return;
    
}

int main(){
    cin >> N >> X >> Y;
    v.resize(N);
    flag.resize(N, false);
    for(int i=0; i<N-1; ++i){
        int ui, vi; cin >> ui >> vi;
        v[ui-1].push_back(vi);
        v[vi-1].push_back(ui);
    }
    vector<int> vs;
    dfs(X-1, Y-1);
    for(int i : path) cout << i << " ";
    cout << endl;
}