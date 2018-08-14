#include<iostream>
#include<set>
using namespace std;

int main()
{
	set<int>s;
	int n;
	int p;
	while(cin>>p){
		s.insert(p);
	}

	for(set<int>::iterator it=s.begin();it!=s.end();it++){
		cout<<*it<<endl;
	}
}