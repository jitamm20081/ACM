#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<unordered_set>
#include<cstring>
using namespace std;

void zifuchuan(int k,string str,vector<string>&ans){
	if(k==str.size()-1){
		ans.push_back(str);
		return;
	}
	unordered_set<char>us;
	sort(str.begin()+k,str.end());
	for(int i=k;i<str.size();i++){
		if(us.find(str[i])==us.end()){
			us.insert(str[i]);
			swap(str[k],str[i]);
			zifuchuan(k+1,str,ans);
			swap(str[k],str[i]);
		}
	}

}


int main(){
	string str;
	while(cin>>str){
		vector<string>ans;
		zifuchuan(0,str,ans);
		for(vector<string>::iterator it=ans.begin();it<ans.end();it++)
			cout<<*it<<endl;	
	}

}