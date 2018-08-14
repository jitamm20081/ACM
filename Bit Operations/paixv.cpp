#include<iostream>
#include<bitset>
#define MAX 1000010
using namespace std;
int main(){
    int length=0;
    int a;
    bitset<MAX>bit_map;
    bit_map.reset();
    while(~scanf("%d",&a)){
        bit_map.set(a);
    }
    for(int j=0;j<MAX;j++){
        if(bit_map[j]==1){
            printf("%d\n",j);
        }
    }

}