#include<stdio.h>
int ring[20];//素数环,亦即最后的解，没有用到

int TempRing[20];//当前的解

int flag=0;//实际上，素数环问题解极多，不能而且不需要遍历所有的解选择最优的解，直接输出第一个解即可

bool IsPrime(int n){
    for(int i=2;i<n;i++){
        if(n%i==0)return false;
    }
    return true;
}

bool CanPlace(int i,int num){//在第i个位置是否可以放入num
    for(int j=0;j<i;j++){//之前没有填入过num
        if(TempRing[j]==num)return false;
    }
    if(i==0)return true;//第一个元素一定可以放入
    if(i==19)return (IsPrime(num+TempRing[0])&&IsPrime(TempRing[18]+num));//最后一个元素需要前后相加都为素数
    return IsPrime(TempRing[i-1]+num);//一般情况下只判断与前数的和
}

// bool IsBetterAnswer(){
//     int i=0;
//     while(i<20){
//         if(ring[i]>TempRing[i])
//             return true;
//         i++;
//     }
//     return false;
// }

void FindRing(int i){
    if(flag==1)return;
    if(i==20){//获得一个解
        flag=1;
        for(int i=0;i<19;i++)
            printf("%d ",TempRing[i]);
        printf("%d\n",TempRing[19]);
    }
    else {
        for(int num=1;num<21;num++){
            if(CanPlace(i,num)){
                TempRing[i]=num;
                FindRing(i+1);
            }
        }
    }
    return;
}
int main(){
    FindRing(0);
    
    return 0;
}