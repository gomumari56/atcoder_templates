#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vector<ll>>
using namespace std;
int main(){
    srand((unsigned int)time(NULL));

    ll N;
    cin >> N;
    vector<pair<ll,ll>> X(N);
    for(ll i=0;i<N;i++){
        cin >> X[i].first >> X[i].second;
    }
    
    for(ll T=0;T<100;T++){
        ll i=0,j=0;
        while(i==j){
            i=rand()%N;
            j=rand()%N;
        }
        ll a=X[i].second-X[j].second;
        ll b=X[j].first-X[i].first;
        ll c=X[i].first*X[j].second-X[j].first*X[i].second;
        ll cnt=0;
        for(ll p=0;p<N;p++){
            if(a*X[p].first+b*X[p].second+c==0){
                cnt++;
            }
        }
        if(cnt>N/2){
            cout << "Yes" << endl;
            cout << a << " " << b << " " << c << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}