//https://atcoder.jp/contests/dp/tasks/dp_f
//LCS...文字列SとTが与えられます。
//SとTの共通部分列（Sの部分列かつTの部分列）のうち、最長のものを求める

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    string S,T;
    cin >> S;
    cin >> T;
    ll SL=(ll)(S.size());
    ll TL=(ll)(T.size());
    vector<vector<ll>> dp(SL+1,vector<ll>(TL+1,0));
    for(ll i=1;i<=SL;i++){
        for(ll j=1;j<=TL;j++){
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(S[i-1]==T[j-1]){
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
            }
        }
    }
    pair<ll,ll> now={SL,TL};
    string ans;
    while(now.first>0 && now.second>0){
        if(dp[now.first-1][now.second]==dp[now.first][now.second]){
            now.first--;
        }
        else if(dp[now.first][now.second-1]==dp[now.first][now.second]){
            now.second--;
        }
        else{
            ans+=S[now.first-1];
            now.first--;
            now.second--;
        }
    }
    reverse(ans.begin(),ans.end());
    cout << ans << endl;
    return 0;
}