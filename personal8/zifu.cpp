#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;

int main(){
	string s;
	while(cin>>s){
		sort(s.begin(),s.end());
		do{
			cout<<s<<endl;
		}while(next_permutation(s.begin(),s.end()));

	}
}