#include<bits/stdc++.h>
#define ll long long
using namespace std;

//LISを求めたい配列の要素の型
#define S pair<ll,ll>

//LISにおける比較関数
bool cmp(S a,S b){
    return ((a.first<=b.first)&&(a.second<=b.second));
}

int main(){
    //入力
    ll H,W,N;
    cin >> H >> W >> N;
    vector<S> V(N);
    for(ll i=0;i<N;i++){
        cin >> V[i].first >> V[i].second;
        V[i].first--;
        V[i].second--;
    }
    sort(V.begin(),V.end());

    map<S,S> R;

    //数列Vに対する最長増加部分列の長さを求める
    vector<S> LIS;
    for(ll i=0;i<N;i++){
        if(LIS.empty()){
            LIS.push_back(V[i]);
        }
        else{
            ll idx=lower_bound(LIS.begin(),LIS.end(),V[i],cmp)-LIS.begin();
            if(idx==(ll)(LIS.size())){
                LIS.push_back(V[i]);
            }
            else if(idx==0){
                LIS[0]=V[i];
            }
            else{
                if(LIS[idx-1]<V[i]){
                    LIS[idx]=V[i];
                }
            }
            if(idx>0){
                R[V[i]]=LIS[idx-1];
            }
        }
    }

    vector<S> rev;

    S now=LIS.back();
    while(1){
        if(!R.count(now)){
            break;
        }
        rev.push_back(now);
        now=R[now];
    }

    cout << (ll)(rev.size()) << endl;

    for(ll i=(ll)(rev.size())-1;i>=0;i--){
        cout << rev[i].first << " " << rev[i].second << endl;
    }
    cout << endl;

    return 0;
}