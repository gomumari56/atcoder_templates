#include <stdio.h>
int bs(int a[200000],int min,int max,int key);
int bsi(long long ar[200001],int min,int max,long long key);
int bsii(long long ar[],int min,int max,long long key);
int bsiint(int ar[],int min,int max,int key);
int main(){
    int arry[] = {1, 3, 5, 8, 12, 16, 19, 24, 26, 31, 35, 38, 40, 46, 47, 51, 63};
    int ans=bs(arry,0,sizeof(arry)/sizeof(arry[0])-1,8);
    printf("%d\n",ans);
    return 0;
}
//配列aのmin番目からmax番目までの範囲でa[mid]=keyとなるmidを探し、midを返す(ない場合は-1)
int bs(int a[200000],int min,int max,int key){
    int mid;
    int i;
    while(min<=max){
        mid=(min+max)/2;
        if(a[mid]==key){
            return mid;
        }
        else if(a[mid]<key){
            min=mid+1;
        }
        else{
            max=mid-1;
        }
    }
    return -1;
}

//配列arのmin番目からmax番目までの範囲でar[t]<=keyとなる最大のtを返す
int bsi(long long ar[200001],int min,int max,long long key){
    int mid;
    int i;
    while(min<=max){
        mid=(min+max)/2;
        if(ar[mid]==key){
            return mid;
        }
        else if(ar[mid]<key){
            min=mid+1;
        }
        else{
            max=mid-1;
        }
    }
    return min-1;
}

//配列arのmin番目からmax番目までの範囲でar[t]<=keyとなる最大のtを返す
int bsii(long long ar[],int min,int max,long long key){
    int mid,i;
    while(min<=max){
        mid=(min+max)/2;
        if(ar[mid]<=key){
            min=mid+1;
        }
        else{
            max=mid-1;
        }
    }
    return min-1;
}

//配列arのmin番目からmax番目までの範囲でar[t]<=keyとなる最大のtを返す
int bsiint(int ar[],int min,int max,int key){
    int mid,i;
    while(min<=max){
        mid=(min+max)/2;
        if(ar[mid]<=key){
            min=mid+1;
        }
        else{
            max=mid-1;
        }
    }
    return min-1;
}