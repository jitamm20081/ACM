#include<stdio.h>
struct Deck{
    int v;//数字
    char s;//花色
};
struct Poker{
    Deck d[5];
    int type,l;
    int print(){
        for(l=0;l<5;l++)
            printf("%d %c\n",d[l].v,d[l].s);
    }
};

int  ChangeValue(char a){
    int value;
    switch(a){
        case 'T':value=10;break;
        case 'J':value=11;break;
        case 'Q':value=12;break;
        case 'K':value=13;break;
        case 'A':value=14;break;
        default: value=a-'0';break;
    }
    return value;
}

int RecognizeType(Poker order){
    int a[5],b[5]={0},i,j=0;
    for(i=0;i<5;i++){
        a[i]=order.d[i].v;
    }
    for(j=0;j<5;j++){
        for(i=0;i<5;i++){
            if(a[j]==order.d[i].v)
                b[j]++;
        }
    }
    int two=0,three=0,four=0,flag=0;
    for(j=0;j<5;j++){
        if(b[j]==2)
            two++;
        if(b[j]==3)
            three++;
        if(b[j]==4)
            four++;
    }
    if(two==0&&three==0&&four==0){//无序
        for(i=0;i<4;i++){
            if((a[i]+1)!=a[i+1])
                flag=1;
        }
        if(flag==1){
            order.type=1;
        }
        if(flag==0){
            order.type=5;
        }
    }
    if(two==1&&three==0&&four==0){//一对
        order.type=2;
    }
    if(two==2){//两对
        order.type=3;
    }
    if(two==0&&three==1){
        order.type=4;
    }
    if(two==1&&three==1){
        order.type==7;
    }
    if(four==1){
        order.type==8;
    }
    return order.type;
}
int judgement(Poker black,Poker white){
    int i,j;
    int black1=0,white1=1,tie=2;
    Deck temp;
    for(i=0;i<4;i++){
        for(j=0;j<4-i;j++){
            if(black.d[j].v<black.d[j+1].v){
                temp = black.d[j];
                black.d[j]=black.d[j+1];
                black.d[j+1]=temp;
            }
        }
    }
    for(i=0;i<5;i++){
        for(j=0;j<5-i;j++){
            if(white.d[j].v<white.d[j+1].v){
                temp= white.d[j];
                white.d[j]=white.d[j+1];
                white.d[j+1]=temp;
            }
        }
    }
    int bcount2=0,wcount2=0;//2计数器
    for(i=0;i<5;i++){
        if(black.d[i].v==2)
            bcount2++;
        if(white.d[i].v==2)
            wcount2++;
    }
    if(black.type!=white.type){
        for(i=0;i<5;i++){
            if(wcount2<bcount2)
                return black;
            if(wcount2<bcount2)
                return white;
            if(wcount2==bcount2)
            {
                if(black.d[i].v>white.d[i].v)
                    return black;
                if(black.d[i].v==white.d[i].v)
                {
                    if(i==4)
                        return tie;
                    else continue;
                }
                if(black.d[i].v<white.d[i].v)
                    return white;
            }

        }
    }
    int o,p;
    int arr[3],brr[3],k=0,t=0;
    if(black.type==white.type&&black.type==2){
        for(i=0;i<5;i++){
            if(black.d[i].v==black.d[i+1].v)
                o=i;
            if(white.d[i].v==white.d[i+1].v)
                p=i;
        }
        if(black.d[o].v>white.d[p].v&&white.d[p].v==2)
            return white;
        if(black.d[o].v>white.d[p].v&&white.d[p].v!=2)
            return black;
        if(black.d[o].v<white.d[p].v&&black.d[p].v==2)
            return black;
        if(black.d[o].v<white.d[p].v&&black.d[p].v!=2)
            return white;
        if(black.d[i].v>white.d[i].v)
                return black;
            if(black.d[i].v<white.d[i].v)
                return white;
        if(black.d[o].v==white.d[p].v){
            for(i=0;i<5;i++){
                if(i!=o&&i!=(o+1)&&i!=p&&i!=(p+1))
                {
                    arr[k]=black.d[i].v;
                    brr[t]=white.d[i].v;
                    k++;
                    t++;
                }
                if(black.d[o].v==2)
                    bcount2-=2;
                if(white.d[p].v==2)
                    wcount2-=2
            }

                if(bcount2>wcount2)
                    return black;
                if(bcount2<wcount2)
                    return white;
                if(bcount2==wcount2)
                {
                    for(i=0;i<3;i++){
                        if(arr[i]>brr[i])
                            return black;
                        if(arr[i]<brr[i])
                            return white;
                        if(arr[i]==brr[i]){
                            if(i==2)
                                return tie;
                            else
                                continue;
                        }
                    }
                }


        }
    }

    if(black.type==white.type&&black.type==3){
        if(bcount2==wcount2)
        {
            /*if(bcount2==2){
                if(black.d[0].v==white.d[0].v)
                {
                    if(black.d[2].v==white.d[2].v)
                        return tie;
                    if(black.d[2].v<white.d[2].v)
                        return white;
                    if(black.d[2].v>white.d[2].v)
                        return black;
                }
                if(black.d[2].v<white.d[2].v)
                    return white;
                if(black.d[2].v>white.d[2].v)
                    return black;
            }
            else{

            }*/
        }
        if(bcount2<wcount2)
        {
            return white;
        }
        if(bcount>wcount2)
        {

            return black;
        }
    }

    if(black.type==white.type&&black.type==4){
        if(bcount2<wcount2)
            return white;
        if(bcount2>wcount2)
            return black;
        if(bcount2==wcount2)
        {
            if(bcount2==4)
            {
                if(black.d[0].v==white.d[0].v)
                    return tie;
                if(black.d[0].v>white.d[0].v)
                    return black;
                if(black.d[0].v<white.d[0].v)
                    return white;
            }
            else
            {
                if(black.d[0].v==white.d[0].v){
                    if(black.d[4].v==white.d[4].v)
                        return tie;
                    if(black.d[4].v>white.d[4].v)
                        return black;
                    if(black.d[4].v<white.d[4].v)
                        return white;
                }

            }
        }

    }

}
int main(){
    Poker black,white;
    int i,m=0,k=0;
    char s[40];
    while(gets(s)){
        for(i=0;i<28;i+=3){
            if(i>12){
                white.d[k].v=ChangeValue(s[i]);
                white.d[k].s=s[i+1];
                k++;
            }
            if(i<=12){
                black.d[m].v=ChangeValue(s[i]);
                black.d[m].s=s[i+1];
                m++;
            }
        }
        white.print();
        black.print();
    }

}
