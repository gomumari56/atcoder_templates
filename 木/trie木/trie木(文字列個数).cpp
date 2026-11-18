//reference: https://github.com/gomumari56/atcoder_templates

//403 - E

#include<bits/stdc++.h>
#define ll long long
using namespace std;

const bool test=false;

//.insert 文字列の挿入
//.search 文字列の存在判定
//.forbid その文字列を接頭辞に持つ文字列を全て無効にする
//sum 有効な文字列の個数

//ここを使う
////////////////////////////////////////////////
struct Trie{
    struct Node{
        //Nodeのメンバ変数の定義
        array<ll,26> next;
        ll cnt=0;
        bool forbidden=false;
        //Nodeの初期化処理
        Node(){
            next.fill(-1);
        }
    };
    //Trieのメンバ変数の定義
    vector<Node> trie;
    ll sum=0;
    //Trieの初期化処理
    Trie(){
        trie.emplace_back();
    }
    //文字列の挿入
    void insert(const string &s){
        if(test){
            cout << "insert:" << s << endl;
        }
        ll v=0;
        for(char c:s){
            if(test){
                cout << "now:" << v << endl;
            }
            if(trie[v].forbidden){
                if(test){
                    cout << "forbidden" << endl;
                }
                return;
            }
            ll x=c-'a';
            //Nodeを進んでいき、存在しなければ追加
            if(trie[v].next[x]==-1){
                trie[v].next[x]=trie.size();
                trie.emplace_back();
            }
            v=trie[v].next[x];
        }
        //最後のNodeに個数を加算
        if(!trie[v].forbidden){
            trie[v].cnt++;
            sum++;
        }
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
        return (trie[v].cnt>0);
    }
    void forbid_sub(const ll &pos){
        if(!trie[pos].forbidden){
            sum-=trie[pos].cnt;
            trie[pos].forbidden=true;
            if(test){
                cout << "forbid " << pos << endl;
            }
            for(auto nxt:trie[pos].next){
                if(nxt!=-1){
                    forbid_sub(nxt);
                }
            }
        }
    }
    void forbid(const string &s){
        ll v=0;
        for(char c:s){
            if(trie[v].forbidden){
                return;
            }
            ll x=c-'a';
            //Nodeを進んでいき、存在しなければ追加
            if(trie[v].next[x]==-1){
                trie[v].next[x]=trie.size();
                trie.emplace_back();
            }
            v=trie[v].next[x];
        }
        if(test){
            cout << "forbidsub on " << v << endl;
        }
        forbid_sub(v);
    }
};
////////////////////////////////////////////////

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    Trie T;

    ll Q;
    cin >> Q;

    while(Q--){
        ll t;
        string s;
        cin >> t >> s;
        if(t==1){
            T.forbid(s);
        }
        if(t==2){
            T.insert(s);
        }
        cout << T.sum << endl;
    }

    return 0;
}