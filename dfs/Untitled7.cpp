#include <bits/stdc++.h>
using namespace std;

int a[20],ans=0;
bool vis[20];

bool judge(int u){  //��֦��������u= 3 6 9 12��ʱ���ж��Ƿ����������������㻰�Ͳ�������������� 
	if(u==3){  //�жϵ�һ��ʽ�� 
		if(a[0]+a[1]==a[2])
			return true;
		return false;
	}
	if(u==6){  //�ڶ���ʽ��
		if(a[3]-a[4]==a[5])
			return true;
		return false;
	}
	if(u==9){  //������ʽ�� 
		if(a[6]*a[7]==a[8])
			return true;
		return false;
	}
	if(u==12){  //���ĸ�ʽ�ӣ��������Ļ�cnt++ 
		if(a[11]*a[10]==a[9]){
			ans++;
			return true;
		}	
		return false;
	}
	return false;
}
void dfs(int u){
	if(u==3||u==6||u==9||u==12){  //�������֦ �����һ��������Ļ� ֱ���˳� 
		if(!judge(u))
		return;
	}	
	if(u==12)return;  //��ǰ�涼���� ����ǰ12�������ҵ��� ����DFS 
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
