#include <iostream>
#include <vector>
using namespace std;

struct Heap{
    vector<int> heap;
    Heap(){}

    void push(int x){
        heap.push_back(x);
        int i = (int)heap.size() - 1; //挿入された番号
        while(i > 0){
            int p = (i-2) / 2; // 親の番号
            if(heap[p] >= x) break;
            heap[i] = heap[p];
            i = p;
        }
        heap[i] = x; //最後に数字を入れる（毎回入れ替えを行う訳ではない）
    }

    int top(){
        if(!heap.empty()) return heap[0];
        else return -1;
    }

    // 最大値をpop
    void pop(){
        if(heap.empty()) return;
        int x = heap.back();
        heap.pop_back();
        int i=0;
        while(i*2+1 < (int)heap.size()){
            int child1 = i*2+1; int child2 = i*2+2;
            if(child2 < (int)heap.size() && heap[child2] > heap[child1]){
                child1 = child2;
            }
            if(heap[child1] <= x) break;
            heap[i] = heap[child1];
            i = child1;
        }
        heap[i] = x; //最終的に，正しい場所にxを挿入する
    }
};

int main(){
    Heap h;
    h.push(5); h.push(3); h.push(7); h.push(1);

    cout << h.top() << endl;
    h.pop();
    cout << h.top() << endl;

    h.push(11);
    cout << h.top() << endl;

}