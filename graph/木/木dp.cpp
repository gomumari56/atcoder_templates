//reference: https://github.com/gomumari56/atcoder_templates

//木dp
//ABC 378 - F

#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ans=0;

void f(ll now,ll prev,vector<vector<ll>>& G,vector<ll>& deg,vector<ll>& dp){
    for(auto next:G[now]){
        if(next!=prev){
            f(next,now,G,deg,dp);
        }
    }
    if(deg[now]==2){
        for(auto next:G[now]){
            if(next!=prev){
                if(deg[next]==3){
                    ans+=dp[next];
                }
            }
        }
        dp[now]=1;
    }
    else if(deg[now]==3){
        ll cnt=0;
        ll d=0;
        for(auto next:G[now]){
            if(next!=prev){
                cnt+=dp[next];
                d+=(dp[next]*(dp[next]-1))/2;
            }
        }
        ans+=(cnt*(cnt-1))/2-d;
        dp[now]=cnt;
    }
    else{
        dp[now]=0;
    }
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    vector<ll> dp(N,0LL),deg(N,0LL);
    vector<vector<ll>> G(N);

    for(ll i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
        deg[a]++;
        deg[b]++;
    }

    //deg が 2-3-3-3-3-3-2 となるようなパスの個数を求める
    //(3を1個以上含む)

    f(0,-1,G,deg,dp);

    cout << ans << endl;

    return 0;
}