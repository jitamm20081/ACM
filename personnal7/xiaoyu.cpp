#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int a,b;
	while(cin>>a>>b){
		int sum=a*10+b;
		int p=19;
		int t;
		t=sum/p;
		cout<<t<<endl;
	}
}