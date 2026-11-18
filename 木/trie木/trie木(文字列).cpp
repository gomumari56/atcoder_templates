//reference: https://github.com/gomumari56/atcoder_templates
#include<bits/stdc++.h>
#define ll long long
using namespace std;

//.insert 文字列の挿入
//.search 文字列の存在判定

//ここを使う
////////////////////////////////////////////////
struct Trie{
    struct Node{
        //Nodeのメンバ変数の定義
        array<ll,26> next;
        bool is_end=false;
        //Nodeの初期化処理
        Node(){
            next.fill(-1);
        }
    };
    //Trieのメンバ変数の定義
    vector<Node> trie;
    //Trieの初期化処理
    Trie(){
        trie.emplace_back();
    }
    //文字列の挿入
    void insert(const string &s){
        ll v=0;
        for(char c:s){
            ll x=c-'a';
            //Nodeを進んでいき、存在しなければ追加
            if(trie[v].next[x]==-1){
                trie[v].next[x]=trie.size();
                trie.emplace_back();
            }
            v=trie[v].next[x];
        }
        //最後のNodeにis_endフラグを立てる
        trie[v].is_end=true;
    }
    //文字列の存在判定
    bool search(const string &s){
        ll v=0;
        for(char c:s){
            ll x=c-'a';
            //Nodeを進んでいき、存在しなければfalse
            if(trie[v].next[x]==-1){
                return false;
            }
            v=trie[v].next[x];
        }
        //最後のNodeでis_endフラグが立っていれば存在する
        return trie[v].is_end;
    }
};
////////////////////////////////////////////////

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    Trie t;

    t.insert("apple");
    t.insert("ample");
    t.insert("buss");
    t.insert("append");

    auto ch = [&](string s) -> void {
        if(t.search(s)){
            cout << s << " : Yes" << endl;
        }
        else{
            cout << s << " : No" << endl;
        }
    };

    ch("apple");
    ch("and");
    ch("buss");
    ch("append");
    ch("appendd");
    ch("appen");
    ch("c");

    return 0;
}