#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    int N;
    cin >> N;
    for(int i=2;i<=N;i++){
        int f=1;
        for(int j=2;j*j<=i;j++){
            if(i%j==0){
                f=0;
                break;
            }
        }
        if(f){
            cout << i << " ";
        }
    }
    cout << endl;

    return 0;
}