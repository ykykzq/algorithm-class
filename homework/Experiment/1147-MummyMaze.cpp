#include<stdio.h>
#include<queue>
using namespace std;

typedef struct node{
    int PeopleX,PeopleY;
    int MummyX,MummyY;
    int step;
}node;

//全局变量
char maze[6][6];//迷宫
queue <node>q1;
bool used[6][6][6][6];//用于记录节点、判重,四个参数依次为PeopleX,PeopleY,MummyX,MummyY

//函数
node MummyMove(node NewNode){//木乃伊的某一步
    //木乃伊的第一步
    if(NewNode.PeopleY!=NewNode.MummyY){//未同列,则左右走
        if(NewNode.PeopleY<NewNode.MummyY)//人在左
            if(maze[NewNode.MummyX][NewNode.MummyY-1]!='#')
                    NewNode.MummyY--;
            else 
                 ;
        else //人在右
            if(maze[NewNode.MummyY][NewNode.MummyY+1]!='#')
                NewNode.MummyY++;
             else 
                ;  
    }
    else{//同列,则上下走
        if(NewNode.PeopleX<NewNode.MummyX)//人在上
            if(maze[NewNode.MummyX-1][NewNode.MummyY]!='#')
                NewNode.MummyX--;
            else
                ;
        if(NewNode.PeopleX>NewNode.MummyX)//人在下
            if(maze[NewNode.PeopleX+1][NewNode.MummyY]!='#')
                NewNode.MummyX++;
            else 
                ;
    }
    //木乃伊的第二步只需要再执行一次此函数
    return NewNode;
}

node MakeNewNode(node NowNode,int i){//这里要体现出“牵制”，保证木乃伊的行动是合法的
    node NewNode=NowNode;
    NewNode.step++;

    //无需保证人的行动是合法的，因为下有Check函数进行检查
    if(i==1){//向上走
        NewNode.PeopleY--;
        //木乃伊走两步
        NewNode=MummyMove(NewNode);
        NewNode=MummyMove(NewNode);
    }
    if(i==2){//向下走
        NewNode.PeopleY++;
        //木乃伊走两步
        NewNode=MummyMove(NewNode);
        NewNode=MummyMove(NewNode);
    }
    if(i==3){//向左走
        NewNode.PeopleX--;
        //木乃伊走两步
        NewNode=MummyMove(NewNode);
        NewNode=MummyMove(NewNode);
    }
    if(i==4){//向右走
        NewNode.PeopleX++;
        //木乃伊走两步
        NewNode=MummyMove(NewNode);
        NewNode=MummyMove(NewNode);
    }
    return NewNode;
}

bool Check(node NewNode){//检查产生的节点的合法性
    if(NewNode.PeopleX<0||NewNode.PeopleX>5||NewNode.PeopleY<0||NewNode.PeopleY>5)//越界
        return false;
    if(maze[NewNode.PeopleX][NewNode.PeopleY]=='#')//人不能走到墙上
        return false;
    if(used[NewNode.PeopleX][NewNode.PeopleY][NewNode.MummyX][NewNode.MummyY]==true)//重复
        return false;
    if(NewNode.PeopleX==NewNode.MummyX&&NewNode.PeopleY==NewNode.MummyY)//被抓住了
        return false;
    return true;
}

void display(node newnode){
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            if(maze[i][j]='#')
                printf("%3c",maze[i][j]);
            if(i==newnode.MummyX&&j==newnode.MummyY)
                printf(" M ");
            else if(i==newnode.PeopleX&&newnode.PeopleY)
                printf(" P ");
            else    
                printf(" . ");
        }     
        printf("\n");
    }
    printf("\n");
}

bool search(node start,node end){
    used[start.PeopleX][start.PeopleY][start.MummyX][start.MummyY]=true;
    q1.push(start);
    while(!q1.empty()){
        node NowNode=q1.front();q1.pop();

        node NewNode;
        for(int i=1;i<=4;i++){
            NewNode=MakeNewNode(NowNode,i);
            if(Check(NewNode)){
                used[NewNode.PeopleX][NewNode.PeopleY][NewNode.MummyX][NewNode.MummyY]=true;
                if(NewNode.PeopleX==end.PeopleX&&NewNode.PeopleY==end.PeopleY)
                    return true;
                q1.push(NewNode);
            }
        }//endFor
    }//endWhile
    return false;
}
int main(){
    int n;
    node start,end;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x,y,mode;
        scanf("%d %d %d",&x,&y,&mode);
        if(mode==0) 
            maze[x+1][y]='#';
        else if(mode==1)
            maze[x][y+1]='#';
    }
    int x,y;
    scanf("%d %d",&x,&y);
    start.MummyX=x;
    start.MummyY=y;
    scanf("%d %d",&x,&y);
    start.PeopleX=x;
    start.PeopleY=y;
    scanf("%d %d",&x,&y);
    end.PeopleX=x;
    end.PeopleY=y;


    //初始化
    start.step=0;

    bool flag=search(start,end);

    if(flag)
        printf("Yes\n");
    else
        printf("No\n");
    return 0;
}