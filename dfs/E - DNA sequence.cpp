#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
char C[4]={'A','C','G','T'};
struct node{
	int length;
	char dna[10];
}a[10];
int pos[10];
int n;
int deep;

int colmax(){
	int max1=0;
	for(int i=0;i<n;i++){
		max1=max(max1,a[i].length-pos[i]);
	}
	return max1;
}


bool dfs(int k){
	int Max=colmax();
	if(k+Max>deep)return false;
	if(Max==0)return true;
	for(int i=0;i<4;i++){
		int tmp[10];
		int flag=0;
		for(int j=0;j<n;j++){
			tmp[j]=pos[j];
		}

		for(int j=0;j<n;j++){
			if(a[j].dna[pos[j]]==C[i]){
				flag=1;
				pos[j]++;
			}	
		}

		if(flag){
			if(dfs(k+1))return true;
			else{
				for(int j=0;j<n;j++){
					pos[j]=tmp[j];
				}
			}
		}

	}
	return false;
}


int main(){
	int test;
	cin>>test;
	while(test--){
		cin>>n;
		int Max=0;
		for(int i=0;i<n;i++){
			scanf("%s",a[i].dna);
			pos[i]=0;
			a[i].length=strlen(a[i].dna);
			Max=max(Max,a[i].length);
		}	
		deep=Max;
		while(1){
			if(dfs(0))break;
			deep++;
		}
		printf("%d\n",deep);
	}
}