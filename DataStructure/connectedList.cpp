#include <iostream>
#include <string>
#include <vector>

// 連結リストのノードを表す構造体
struct Node{
    Node *next, *prev;
    std::string name;

    Node(std::string name_ = "") : next(NULL), prev(NULL), name(name_){} //コンストラクタの初期化
};

// 番兵を表すノード
Node* nil;

//初期化
void init(){
    nil = new Node();
    nil->next = nil; //初期状態ではnilがnilを指すようにしておく
    nil->prev = nil;
}

//連結リストの出力
void printList(){
    Node* cur = nil->next;
    for(; cur!=nil; cur = cur->next){
        std::cout << cur->name << "->";
    }
    std::cout << std::endl;
}

//ノードpの直後にノードvを挿入する
//ノードpのデフォルト引数をnilとしておく
//insert(v)を呼び出す操作は，リストの先頭への挿入を表す
void insert(Node* v, Node* p = nil){
    v->next = p->next; //初めに元のpの次のポインタをvの次のポインタとして与える必要がある
    p->next->prev = v;
    v->prev = p;
    p->next = v;
}

//ノードvの削除
void erase(Node* v){
    if(v == nil) return; //vが番兵の時は何もしない
    v->prev->next = v->next;
    v->next->prev = v->prev;
    delete v; //メモリの解放
}

int main()
{
    //初期化
    init();

    std::vector<std::string> names = {"yamamoto",
    "watanabe",
    "ito",
    "takahashi",
    "suzuki",
    "sato"};

    Node *watanabe;
    for(int i=0; i<(int)names.size(); ++i){
        Node* node = new Node(names[i]);

        //作成したノードを連結リストの先頭に挿入する
        insert(node);

        //nodeの名前がwatanabeだった時に，そのノードを保持する
        if(names[i] == "watanabe") watanabe = node;
    }
     std::cout << "before: ";
     printList(); //削除前を出力
     erase(watanabe);
     std::cout << "after: ";
     printList(); //削除後の出力

}