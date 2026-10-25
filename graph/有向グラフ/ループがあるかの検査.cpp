#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
using namespace std;

//Gは有向グラフ
vector<vector<ll>> G(200020);

//dfsが通ったことがある頂点集合
vector<bool> dfs_vis(200020,false);

//dfsにより、その先にループがないことが確かめられた頂点集合
vector<bool> dfs_seen(200020,false);

//edgeからスタートして、途中にループがあればtrue、なければfalseを返す
bool dfs_loop(ll edge);

int main(){
    ll N,M;
    cin >> N >> M;
    ll K[400040]={};
    for(ll k=1;k<=M;k++){
        ll t;
        cin >> t;
        for(ll i=1;i<=t;i++){
            cin >> K[i];
            if(i>1){
                G[K[i]].push_back(K[i-1]);
            }
        }
    }

    //dfs_loopを頂点1,2,...,Nに対して行うことで、グラフ上にループが1個もないことが検証できる
    for(ll i=1;i<=N;i++){
        if(dfs_vis[i]==true){
            continue;
        }
        //頂点iから始めてループがあれば、Gはループを持つ
        if(dfs_loop(i)){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}
bool dfs_loop(ll edge){
    dfs_vis[edge]=true;
    for(auto p:G[edge]){
        if(dfs_vis[p]==true){
            if(dfs_seen[p]==false){
                return true;
            }
        }
        else{
            bool f=dfs_loop(p);
            if(f){
                return true;
            }
        }
    }
    dfs_seen[edge]=true;
    return false;
}