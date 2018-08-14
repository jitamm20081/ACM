#include <iostream>
#include <cstring>
#include<string>
using namespace std;

int main()
{
	int n;
	string str1[10],str2[10],str3,str4,stro;
	while(cin>>n){
		if(n==0)break;
		getchar();
		for(int i=0;i<n;i++){
			getline(cin,str1[i]);
			getline(cin,str2[i]);
		}
		
		getline(cin,str3);
		int index1=0;
		for(int j=0;j<n;j++){
			index1=str3.find(str1[j]);
			while(index1>=0){
					str3.erase(index1,str1[j].size());
					str3.insert(index1,str2[j]);
				    index1=str3.find(str1[j]);
			}
		}
		cout<<str3<<endl;
	}
}
