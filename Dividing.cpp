#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	int i;
	int flag=1;
	int pack[7];

	while(cin>>pack[0]>>pack[1]>>pack[2]>>pack[3]>>pack[4]>>pack[5]){
		if(pack[0]==0&&pack[1]==0&&pack[2]==0&&pack[3]==0&&pack[4]==0&&pack[5]==0)
			break;
		int sum=0;
		printf("Collection #%d:\n",flag);
		flag++;
		for(i=0;i<6;i++){
			sum+=(pack[i]*(i+1));
		}
		if(sum%2){
			printf("Can't be divided.\n\n");
			continue;
		}
		
		vector<int>s;
		for(i=0;i<6;i++){
			int c=1;
			int k=pack[i];
			while(k-c>0){
				k-=c;
				s.push_back(c*(i+1));
				c*=2;
			}
			if(k!=0){
				s.push_back(k*(i+1));
			}
		}
		int dp[250050];	
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		for(i=0;i<s.size();i++){
			for(int j=sum/2;j>=s[i];j--)
			{
				if(dp[j-s[i]])
					dp[j]=1;
			}
		}
		printf(dp[sum/2]?"Can be divided.\n\n":"Can't be divided.\n\n");
	}
	
} 
