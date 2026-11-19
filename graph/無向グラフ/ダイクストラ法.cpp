//reference: https://github.com/gomumari56/atcoder_templates
#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N,M; //N頂点,M辺のグラフ
    cin >> N >> M;
    ll s=1,g=-1; //sからgへの最短距離を求める
    vector<vector<pair<ll,ll>>> G(N); //グラフの情報
    //行き先は、{cost,vertex}の形式

    for(ll i=0;i<M;i++){
        ll a,b,c; //aからbへのコストcの辺
        cin >> a >> b >> c;
        a--;
        b--;
        G[a].push_back({c,b});
        G[b].push_back({c,a}); //無向グラフの場合のみ
    }

    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<pair<ll,ll>>> Q; //優先度付きqueue
    vector<bool> vi(N,false); //調査済みのリスト
    vector<ll> dist(N,LLONG_MAX); //sからの最短距離 //minを求めたいので初期値は大きくする
    dist[s]=0; //sからsの最短距離は0

    //開始地点の追加
    Q.push({0,s});

    //優先度付きキューも{cost,vertex}の形式を持つ

    while(!Q.empty()){
        ll X=Q.top().second;
        Q.pop();

        if(vi.at(X)==true){ //すでに調査済みであればcontinue
            continue;
        }
        vi.at(X)=true;

        if(X==g){ //目的地までの最短距離が確定すれば終了
            break;
        }

        for(auto k:G[X]){
            dist[k.second]=min(dist[k.second],dist[X]+k.first);
            if(vi.at(k.second)==false){
                Q.push({dist[k.second],k.second});
            }
        }
    }

    for(ll i=0;i<N;i++){
        if(dist[i]==LLONG_MAX){ //到達不可能な場合-1
            cout << -1 << endl;
        }
        else{
            cout << dist[i] << endl;
        }
    }

    return 0;
}