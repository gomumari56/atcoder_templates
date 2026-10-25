#include<bits/stdc++.h>
using namespace std;
const int takahashi=0;
const int aoki=1;

#define phase int
map<phase,bool> M;
bool f(phase P);

int main(){
    int P;
    cin >> P;

    bool ans=f(P);
    cout << (bool)ans << endl;

    return 0;
}

bool f(phase P){
    if(M.count(P)){
        return M[P];
    }
    if(P==2){
        M[P]=true;
        return true;
    }
    if(P==0 || P%2==1){
        M[P]=false;
        return false;
    }
    phase Q=P/2;
    if(f(Q)==true){
        M[P]=true;
        return true;
    }
    else{
        M[P]=false;
        return false;
    }
    return 0;
}