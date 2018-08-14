#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const double e = 2.71828182845;
const double pi = 3.1415926;
const double  log8_e =log10(e)/log10(8);
#define log8_2pi(x) (log10(2*pi*x)/log10(8.0))/2
#define log8(x) log10(x)/log10(8.0) 
int main(){
	int a;
	int test;
	cin>>test;
	while(test--){
		cin>>a;
		int s;
		if(a==1||a==0){
			cout<<"1\n";
			continue;
		}
		s=(int)(log8_2pi(a)+a*log8(a)-a*log8_e)+1; 
		cout<<s<<endl;
	}

}
