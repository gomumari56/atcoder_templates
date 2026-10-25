// https://imoz.jp/algorithms/imos_method.html

#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
using namespace std;
ll d[2020][2020]={};
ll d2[2020][2020]={};
int main(){
    ll N;
    cin >> N;

    for(ll i=1;i<=N;i++){
        ll U,D,L,R;
        cin >> U >> D >> L >> R;
        d[U][L]++;
        d[D+1][L]--;
        d[U][R+1]--;
        d[D+1][R+1]++;

        d2[U][L]+=i;
        d2[D+1][L]-=i;
        d2[U][R+1]-=i;
        d2[D+1][R+1]+=i;
    }

    for(ll i=1;i<=2000;i++){
        for(ll j=2;j<=2000;j++){
            d[i][j]=d[i][j-1]+d[i][j];
            d2[i][j]=d2[i][j-1]+d2[i][j];
        }
    }
    for(ll i=2;i<=2000;i++){
        for(ll j=1;j<=2000;j++){
            d[i][j]=d[i-1][j]+d[i][j];
            d2[i][j]=d2[i-1][j]+d2[i][j];
        }
    }

    ll sum[200020]={};
    for(ll i=1;i<=2000;i++){
        for(ll j=1;j<=2000;j++){
            if(d[i][j]==0){
                sum[0]++;
            }
            if(d[i][j]==1){
                sum[d2[i][j]]++;
            }
        }
    }

    for(ll i=1;i<=N;i++){
        cout << sum[0]+sum[i] << endl;
    }

    return 0;
}