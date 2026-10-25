#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
using namespace std;
int main(){
    ll N;
    cin >> N;
    vector<ll> V(N);
    for(ll i=0;i<N;i++){
        cin >> V[i];
    }

    //数列Vに対する最長増加部分列の長さを求める
    vector<ll> LIS;
    for(ll i=0;i<N;i++){
        if(LIS.empty()){
            LIS.push_back(V[i]);
            //cout << "push1 " << V[i].second << endl;
        }
        else{
            ll idx=lower_bound(LIS.begin(),LIS.end(),V[i])-LIS.begin();
            if(idx==(ll)(LIS.size())){
                LIS.push_back(V[i]);
                //cout << "push2 " << V[i].second << endl;
            }
            else if(idx==0){
                LIS[0]=V[i];
            }
            else{
                if(LIS[idx-1]<V[i]){
                    //cout << "update " << LIS[idx];
                    LIS[idx]=V[i];
                    //cout << " to " << V[i].second << endl;
                }
            }
        }
    }

    //LISのサイズが解
    cout << (ll)(LIS.size()) << endl;

    return 0;
}