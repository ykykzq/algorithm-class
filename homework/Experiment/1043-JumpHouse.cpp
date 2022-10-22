#include<stdio.h>
#include<queue>
using namespace std;

typedef struct node{
    int x,y;
    int step;//表示第几次跳
}node;

int CheckerBoard[200][200];//存储的是一个数字，代表是第几步到达的；并用于判重
queue <node> q1;//队列

node MakeNewNode(node NowNode,int i){
    node NewNode=NowNode;
    NewNode.step++;
    switch(i){
        //左上
        case 1:
            NewNode.x=NewNode.x-2;
            NewNode.y=NewNode.y+1;
            break;
        case 2:
            NewNode.x=NewNode.x-1;
            NewNode.y=NewNode.y+2;
            break;
        //右上
        case 3:
            NewNode.x=NewNode.x+2;
            NewNode.y=NewNode.y+1;
            break;
        case 4:
            NewNode.x=NewNode.x+1;
            NewNode.y=NewNode.y+2;
            break;
        //右下
        case 5:
            NewNode.x=NewNode.x+2;
            NewNode.y=NewNode.y-1;
            break;
        case 6:
            NewNode.x=NewNode.x+1;
            NewNode.y=NewNode.y-2;
            break;
        //左下
        case 7:
            NewNode.x=NewNode.x-2;
            NewNode.y=NewNode.y-1;
            break;
        case 8:
            NewNode.x=NewNode.x-1;
            NewNode.y=NewNode.y-2;
            break;
    }

    return NewNode;
}

bool Check(node NewNode){
    if(NewNode.x<0||NewNode.y<0||NewNode.x>199||NewNode.y>199)//越界
        return false;
    if(CheckerBoard[NewNode.x][NewNode.y]!=0)//已走过，不可重复到达此节点
        return false;
    return true;
}

int search(node start,node end){
    q1.push(start);
    while(!q1.empty()){
        node NowNode=q1.front();q1.pop();//取出

        for(int i=1;i<=8;i++){
            node NewNode=MakeNewNode(NowNode,i);
            if(Check(NewNode)){
                CheckerBoard[NewNode.x][NewNode.y]=NewNode.step+'0';
                if(NewNode.x==end.x&&NewNode.y==end.y){
                    return NewNode.step;
                }
                q1.push(NewNode);
            }
        }
    }
    return -1;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        node start,end;
        scanf("%d%d%d%d",&start.x,&start.y,&end.x,&end.y);

        //坐标修正
        start.x--,start.y--,end.x--,end.y--;

        //初始化
        for(int i=0;i<200;i++)
            for(int j=0;j<200;j++)
                CheckerBoard[i][j]=0;
        while(!q1.empty())
            q1.pop();
        start.step=0;

        printf("%d\n",search(start,end));
    }
    return 0;
}