#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
typedef struct node
{
    int num[3][3];
    int step;
    int ZeroX,ZeroY;//0的位置
}node;
int POW(int x,int i){//返回x的i次方
    int y=1;
    while(i!=0){
        y=y*x;
        i--;
    }
    return y;
}
int TranSeries(node NewNode){//首先将序列转化为int
    int x=0;
    for(int i=0;i<8;i++){
        x=(x+NewNode.num[i/3][i%3])*10;
    }
    return x+NewNode.num[2][2];
}
int Hash(int x){//将一个序列投影到0-n!-1的范围内
    int y=0;
    int help=362880;//9!
    bool used[9]={false,false,false,false,false,false,false,false,false};
    for(int i=8;i>=0;i--){
        int front=x/POW(10,i)%10;//从最大位开始，逐次析出每一位

        //遍历，查看有几个比其小的数字
        int flag=0;
        for(int j=0;j<9;j++){
            if(used[j]==false)
                if(j<front)
                    flag++;
        }
        //help逐步从9！降至1
        help=help/(i+1);

        y=y+help*flag;
        used[front]=true;
    }
    return y;
}
bool used[362881];
int main(){
    node n;
    int a[]={0,1,2,3,4,5,6,7,8};
    do{
	    n.num[0][0]=a[0],n.num[0][1]=a[1],n.num[0][2]=a[2],n.num[1][0]=a[3],n.num[1][1]=a[4],n.num[1][2]=a[5],n.num[2][0]=a[6],n.num[2][1]=a[7],n.num[2][2]=a[8];
        cout<<a[0]<<a[1]<<a[2]<<a[3]<<a[4]<<a[5]<<a[6]<<a[7]<<a[8]<<endl;
        int x=TranSeries(n);
        printf("x:%d\n",x);
        printf("Hash:%d\n\n",Hash(x));
        used[Hash(x)]=true;
    }while(next_permutation(a,a+9));

    for(int i=0;i<362881;i++){
        if(used[i]==false){
            printf("waring");
            break;
        }  
    }
        
    
    return 0;
}
