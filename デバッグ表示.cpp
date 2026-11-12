//reference: https://github.com/gomumari56/atcoder_templates
#include<bits/stdc++.h>
#define ll long long
using namespace std;

template<typename T>
void out(const T &X, ostream &os = cout){
    if constexpr(requires{X.begin();X.end();}){
        for(auto it=X.begin();it!=X.end();it++) out(*it, os);
        os << "\n";
    }else if constexpr(requires(T t){t.pop();t.size();}){
        T x=X;
        while(x.size()){
            if constexpr(requires{x.top();}){
                out(x.top(), os);
                x.pop();
            }else{
                out(x.front(), os);
                x.pop();
            }
        }
        os << "\n";
    }else{
        if constexpr(requires(T t){t.first;}){
            out(X.first, os);
            out(X.second, os);
            os << "\n";
        }else{
            os << X << " ";
        }
    }
}

#define debug(x) cerr << #x << " = ", out(x, cerr)

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<pair<ll,ll>> A(5,{1,2});

    debug(A);
    
    return 0;
}