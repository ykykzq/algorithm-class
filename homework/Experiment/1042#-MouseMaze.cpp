//需要注意坐标修正（line77）
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

typedef struct node
{
    int x,y;
    int step;//代表着这是第几步
}node;

queue <node> q1;//队列
char maze[12][12];//迷宫图

node MakeNewNode(node now,int i){
    node newNode=now;
    newNode.step++;
    if(i==1)
        newNode.y=now.y-1;//上
    else if(i==2)
        newNode.y=now.y+1;//下
    else if(i==3)
        newNode.x=now.x-1;//左
    else if(i==4)
        newNode.x=now.x+1;//右
    
    return newNode;    
}

bool Check(node newNode){
    if(newNode.x<0||newNode.y<0||newNode.y>11||newNode.x>11)//越界节点无效
        return false;
    if(maze[newNode.x][newNode.y]!='.')//墙或者已走的节点无效
        return false;
    return true;
}
// void display(){//用于debug
//     printf("\n");
//     for(int i=0;i<12;i++){
//         for(int j=0;j<12;j++){
//             if(maze[i][j]=='.'||maze[i][j]=='X')
//                 printf("%c",maze[i][j]);
//             else 
//                 printf("%d",maze[i][j]-'0');
//         }
//         printf("\n");
//     }
//     printf("\n");
// }
int search(node start,node end){
    maze[start.x][start.y]=0+'0';
    q1.push(start);
    while(!q1.empty()){
        node now=q1.front();q1.pop();//弹出到now中

        // display();//用于debug
        node newNode;
        for(int i=1;i<=4;i++){
            newNode=MakeNewNode(now,i);
            if(Check(newNode)){
                maze[newNode.x][newNode.y]=newNode.step+'0';
                if(newNode.x==end.x&&newNode.y==end.y){
                    return newNode.step;
                }
                q1.push(newNode);
            }
        }
    }
    return 0;
}

int main(){
    node start,end;
    scanf("%d%d%d%d",&start.x,&start.y,&end.x,&end.y);

    //修正坐标
    start.x--;
    start.y--;
    end.x--;
    end.y--;

    getchar();//吃回车
    for(int i=0;i<12;i++){
        for(int j=0;j<12;j++){
            scanf("%c",&maze[i][j]);
        }
        getchar();//吃掉回车
    }

    start.step=0;
    

    printf("%d\n",search(start,end));

    return 0;
}