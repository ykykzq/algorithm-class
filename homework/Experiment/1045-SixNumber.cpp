#include<stdio.h>
#include<queue>
using namespace std;
typedef struct node
{
    int num[6];
    int step;
}node;

//全局变量
queue <node> q1;
bool used[6][6][6][6][6][6];//用于标记到过的状态,判重

//函数
node MakeNewNode(node NowNode,int i){
    node NewNode=NowNode;
    NewNode.step++;
    if(i==1){//阿尔法转换
        int temp=NewNode.num[0];
        NewNode.num[0]=NewNode.num[3];
        NewNode.num[3]=NewNode.num[4];
        NewNode.num[4]=NewNode.num[1];
        NewNode.num[1]=temp;
    }
    if(i==2){//贝塔转换
        int temp=NewNode.num[1];
        NewNode.num[1]=NewNode.num[4];
        NewNode.num[4]=NewNode.num[5];
        NewNode.num[5]=NewNode.num[2];
        NewNode.num[2]=temp;
    }
    return NewNode;
}

bool Check(node NewNode){
    if(used[NewNode.num[0]][NewNode.num[1]][NewNode.num[2]][NewNode.num[3]][NewNode.num[4]][NewNode.num[5]]==true)
        return false;//已经出现过
    return true;//只需要判重即可
}

bool Equal(node n1,node n2){//两个序列是否相等，用于判断是否已找到
    for(int i=0;i<6;i++){
        if(n1.num[i]!=n2.num[i])
            return false;
    }
    return true;
}
bool search(node start,node end){
    if(Equal(start,end))
        return true;
    used[start.num[0]][start.num[1]][start.num[2]][start.num[3]][start.num[4]][start.num[5]]=true;
    q1.push(start);
    while(!q1.empty()){
        node NowNode=q1.front();q1.pop();//取出

        node NewNode;
        for(int i=1;i<=2;i++){
            NewNode=MakeNewNode(NowNode,i);
            if(Check(NewNode)){
                //标记这个状态
                used[NewNode.num[0]][NewNode.num[1]][NewNode.num[2]][NewNode.num[3]][NewNode.num[4]][NewNode.num[5]]=true;
                if(Equal(NewNode,end)){
                    return true;
                }
                q1.push(NewNode);
            }
        }//endFor
    }//endWhile
    return false;
}
int main(){
    node start,end;
    while(scanf("%d %d %d %d %d %d",start.num+0,start.num+1,start.num+2,start.num+3,start.num+4,start.num+5)!=EOF){
        
        //初始化
        start.step=0;
        for(int i=0;i<6;i++)
            end.num[i]=i+1;
        while(!q1.empty())
            q1.pop();
        for(int i1=0;i1<6;i1++)
            for(int i2=0;i2<6;i2++)
                for(int i3=0;i3<6;i3++)
                    for(int i4=0;i4<6;i4++)
                        for(int i5=0;i5<6;i5++)
                            for(int i6=0;i6<6;i6++)
                                used[i1][i2][i3][i4][i5][i6]=false;



        bool flag=search(start,end);
        if(flag)
            printf("Yes\n");
        else 
            printf("No\n");
    }
    return 0;
}