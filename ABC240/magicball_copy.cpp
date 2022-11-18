#include <iostream>
#include <vector>

using namespace std;

int main(){
    int N; cin >> N;
    int ai; cin >> ai;
    vector<int> v;

    int n = ai; 
    int cnt = 1;
    //int num = 1;

    for(int i=0; i<N-1; ++i){
        cin >> ai;
        //num++;

        if(ai == n){
            cnt++;
            if(cnt == ai){
            //num -= cnt;
            cnt = 0;
            continue;
            } 
        } 
        else{
            if(cnt == 0){
                n = ai;
                if(i==N-1) v.push_back(ai);
                continue;
            } 
            for(int j=0; j<cnt; ++j) v.push_back(n);
            n = ai;
            cnt = 1;
        }
    }    

    for(int i=0; i<v.size(); ++i) cout << v[i] << endl;
}