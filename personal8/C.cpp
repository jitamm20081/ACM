#include<iostream>
#include<queue>
using namespace std;
priority_queue<int,vector<int>,greater<int>>que;
int n;
int main(){
	int a;
	while(cin>>n){
		while(!que.empty())que.pop();
		for(int i=0;i<n;i++){
			scanf("%d",&a);
			que.push(a);
		}
		int kaixiao=0;
		while(que.size()!=1){
			int c,d;
			c=que.top();
			que.pop();
			d=que.top();
			que.pop();
			kaixiao+=(c+d);
			que.push(c+d);
		}
		cout<<kaixiao<<endl;		
	}

}