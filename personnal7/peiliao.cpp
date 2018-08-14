#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n;
int count1;
int a[10000][15];
int main(){
	while(cin>>n){
		if(n<10||n>30){
			cout<<"0"<<endl;
			continue;
		}
		count1=0;
		int a1,a2,a3,a4,a5,a6,a7,a8,a9,a10;
		for(a1=1;a1<=3;a1++)
			for(a2=1;a2<=3;a2++)
				for(a3=1;a3<=3;a3++)
					for(a4=1;a4<=3;a4++)
						for(a5=1;a5<=3;a5++)
							for(a6=1;a6<=3;a6++)
								for(a7=1;a7<=3;a7++)
									for(a8=1;a8<=3;a8++)
										for(a9=1;a9<=3;a9++)
											for(a10=1;a10<=3;a10++){
												if(a1+a2+a3+a4+a5+a6+a7+a8+a9+a10==n){
													a[count1][0]=a1,a[count1][1]=a2,a[count1][2]=a3,a[count1][3]=a4,a[count1][4]=a5,a[count1][5]=a6,
													a[count1][6]=a7,a[count1][7]=a8,a[count1][8]=a9,a[count1][9]=a10;													
													count1++;
												}
											}
		printf("%d\n",count1);
		for(int i=0;i<count1;i++)
			printf("%d %d %d %d %d %d %d %d %d %d \n",a[i][0],a[i][1],a[i][2],a[i][3],a[i][4],a[i][5],a[i][6],a[i][7],a[i][8],a[i][9]);


	}
}