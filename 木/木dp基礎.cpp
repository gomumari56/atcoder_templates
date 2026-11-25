//reference: https://github.com/gomumari56/atcoder_templates
//https://atcoder.jp/contests/tessoku-book/submissions/81075163

//木dp
//自分の子孫の個数を求める

#include<bits/stdc++.h>
#define ll long long
using namespace std;

void f(ll now,vector<vector<ll>>& G,vector<ll>& dp){
    dp[now]=0;
    for(auto next:G[now]){
        f(next,G,dp);
        dp[now]+=dp[next]+1;
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    vector<vector<ll>> G(N);
    vector<ll> dp(N);

    for(ll i=1;i<N;i++){
        ll a;
        cin >> a;
        a--;
        G[a].push_back(i);
    }

    f(0,G,dp);

    for(ll i=0;i<N;i++){
        cout << dp[i] << " ";
    }
    cout << endl;

    return 0;
}