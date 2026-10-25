#include<stdio.h>
int divC(int a);
int main(){
    unsigned long long n,j,count,ans=0;
    scanf("%llu",&n);
    for(j=1;j<=n;j++){
        ans+=(j*(unsigned long long)divC(j));
		//printf("%llu\n",j);
    }
    printf("%llu",ans);
    return 0;
}
int divC(int a){
	int sum=1;
	int div[10][2]={},divcount=0;
	int skip=1;
	while(skip){
		skip=0;
		for(int i=2;i*i<=a;i++){
			if(a%i==0){
				a/=i;
				for(int k=1;k<=divcount+1;k++){
					if(div[k][0]==i){
						div[k][1]++;
						break;
					}
					if(k>divcount){
						divcount++;
						div[k][0]=i;
						div[k][1]++;
						break;
					}
				}
				skip=1;
				break;
			}
		}
	}
	if(a>1){
		for(int k=1;k<=divcount+1;k++){
			if(div[k][0]==a){
				div[k][1]++;
				break;
			}
			if(k>divcount){
				divcount++;
				div[k][0]=a;
				div[k][1]++;
				break;
			}
		}
	}
	for(int i=1;i<=divcount;i++){
		sum*=(div[i][1]+1);
	}
	return sum;
}