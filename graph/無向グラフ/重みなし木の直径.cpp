//reference: https://github.com/gomumari56/atcoder_templates
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N; //木の頂点数
    cin >> N;

    vector<vector<ll>> G(N);

    for(ll i=0;i<N-1;i++){
        ll u,v;
        cin >> u >> v;
        u--; //0-indexed
        v--; //0-indexed
        G[u].push_back(v);
        G[v].push_back(u);
    }

    //直径の端点
    ll p=-1;
    ll q=-1;

    //直径
    ll diam=0;

    //p-qのパス
    vector<ll> path;

    vector<ll> root(N,-1);

    { //直径と、直径の端点を片方求める
        queue<ll> Q;
        vector<bool> vis(N,false);
        Q.push(0);
        vis[0]=true;
        while(!Q.empty()){
            auto now=Q.front();
            Q.pop();
            p=now;
            for(auto next:G[now]){
                if(!vis[next]){
                    Q.push(next);
                    vis[next]=true;
                }
            }
        }
    }

    { //もう一つの端点を求める
        queue<ll> Q;
        vector<ll> vis(N,-1);
        Q.push(p);
        vis[p]=0;
        while(!Q.empty()){
            auto now=Q.front();
            Q.pop();
            q=now;
            diam=max(diam,vis[now]);
            for(auto next:G[now]){
                if(vis[next]==-1){
                    Q.push(next);
                    vis[next]=vis[now]+1;
                    root[next]=now;
                }
            }
        }
    }

    { //2点間のパスを求める
        path.push_back(q);
        ll now=q;
        while(1){
            if(root[now]==-1){
                break;
            }
            now=root[now];
            path.push_back(now);
        }
    }

    cout << "diam = " << diam << endl;

    for(auto e:path){
        cout << e << " ";
    }
    cout << endl;

    return 0;
}