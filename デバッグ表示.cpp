//reference: https://github.com/gomumari56/atcoder_templates
#include<bits/stdc++.h>
#define ll long long
using namespace std;

//↓の範囲を使う
/////////////////////////////////////////////////
template<typename T>
void OUT(const T &X, ostream &os = cout){
    if constexpr(requires{X.begin();X.end();}){
        for(auto it=X.begin();it!=X.end();it++) OUT(*it, os);
        os << "\n";
    }else if constexpr(requires(T t){t.pop();t.size();}){
        T x=X;
        while(x.size()){
            if constexpr(requires{x.top();}){
                OUT(x.top(), os);
                x.pop();
            }else{
                OUT(x.front(), os);
                x.pop();
            }
        }
        os << "\n";
    }else{
        if constexpr(requires(T t){t.first;}){
            OUT(X.first, os);
            OUT(X.second, os);
            os << "\n";
        }else{
            os << X << " ";
        }
    }
}
#define debug(x) cerr << endl << #x << ":" << endl, OUT(x, cerr), cout << endl
/////////////////////////////////////////////////


int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<pair<ll,ll>> A(5,{1,2});

    debug(A);
    
    return 0;
}