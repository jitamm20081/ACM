#include<iostream>
using namespace std;
long long n;
long long a,b,c,d;
int main()
{
	while(cin>>n){
		a = n/2;
		b = n/3;
		c = n/5;
		d = n/7;
		long long x = n/6;
		long long y = n/10;
		long long z = n/14;
		long long k = n/15;
		long long l = n/21;
		long long g = n/35;
		long long x1 = n / 30;
		long long x2 = n / 42;
		long long x3 = n / 105;
		long long x4 = n / 70;
		long long xx = n / 210;
		long long sum =n-a-b-c-d+x+y+z+k+l+g-x1-x2-x3-x4+xx;
		cout<<sum<<endl;n
			
		
	}
		return 0;

}

