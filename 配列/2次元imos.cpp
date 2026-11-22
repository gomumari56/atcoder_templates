//reference: https://github.com/gomumari56/atcoder_templates
//https://atcoder.jp/contests/tessoku-book/submissions/81026200
//imos

#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll H,W,N;
    cin >> H >> W >> N;

    vector<vector<ll>> sum(H,vector<ll>(W,0));

    for(ll i=0;i<N;i++){
        ll a,b,c,d;
        cin >> a >> b >> c >> d;
        a--;
        b--;
        c--;
        d--;
        sum[a][b]++;
        if(d+1<W){
            sum[a][d+1]--;
        }
        if(c+1<H){
            sum[c+1][b]--;
        }
        if(c+1<H && d+1<W){
            sum[c+1][d+1]++;
        }
    }

    for(ll i=0;i<H;i++){
        for(ll j=1;j<W;j++){
            sum[i][j]+=sum[i][j-1];
        }
    }
    for(ll i=1;i<H;i++){
        for(ll j=0;j<W;j++){
            sum[i][j]+=sum[i-1][j];
        }
    }

    for(ll i=0;i<H;i++){
        for(ll j=0;j<W;j++){
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}