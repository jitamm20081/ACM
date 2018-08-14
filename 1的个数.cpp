#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a;
	int count1;
	while(cin>>a){
		for(count1=0;a;++count1)
		a&=(a-1);
		cout<<count1<<endl;
	}

	
}
