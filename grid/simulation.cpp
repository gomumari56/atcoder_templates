#include<bits/stdc++.h>
#define ll long long
using namespace std;

int Fj(pair<int,int> K,int H,int W); //grid範囲内かの確認
pair<int,int> Padd(pair<int,int> A,pair<int,int> B); //pair<int,int>各成分を和にする

int main(){
    int H,W,Y;
    cin >> H >> W >> Y;
    int F[1050][1050]={}; //FにH*Wマスの情報を入れる

    for(int i=1;i<=H;i++){
        for(int j=1;j<=W;j++){
            cin >> F[i][j];
        }
    }

    int area=H*W; //残っている面積


    set<tuple<int,int,int>> Q; //海面チェックリスト 高さ,x,y
    set<pair<int,int>> add; //チェックリストに追加したことがあるもののリスト

    //外周の追加
    for(int i=1;i<=H;i++){
        Q.insert({F[i][1],i,1});
        Q.insert({F[i][W],i,W});
        add.insert({i,1});
        add.insert({i,W});
    }
    for(int j=2;j<W;j++){
        Q.insert({F[1][j],1,j});
        Q.insert({F[H][j],H,j});
        add.insert({1,j});
        add.insert({H,j});
    }

    for(int y=1;y<=Y;y++){
        while(1){
            if(Q.empty()){
                break;
            }
            tuple<int,int,int> p=*Q.begin();
            if(get<0>(p)<=y){
                Q.erase(p);

                queue<pair<int,int>> Q2;
                Q2.push({get<1>(p),get<2>(p)});

                while(!Q2.empty()){
                    //queueの先頭を取り出す
                    pair<int,int> X=Q2.front();
                    Q2.pop();
                    //cout << X.first << "," << X.second << "が沈んだ" << endl;
                    area--;

                    pair<int,int> D[4]={{1,0},{-1,0},{0,1},{0,-1}}; //上下左右
                    for(auto k:D){
                        pair<int,int> Y=Padd(X,k); //移動先の座標
                        if(Fj(Y,H,W)){ //gridの範囲内であることを確認
                            if(!add.count(Y)){
                                if(F[Y.first][Y.second]<=y){ //条件式を入れる
                                    //queueに追加
                                    add.insert(Y);
                                    Q2.push(Y);
                                }
                                else{
                                    //海面チェックリストに追加
                                    Q.insert({F[Y.first][Y.second],Y.first,Y.second});
                                    add.insert(Y);
                                }
                            }
                        }
                    }
                }
            }
            else{
                break;
            }
        }

        cout << area << endl;
    }

    return 0;
}
int Fj(pair<int,int> K,int H,int W){
    if(1<=K.first && K.first<=H && 1<=K.second && K.second<=W){
        return 1;
    }
    else{
        return 0;
    }
}
pair<int,int> Padd(pair<int,int> A,pair<int,int> B){
    return {A.first+B.first,A.second+B.second};
}