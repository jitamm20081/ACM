#include<iostream>
using namespace std;
int high;
int count;
int a[11];
int main(){
	while(cin>>a[0]){
		count=0;
		for(int i=1;i<10;i++){
			cin>>a[i];
		}
		cin>>high;
		for(int i=0;i<10;i++){
			if(a[i]<=(high+30))
				count++;
		}
		cout<<count<<endl;
	}

}