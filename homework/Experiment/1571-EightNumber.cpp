#include<stdio.h>
#include<queue>
using namespace std;


typedef struct node
{
    int num[3][3];
    int step;
    int ZeroX,ZeroY;//0的位置
}node;

//全局变量
bool used[362881];
queue <node> q1;

int POW(int x,int i){//返回x的i次方
    int y=1;
    while(i!=0){
        y=y*x;
        i--;
    }
    return y;
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

node MakeNewNode(node NowNode,int i){
    node NewNode=NowNode;
    NewNode.step++;
    if(i==1){//上
        if(NowNode.ZeroX!=0){//上面有数字
            NewNode.num[NewNode.ZeroX][NewNode.ZeroY]=NewNode.num[NewNode.ZeroX-1][NewNode.ZeroY];
            NewNode.ZeroX--;
            NewNode.num[NewNode.ZeroX][NewNode.ZeroY]=0;
        }
    }
    else if(i==2){//下
        if(NowNode.ZeroX!=2){//下面有数字
            NewNode.num[NewNode.ZeroX][NewNode.ZeroY]=NewNode.num[NewNode.ZeroX+1][NewNode.ZeroY];
            NewNode.ZeroX++;
            NewNode.num[NewNode.ZeroX][NewNode.ZeroY]=0;
        }
    }
    else if(i==3){//左
        if(NowNode.ZeroY!=0){//左面有数字
            NewNode.num[NewNode.ZeroX][NewNode.ZeroY]=NewNode.num[NewNode.ZeroX][NewNode.ZeroY-1];
            NewNode.ZeroY--;
            NewNode.num[NewNode.ZeroX][NewNode.ZeroY]=0;
        }
    }
    else if(i==4){//右
        if(NowNode.ZeroY!=2){//右面有数字
            NewNode.num[NewNode.ZeroX][NewNode.ZeroY]=NewNode.num[NewNode.ZeroX][NewNode.ZeroY+1];
            NewNode.ZeroY++;
            NewNode.num[NewNode.ZeroX][NewNode.ZeroY]=0;
        }
    }
    return NewNode;
}

int TranSeries(node NewNode){//首先将序列转化为int
    int x=0;
    for(int i=0;i<8;i++){
        x=(x+NewNode.num[i/3][i%3])*10;
    }
    return x+NewNode.num[2][2];
}

bool Check(node NewNode){//在make中已经控制不会越界，只需判重即可
    if(used[Hash(TranSeries(NewNode))]==true)
        return false;
    return true;
}

bool Equal(node NewNode,node end){//搜索终止条件
    for(int i=0;i<=8;i++)
        if(NewNode.num[i/3][i%3]!=end.num[i/3][i%3])
            return false;
    return true;
}

int search(node start,node end){
    q1.push(start);
    used[Hash(TranSeries(start))]=true;
    while(!q1.empty()){
        node NowNode=q1.front();q1.pop();//取出

        node NewNode;
        for(int i=1;i<=4;i++){
            NewNode=MakeNewNode(NowNode,i);
            if(Check(NewNode)){
                int x=TranSeries(NewNode);
                used[Hash(x)]=true;
                if(Equal(NewNode,end)){
                    return NewNode.step;
                }
                q1.push(NewNode);
            }
        }
    }
    return -1;
}


int main(){
    node start,end;
    for(int i=0;i<=8;i++){
        scanf("%d",&start.num[i/3][i%3]);
        if(start.num[i/3][i%3]==0){
            start.ZeroX=i/3;
            start.ZeroY=i%3;
        }

        //顺带初始化end
        end.num[i/3][i%3]=i+1;
    }

    //初始化
    start.step=0;
    end.num[2][2]=0;

    int answer=search(start,end);
    printf("%d\n",answer);
    return 0;
}