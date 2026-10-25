#include<stdio.h>
#include<stdlib.h>
void merge(int ar[],int left,int mid,int right);
void msort(int ar[],int left,int right);
int main(){
    int a[10]={9,8,7,6,5,4,3,2,1,0};
    msort(a,0,9);
    for(int i=0;i<10;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
void merge(int ar[],int left,int mid,int right){
    int i=left;
    int j=mid;
    int k=0;
    int l;
    int *s;
    s=(int*)calloc(right-left+1,sizeof(int));
    while(i<mid && j<right){
        if(ar[i]<=ar[j]){
            s[k++]=ar[i++];
        }else{
            s[k++]=ar[j++];
        }
    }
    if(i==mid){ /* i側のarをsに移動し尽くしたので、j側も順番にsに入れていく */
        while(j<right){
            s[k++]=ar[j++];
        }
    }else{
        while(i<mid){ /* j側のarをsに移動し尽くしたので、i側も順番にsに入れていく */
            s[k++]=ar[i++];
        }
    }
    for(l=0;l<k;l++){
        ar[left+l]=s[l];
    }
    free(s);
}
void msort(int ar[],int left,int right){
    int mid;
    if(left==right || left==right-1){
        return;
    }
    mid=(left+right)/2;
    msort(ar,left,mid);
    msort(ar,mid,right);
    merge(ar,left,mid,right);
}