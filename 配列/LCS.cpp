//https://atcoder.jp/contests/tessoku-book/tasks/tessoku_book_t
//LCS...文字列SとTが与えられます。
//SとTの共通部分列（Sの部分列かつTの部分列）のうち、最長のものは何文字か

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
    cout << dp[SL][TL] << endl;
    return 0;
}