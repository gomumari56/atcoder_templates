#include<bits/stdc++.h>
#include<atcoder/all>
#define ll long long
using namespace std;
using namespace atcoder;
using mint = atcoder::modint998244353;

template<typename T,typename F>
T POW(T id,T a,ll K,F op){}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vvem A={{(mint)10,(mint)1},{(mint)0,(mint)1}};
    vvem id={{(mint)1,(mint)0},{(mint)0,(mint)1}};
    auto mul=[&](vvem a,vvem b){
        vvem res={{(mint)0,(mint)0},{(mint)0,(mint)0}};
        rep(j,0,2){
            rep(k,0,2){
                rep(l,0,2){
                    res[j][l]+=a[j][k]*b[k][l];
                }
            }
        }
        return res;
    };
    POW(id,A,y,mul);

    return 0;
}