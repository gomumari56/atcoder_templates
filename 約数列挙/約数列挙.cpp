#include<bits/stdc++.h>
#define ll long long
using namespace std;

// 約数列挙
vector<long long> calc_divisor(long long n) {
    vector<long long> res;
    for (long long i = 1LL; i*i <= n; ++i) {
        if (n % i == 0) {
            res.push_back(i);
            long long j = n / i;
            if (j != i) res.push_back(j);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    
    ll N;
    cin >> N;

    auto div=calc_divisor(N);
    
    for(auto p:div){
        cout << p << " ";
    }
    cout << endl;

    return 0;
}