#include<stdio.h>

int graph[20][20];//邻接矩阵

int node[20];//存储每个节点的颜色
int answer;//着色方案的个数

bool CanPlace(int now_node,int color,int NofNodes){
    for(int i=0;i<NofNodes&&i!=now_node;i++){//遍历所有不同于其的节点
        if(graph[i][now_node]||graph[now_node][i]){//二者是可达的节点
            if(node[i]!=0&&color==node[i])//右颜色且相同
                return false;   
        }
    }
    return true;
}
void search(int i,int NofNodes,int m){//i代表了节点,NofNodes代表节点个数，m代表几种颜色
    if(i==NofNodes){
        answer++;
    }
    else{
        for(int color=1;color<=m;color++){
            if(CanPlace(i,color,NofNodes)){
                node[i]=color;
                search(i+1,NofNodes,m);
                node[i]=0;
            }
        }
    }
    return;
}
int main(){
    int n,r,m;
    scanf("%d %d %d",&n,&r,&m);

    for(int i=0;i<r;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        graph[x][y]=1;
    }

    search(0,n,m);
    printf("%d",answer);
    return 0;
}