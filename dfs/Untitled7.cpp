#include <bits/stdc++.h>
using namespace std;

int a[20],ans=0;
bool vis[20];

bool judge(int u){  //剪枝函数，当u= 3 6 9 12的时候判断是否满足条件，不满足话就不会继续往下搜索 
	if(u==3){  //判断第一个式子 
		if(a[0]+a[1]==a[2])
			return true;
		return false;
	}
	if(u==6){  //第二个式子
		if(a[3]-a[4]==a[5])
			return true;
		return false;
	}
	if(u==9){  //第三个式子 
		if(a[6]*a[7]==a[8])
			return true;
		return false;
	}
	if(u==12){  //第四个式子，如果满足的话cnt++ 
		if(a[11]*a[10]==a[9]){
			ans++;
			return true;
		}	
		return false;
	}
	return false;
}
void dfs(int u){
	if(u==3||u==6||u==9||u==12){  //回溯里剪枝 如果有一个不满足的话 直接退出 
		if(!judge(u))
		return;
	}	
	if(u==12)return;  //当前面都成立 并且前12个数都找到了 结束DFS 
	for(int i=1;i<=13;i++){
		if(!vis[i]){
			a[u]=i;
			vis[i]=true;
			dfs(u+1);
			vis[i]=false;
		}
	}
}
int main(){
	dfs(0);
	cout<<ans<<endl;
	return 0;	
}
