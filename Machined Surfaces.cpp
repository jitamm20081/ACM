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
		getchar();//�ѻس������� 
		if(n==0)break;
		int ant=0,min=26;
		int sum=0;
		for(int i=0;i<n;i++){
			getline(cin,s[i]);//һ���cin�������ո�ֹͣ��getline���������س���ֹͣ 
			ant=count(s[i].begin(),s[i].end(),' ');
			sum+=ant;
			if(ant<min)min=ant;
		}
		cout<<sum-n*min<<endl;
		
	}
	
	
}
