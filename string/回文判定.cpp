#include<bits/stdc++.h>
#define ll long long
#define MOD 998244353
using namespace std;
ll K;
bool ch(string S); //Sが回文ならtrue
int main(){
    string S1="ABCBA";
    string S2="ABCBB";
    bool t1=ch(S1);
    bool t2=ch(S2);
    cout << t1 << " " << t2 << endl;
    return 0;
}
bool ch(string S){
    string T=S;
    reverse(T.begin(),T.end());
    if(S==T){
        return true;
    }
    else{
        return false;
    }
    return false;
}