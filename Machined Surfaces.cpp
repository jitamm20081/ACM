#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
	string s[13];
	int n;
	while(cin>>n){
		getchar();//把回车键读掉 
		if(n==0)break;
		int ant=0,min=26;
		int sum=0;
		for(int i=0;i<n;i++){
			getline(cin,s[i]);//一般的cin是遇到空格停止，getline则是遇到回车键停止 
			ant=count(s[i].begin(),s[i].end(),' ');
			sum+=ant;
			if(ant<min)min=ant;
		}
		cout<<sum-n*min<<endl;
		
	}
	
	
}
