#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<bool> P(N+1,true);
    P[1]=false;
    for(int i=2;i<=N/2;i++){
        if(P[i]==false){
            continue;
        }
        for(int j=2*i;j<=N;j+=i){
            P[j]=false;
        }
    }
    for(int i=2;i<=N;i++){
        if(P[i]==true){
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}