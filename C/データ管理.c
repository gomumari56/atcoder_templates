#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int len;
    int *ar;
} Data;

int bsii(int ar[],int min,int max,int key);
void insert(Data *a,int value);

////////////////////////////////////

int main(){
    Data test={.len=0,.ar=(int*)malloc(sizeof(int))};

    int input;
    while(1){
        scanf("%d",&input);
        if(input==-1){
            break;
        }
        else{
            insert(&test,input);
        }
    }

    for(int i=0;i<test.len;i++){
        printf("%d ",test.ar[i]);
    }
    printf("\n");

    return 0;
}

////////////////////////////////////

int bsii(int ar[],int min,int max,int key){
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

void insert(Data *a,int value){
    int ins=bsii(a->ar,0,a->len-1,value)+1;
    a->ar=(int*)realloc(a->ar,sizeof(int)*(a->len));
    for(int i=a->len-1;i>=ins;i--){
        a->ar[i+1]=a->ar[i];
    }
    a->ar[ins]=value;
    a->len++;
}