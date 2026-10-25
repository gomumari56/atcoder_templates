#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;
int main(){
    int N,Q;
    cin >> N >> Q;
    dsu d(N);
    for(int i=1;i<=Q;i++){
        int t,u,v;
        cin >> t >> u >> v;
        if(t==0){
            d.merge(u,v);
        }
        else{ //t==1
            cout << d.same(u,v) << endl;
        }
    }
    return 0;
}