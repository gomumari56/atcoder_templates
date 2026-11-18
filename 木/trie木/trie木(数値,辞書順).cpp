//reference: https://github.com/gomumari56/atcoder_templates

//437 - E

#include<bits/stdc++.h>
#define ll long long
using namespace std;

//.insert 数値の挿入
//.output 辞書順にidを出力

//ここを使う
////////////////////////////////////////////////
struct Trie{
    struct Node{
        //Nodeのメンバ変数の定義
        map<ll,ll> next;
        vector<ll> id;
    };
    //Trieのメンバ変数の定義
    vector<Node> trie;
    //Trieの初期化処理
    Trie(){
        trie.emplace_back();
    }
    //posの後ろに要素x,番号idを追加する
    ll insert(const ll &pos,const ll &x,const ll &id){
        //Nodeが存在しなければ追加
        if(!trie[pos].next.count(x)){
            trie[pos].next[x]=trie.size();
            trie.emplace_back();
        }
        ll npos=trie[pos].next[x];
        //最後のNodeにis_endフラグを立てる
        trie[npos].id.push_back(id);
        return npos;
    }
    void output(ll now){
        for(auto id:trie[now].id){
            cout << id << " ";
        }
        for(auto [key,next]:trie[now].next){
            output(next);
        }
    }
};
////////////////////////////////////////////////

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    Trie t;

    ll N;
    cin >> N;
    vector<ll> x(N+1),y(N+1);
    for(ll i=1;i<=N;i++){
        cin >> x[i] >> y[i];
    }
    vector<ll> pos(N+1);
    pos[0]=0;
    for(ll i=1;i<=N;i++){
        pos[i]=t.insert(pos[x[i]],y[i],i);
    }
    t.output(0);
    cout << endl;

    return 0;
}