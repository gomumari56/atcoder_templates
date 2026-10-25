// 426 - E

#include<bits/stdc++.h>
#define ll long long
using namespace std;

//2点(a,b),(x,y)間の距離^2を求める
double d2(double a,double b,double x,double y){
    return (a-x)*(a-x)+(b-y)*(b-y);
}
//(a,b)と(x,y)を(1-prop):propに内分する点の座標を求める
pair<double,double> internal_division(double a,double b,double x,double y,double prop){
    return {
        (1.0-prop)*a+prop*x,
        (1.0-prop)*b+prop*y
    };
}
void solve(){
    double tsx,tsy,tgx,tgy,asx,asy,agx,agy;
    cin >> tsx >> tsy >> tgx >> tgy;
    cin >> asx >> asy >> agx >> agy;

    double dist2[2]={};
    dist2[0]=d2(tsx,tsy,tgx,tgy);
    dist2[1]=d2(asx,asy,agx,agy);

    if(dist2[0]>dist2[1]){
        swap(tsx,asx);
        swap(tsy,asy);
        swap(tgx,agx);
        swap(tgy,agy);
        swap(dist2[0],dist2[1]);
    }
    
    double prop=sqrt(dist2[0])/sqrt(dist2[1]);
    auto [cx,cy]=internal_division(asx,asy,agx,agy,prop);

    //cout << "Dist2: " << dist2[0] << "," << dist2[1] << endl;
    //cout << "C: " << cx << "," << cy << endl;
    
    double ans2=200000.0;

    //三分探索 前半
    double L=0.0;
    double R=1.0;
    while(R-L>0.000000001){
        double nl=(2.0*L+R)/3.0;
        double nr=(L+2.0*R)/3.0;

        auto [nltx,nlty]=internal_division(tsx,tsy,tgx,tgy,nl);
        auto [nlax,nlay]=internal_division(asx,asy,cx,cy,nl);
        double nl_dist2=d2(nltx,nlty,nlax,nlay);

        auto [nrtx,nrty]=internal_division(tsx,tsy,tgx,tgy,nr);
        auto [nrax,nray]=internal_division(asx,asy,cx,cy,nr);
        double nr_dist2=d2(nrtx,nrty,nrax,nray);

        if(nl_dist2<nr_dist2){
            R=nr;
        }
        else{
            L=nl;
        }
    }
    auto [Ltx,Lty]=internal_division(tsx,tsy,tgx,tgy,L);
    auto [Lax,Lay]=internal_division(asx,asy,cx,cy,L);

    //cout << "pos: " << Ltx << " " << Lty << " " << Lax << " " << Lay << endl;

    ans2=min(ans2,d2(Ltx,Lty,Lax,Lay));

    //cout << "#1 " << fixed << setprecision(15) << d2(Ltx,Lty,Lax,Lay) << endl;
    //cout << "L= " << fixed << setprecision(15) << L << endl;

    //三分探索 後半
    L=0.0;
    R=1.0;
    while(R-L>0.000000001){
        double nl=(2.0*L+R)/3.0;
        double nr=(L+2.0*R)/3.0;

        auto [nlax,nlay]=internal_division(cx,cy,agx,agy,nl);
        double nl_dist2=d2(tgx,tgy,nlax,nlay);

        auto [nrax,nray]=internal_division(cx,cy,agx,agy,nr);
        double nr_dist2=d2(tgx,tgy,nrax,nray);

        if(nl_dist2<nr_dist2){
            R=nr;
        }
        else{
            L=nl;
        }
    }
    auto [LLax,LLay]=internal_division(cx,cy,agx,agy,L);
    ans2=min(ans2,d2(tgx,tgy,LLax,LLay));

    //cout << "#2 " << fixed << setprecision(15) << d2(tgx,tgy,LLax,LLay) << endl;
    //cout << "L= " << fixed << setprecision(15) << L << endl;

    cout << fixed << setprecision(15) << sqrt(ans2) << endl;

    //cout << endl << endl;
}
int main(){
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    ll T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}