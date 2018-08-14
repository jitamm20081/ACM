#include<iostream>
#include<string>
#include<cstdio>
using namespace std;

string add(string str1,string str2){
	string str3;
	int i,j;
	int lenstr1=str1.length();
	int lenstr2=str2.length();
	if(lenstr1>lenstr2){
		for(i=0;i<lenstr1-lenstr2;i++)
			str2='0'+str2;
	}	
	else
	{
		for(i=0;i<lenstr2-lenstr1;i++)
			str1='0'+str1;		
	}
	int len1=str1.length();
	int jinwei=0,temp;
	for(i=len1-1;i>=0;i--){
		temp=str1[i]-'0'+str2[i]-'0'+jinwei;
		if(temp>=10)
			jinwei=1;
		else
			jinwei=0;		
		str3=char(temp%10+'0')+str3;

	}
	if(jinwei==1) str3='1'+str3;
	return str3; 
} 


int main(){
	string str1;
	string sum="0";
	while(cin>>str1){
			if(str1=="0")
				break;
			else{
				sum=add(sum,str1);
			}	
		}
	cout<<sum<<endl;
	return 0;
}
