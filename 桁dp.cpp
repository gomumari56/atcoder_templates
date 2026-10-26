//reference: https://github.com/gomumari56/atcoder_templates

//考え方の参考: https://torus711.hatenablog.com/entry/20150423/1429794075#f-d8dbd02d
//考え方の参考: https://drken1215.hatenablog.com/entry/2019/02/04/013700
//考え方の参考: https://qiita.com/pinokions009/items/1e98252718eeeeb5c9ab

#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;
using mint = atcoder::modint998244353;
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    string N;
    cin >> N;

    ll L=(ll)(N.size());

    //N以下の非負整数の個数を求める

    mint dp[L+1][2]={};
    //dp[i][j]...上からi桁決まってて、jはNより小さいかどうかのbool

    // 2番目の変数はN未満かどうかの変数
    // N未満なら1

    dp[0][1]=(mint)0;
    dp[0][0]=(mint)1;

    //上の桁から順に決めていくことを考える
    for(ll i=0;i<L;i++){
        { //0
            for(ll k=0;k<(N[i]-'0');k++){
                dp[i+1][1]+=dp[i][0];
            }
            dp[i+1][0]+=dp[i][0];
        }
        { //1
            for(ll k=0;k<10;k++){
                dp[i+1][1]+=dp[i][1];
            }
        }
    }

    cout << dp[L][0].val()+dp[L][1].val() << endl;

    return 0;
}