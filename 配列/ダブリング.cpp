#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define NMAX 200020

ll N,K;
vector<ll> KBIT; //Kを2進数にしたとき1である位のリスト
ll MOVE[NMAX]={}; //MOVE[j] jから1回の遷移でどこへ行くか
ll DDP[70][NMAX]={}; //DDP[i][j] jから2^i回の遷移でどこへ行くか
void KBIT_FILL(); //KBITを計算
void DDP_FILL(); //DDPを計算
ll DDP_MOVE(ll P); //DDP_MOVE(P) PからK回の遷移でどこへ行くか

int main(){
    cin >> N >> K;
    ll A[NMAX]={};
    for(ll i=1;i<=N;i++){
        cin >> MOVE[i];
    }
    for(ll i=1;i<=N;i++){
        cin >> A[i];
    }

    KBIT_FILL();
    DDP_FILL();

    for(ll i=1;i<=N;i++){
        cout << (A[DDP_MOVE(i)]) << " ";
    }
    cout << endl;
    
    return 0;
}

void KBIT_FILL(){
    ll t=0;
    ll k=K;
    while(k){
        if(k%2==1){
            KBIT.push_back(t);
        }
        k/=2;
        t++;
    }
}
void DDP_FILL(){
    for(ll j=1;j<=N;j++){
        DDP[0][j]=MOVE[j];
    }
    for(ll i=1;i<=65;i++){
        for(ll j=1;j<=N;j++){
            DDP[i][j]=DDP[i-1][DDP[i-1][j]];
        }
    }
}
ll DDP_MOVE(ll P){
    for(ll j=0;j<(ll)(KBIT.size());j++){
        P=DDP[KBIT[j]][P];
    }
    return P;
}