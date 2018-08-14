#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int a,b;
int arr[3000];
int zhengshu;
int yushu;
float xiaoshu;
int n;
int num;
int k=0;//循环节开始的地方
int main(){
	while(cin>>a>>b){
		k=0;
		int i,j;
		zhengshu=a/b;
		cout<<zhengshu<<endl;
		yushu=a%b;
		memset(arr,0,sizeof(arr));

		for(j=0;j<3005;j++){
			num=yushu*10;
			arr[j]=num/b;
			yushu=num%b;
				}
		cout<<zhengshu<<endl;
		/*for(j=0;j<3000;j++){
			cout<<arr[j];1 
				}*/
		int flag;

		while(1){
			for(i=1;i<=b;i++){
				flag=0;
				for(j=0;j<3000-k;j++){
					//cout<<arr[j+k]<<" "<<arr[j%i+k]<<" ";
					//cout<<j+k<<" "<<j%i+k<<" ";
					if(arr[j+k]!=arr[j%i+k]||i==3000){
						flag=1;
						break;
					}
				}
				if(flag==0){
					n=i;
					break;
				}
			}
			//cout<<flag<<"ddd";	
			//cout<<n<<" "<<k<<endl;
			if(flag==0){
				printf("%d.",zhengshu);
				for(i=0;i<k;i++){
					printf("%d",arr[i]);
				}
				printf("(");
				if(n<=50){
					for(i=k;i<k+n;i++){
						printf("%d",arr[i]);
					}
					printf(")\n");				
				}
				else {
					for(i=k;i<k+50;i++){
						printf("%d",arr[i]);
					}
					printf("...)\n");
				}
				printf("%d\n",n);
			}
			if(flag==0)
				break;
			k++;
		}

	}
}
