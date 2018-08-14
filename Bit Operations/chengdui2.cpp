#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

void count(vector<long long>&arr,long long *ret1,long long *ret2){
	long long num=0;
	int key=0;
	for(int i=0;i<arr.size();i++){
		num^=arr[i];
	}

	for(int i=0;i<64;i++){
		if((num>>i)&1==1){
			break;
		}
		else 
			key++;
	}


	for(int i=0;i<arr.size();i++){
		if((arr[i]>>key)&1==1){
			*ret1^=arr[i];
		}
		else 
			*ret2^=arr[i];
	}



}



int main(){
	long long  ret1,ret2;
	vector<long long>arr;
	long long a;
	while(~scanf("%lld",&a)){
		arr.push_back(a);
	}

	ret1=0;
	ret2=0;
	count(arr,&ret1,&ret2);
	if(ret1>ret2){
		swap(ret1,ret2);
	}
	printf("%d %d\n",ret1,ret2);



}