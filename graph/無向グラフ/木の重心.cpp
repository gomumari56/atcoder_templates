// abc 362 - F
// 木の重心...その頂点を取り除いてできる全ての部分木の頂点数がN/2以下になるような頂点

#include<bits/stdc++.h>
#define ll long long
using namespace std;
vector<vector<ll>> G(200020);
ll dp[200020]={};
vector<ll> root(200020,-1);
vector<ll> V;

//木dp : ある頂点を根として、各頂点に対して、その頂点を根とする部分木の超点数を求める
ll tree_dp(ll now,ll parent){
    root[now]=parent;
    dp[now]=1;
    for(auto next:G[now]){
        if(next!=parent){
            dp[now]+=tree_dp(next,now);
        }
    }
    return dp[now];
}
// void v_set(ll now,ll parent){
//     for(auto next:G[now]){
//         if(next!=parent){
//             v_set(next,now);
//         }
//     }
//     V.push_back(now);
// }
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll N;
    cin >> N;
    for(ll i=1;i<=N-1;i++){
        ll u,v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    tree_dp(0,-1);

    //重心の列挙
    for(ll i=0;i<N;i++){
        if(N-dp[i]<=N/2){
            bool f=true;
            for(auto p:G[i]){
                if(p!=root[i]){
                    if(dp[p]>N/2){
                        f=false;
                        break;
                    }
                }
            }
            if(f){
                cout << i << " ";
                break;
            }
        }
    }
    cout << endl;

    // v_set(g,-1);

    // ll L=(ll)(V.size());

    // if(L%2!=0){
    //     V.pop_back();
    //     L--;
    // }
    // for(ll i=0;i<L/2;i++){
    //     cout << V[i]+1 << " " << V[i+L/2]+1 << endl;
    // }

    return 0;
}