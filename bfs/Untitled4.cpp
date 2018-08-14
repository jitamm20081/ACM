#include <cstdio>
#include <iostream>
#include<cstdlib>
using namespace std;
int n,c,a[1001];
int maxx=0;
void search(int,int);
int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
	search(0,1);
	cout<<maxx;
	return 0;
}
void search(int sum,int t)
{
	if(sum>c)
		return ;
	maxx=max(maxx,sum);
	for(int i=t+1;i<=n;i++)
		search(sum+a[i],i);
}

