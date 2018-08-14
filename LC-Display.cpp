#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const char Inpart[10][8]={
	"1110111",//0
	"0010010",//1
	"1011101",//2
	"1011011",//3
	"0111010",//4
	"1101011",//5
	"1101111",//6
	"1010010",//7
	"1111111",//8
	"1111011",//9
};

char Ingood[2*10+3+5][8*(10+3+9)+5];

void print(int pos,int len1,int num){
	//horizontal
	for(int i=1;i<=len1;i++){
		if(Inpart[num][0]=='1'){
			Ingood[0][pos+i]='-';
		}
		if(Inpart[num][3]=='1'){
			Ingood[len1+1][pos+i]='-';
		}
		if(Inpart[num][6]=='1'){
			Ingood[2*len1+2][pos+i]='-';
		}
	}
	//vertical
	for(int j=1;j<=len1;j++){
		if(Inpart[num][1]=='1'){
			Ingood[j][pos]='|';
		}
		if(Inpart[num][2]=='1'){
			Ingood[j][pos+len1+1]='|';
		}
		if(Inpart[num][4]=='1'){
			Ingood[j+len1+1][pos]='|';
		}
		if(Inpart[num][5]=='1'){
			Ingood[j+len1+1][pos+len1+1]='|';
		}
	}
	
}

int main(){
	char num[15];
	int row,col,length;
	while(scanf("%d %s",&length,num)){
		int len=strlen(num);
		if(length==0&&num[0]=='0'&&len==1)break;
		int i,j;
		row=2*length+3;
		col=(length+3)*len-1;
		for(i=0;i<row;i++){
			for(j=0;j<col;j++){
				Ingood[i][j]=' ';
			}
		}

		for(i=0;i<len;i++){
			print(i*(length+3),length,num[i]-'0');
		}
		for(int i=0;i<row;i++){
			Ingood[i][col]='\0';
			printf("%s\n",Ingood[i]);
		}
		cout<<endl;
	}
	
}
