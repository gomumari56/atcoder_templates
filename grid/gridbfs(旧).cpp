#include<bits/stdc++.h>
using namespace std;

int Fj(pair<int,int> K,int H,int W); //grid範囲内かの確認
pair<int,int> Padd(pair<int,int> A,pair<int,int> B); //pair<int,int>各成分を和にする

int main(){
    int H,W;
    cin >> H >> W;
    int F[550][550]={}; //FにH*Wマスの情報を入れる

    queue<pair<int,int>> Q; //queue
    bool add[550][550]={}; //queueに追加したことがあるもののリスト

    //開始地点の追加
    Q.push({1,1});
    add[1][1]=true;

    while(!Q.empty()){
        //queueの先頭を取り出す
        pair<int,int> X=Q.front();
        Q.pop();

        pair<int,int> D[4]={{1,0},{-1,0},{0,1},{0,-1}}; //上下左右
        for(auto k:D){
            pair<int,int> Y=Padd(X,k); //移動先の座標
            if(Fj(Y,H,W)){ //gridの範囲内であることを確認
                if(add[Y.first][Y.second]==false){
                    if(1){ //条件式を入れる
                        //queueに追加
                        add[Y.first][Y.second]=true;
                        Q.push(Y);
                    }
                }
            }
        }
    }

    cout << "結果" << endl;

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