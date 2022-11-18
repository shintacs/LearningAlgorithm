#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N; cin >> N;
    int cnt=0;
    vector<pair<int, int>> v;
    
    for(int i=0; i<N; ++i){
        int ai;
        cin >> ai;
        if(v.empty() || v.back().first != ai){
            v.push_back(make_pair(ai, 1));
            cnt++;
        }
        else{
            v.back().second++;
            cnt++;
            
            if(v.back().second == ai){
                v.pop_back();
                cnt -= ai;
            }
        }
        cout << cnt << endl;
    }
}