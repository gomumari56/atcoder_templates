#include<bits/stdc++.h>
#define ll long long
#define vll vector<ll>
#define vvll vector<vll>
using namespace std;
ll dx[4]={-1,1,0,0};
ll dy[4]={0,0,-1,1};
int main(){
    ll H,W;
    cin >> H >> W;
    vector<vector<ll>> F(H,vector<ll>(W));
    pair<ll,ll> S,G;
    for(ll i=0;i<H;i++){
        string str;
        cin >> str;
        for(ll j=0;j<W;j++){
            if(str[j]=='#'){
                F[i][j]=1;
            }
            if(str[j]=='s'){
                S={i,j};
            }
            if(str[j]=='g'){
                G={i,j};
            }
        }
    }
    vector<vector<bool>> vis(H,vector<bool>(W));
    queue<pair<ll,ll>> Q;
    Q.push(S);
    vis[S.first][S.second]=true;
    bool goal=false;
    while(!Q.empty()){
        auto [x,y]=Q.front();
        Q.pop();
        for(ll i=0;i<4;i++){
            ll nx=x+dx[i];
            ll ny=y+dy[i];
            if(0<=nx && nx<H && 0<=ny && ny<W){
                if(!vis[nx][ny] && F[nx][ny]==0){
                    Q.push({nx,ny});
                    vis[nx][ny]=true;
                    if(nx==G.first && ny==G.second){
                        goal=true;
                    }
                }
            }
        }
    }
    if(goal){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}