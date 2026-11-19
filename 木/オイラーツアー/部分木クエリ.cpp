//reference: https://github.com/gomumari56/atcoder_templates

//参考: https://info.atcoder.jp/entry/algorithm_lectures/euler_tour_technique

#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;

//segtreeモノイドの定義
#define S ll
ll op(ll a,ll b){
    return a+b;
}
ll e(){
    return 0LL;
}

void et(ll now,ll prev,vector<vector<ll>>& G,vector<ll>& V,vector<ll>& in,vector<ll>& out){
    in[now]=(ll)(V.size());
    V.push_back(now);
    for(auto next:G[now]){
        if(next!=prev){
            et(next,now,G,V,in,out);
            V.push_back(now);
        }
    }
    out[now]=(ll)(V.size())-1;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    vector<vector<ll>> G(N);
    for(ll i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    //Vがオイラーツアー(通った頂点列)
    vector<ll> V,in(N),out(N);
    et(0,-1,G,V,in,out);

    //Vは長さ2*N-1なので対応するsegtreeも長さ2*N-1にする
    segtree<S,op,e> seg(2*N-1);

    //初期値を1にする(入力で与えられる場合もある)
    for(ll i=0;i<N;i++){
        seg.set(in[i],1);
    }

    ll Q;
    cin >> Q;
    while(Q--){
        ll t;
        cin >> t;
        //頂点vの重みをx加える
        if(t==0){
            ll v,x;
            cin >> v >> x;
            v--;
            seg.set(in[v],seg.get(in[v])+x);
        }
        //頂点vの部分木に含まれる頂点の重みの総和
        if(t==1){
            ll v;
            cin >> v;
            v--;
            cout << seg.prod(in[v],out[v]+1) << endl;
        }
    }

    return 0;
}