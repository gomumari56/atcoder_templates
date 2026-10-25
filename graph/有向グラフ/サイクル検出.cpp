#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
#define vertex pair<ll,ll>
using namespace std;
bool cycle_find(vector<vector<ll>> &G,vector<bool> &vis,vector<bool> &seen);
bool dfs(ll now,vector<vector<ll>> &G,vector<bool> &vis,vector<bool> &seen);
int main(){
    ll T;
    cin >> T;
    //cout << "T" << endl;
    while(T--){
        ll N,M;
        cin >> N >> M;
        //cout << "CIN0" << endl;
        vector<vector<ll>> G(N);
        for(ll i=1;i<=M;i++){
            ll u,v;
            cin >> u >> v;
            u--;
            v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        for(ll i=0;i<N;i++){
            G[i].push_back(i);
        }
        //cout << "CIN1" << endl;
        ll W;
        cin >> W;
        vector<string> S(N);
        for(ll i=0;i<N;i++){
            cin >> S[i];
        }
        //cout << "CIN" << endl;
        vector<vector<ll>> H(N*W);
        for(ll i=0;i<W;i++){ //day
            for(ll j=0;j<N;j++){ //vertex
                if(S[j][i]=='o'){
                    for(auto k:G[j]){
                        if(S[k][(i+1)%W]=='o'){
                            H[j+N*i].push_back(k+N*((i+1)%W));
                        }
                    }
                }
            }
        }
        
        //Hにサイクルがあるかを検出する
        vector<bool> vis(N*W,false);
        vector<bool> seen(N*W,false);
        bool f=cycle_find(H,vis,seen);
        if(f){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}
bool cycle_find(vector<vector<ll>> &G,vector<bool> &vis,vector<bool> &seen){
    for(ll i=0;i<(ll)(G.size());i++){
        if(seen[i]){
            continue;
        }
        bool f=dfs(i,G,vis,seen);
        if(f){
            return true;
        }
    }
    return false;
}
bool dfs(ll now,vector<vector<ll>> &G,vector<bool> &vis,vector<bool> &seen){
    vis[now]=true;
    for(auto next:G[now]){
        if(vis[next] && !seen[next]){
            return true;
        }
        if(!vis[next]){
            bool f=dfs(next,G,vis,seen);
            if(f){
                return true;
            }
        }
    }
    seen[now]=true;
    return false;
}