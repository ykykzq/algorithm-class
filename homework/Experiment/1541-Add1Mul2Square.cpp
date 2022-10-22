//需要注意while的死循环，见line54
#include <iostream>
#include <queue>
using namespace std;
int Answer;//需要的次数
int Father[100000];//用于记录每个节点的父节点，并用于判重

int MakeNewNode(int i,int now_n){
    if(i==1)
        return now_n+1;
    else if(i==2)
        return 2*now_n;
    else if(i==3)
        return now_n*now_n;

    return -1;//meaningless
}
bool Check(int now_n,int n){
    if(now_n>n)//已经超过目标数字
        return false;
    if(Father[now_n]!=0)//已经有父节点，说明之前产生过此数字
        return false;
    return true;
}
queue<int> q1;
bool search(int m,int n){
    q1.push(m);
    // Father[m]=m;
    while(!q1.empty()){
        int now=q1.front();
        q1.pop();
        int new_node;


        for(int i=1;i<=3;i++){
            new_node=MakeNewNode(i,now);
            
            if(Check(new_node,n)){//此节点是可扩展节点，则设置父节点、放入队列
                Father[new_node]=now;
                q1.push(new_node);
                if(new_node==n)//找到了
                    return true;
            }
        }//endFor
    }//endWhile
    return false;
}

int main(){
    int m,n;
    scanf("%d%d",&m,&n);
    search(m,n);

    //例如数据1,16，那么1会在后续产生，因此Father[1]==1,将会覆盖掉出发数据的father，进而产生死循环。
    //解决方案1：重新设置开始数据父节点为0（line57）
    //解决方案2：设置开始数据的父节点为自己（line28），并将下面的while终止条件设置为n不等于m
    Father[m]=0;
    while(Father[n]!=0){
        n=Father[n];
        Answer++;
    }
        
    printf("%d\n",Answer);
    return 0;
}