#include<stdio.h>
char castle[4][4];
int MaxNum;
int n;//城堡的规模
bool check(int i,int j){
    if(castle[i][j]=='X'||castle[i][j]=='P')//此处是墙或者已放置
        return false;

    int row=i,col=j;
    while(row>=0){//判断此列可以放置
        if(castle[row][col]=='X')break;//第一个碰到是是墙，因此此列可以放置
        if(castle[row][col]=='P'){
            return false;
        }
        row--;
    }
    row=i;
    while(col>=0){//判断此列可以放置
        if(castle[row][col]=='X')break;
        if(castle[row][col]=='P'){
            return false;

        }
        col--;
    }
    return true;
}
void search(int i){
    int row,col;
    row=i/n;
    col=i%n;
    if(row==n){//遍历完了
        int num=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(castle[i][j]=='P')num++;
            }
        }
        if(num>MaxNum)MaxNum=num;
    }
    else {
        search(i+1);//此地不放堡垒
        if(check(row,col)){
            castle[row][col]='P';
            search(i+1);
            castle[row][col]='.';
        }
    }
    return ;
}
int main(){

    while(1){
        scanf("%d",&n);
        getchar();
        if(n==0)break;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                scanf("%c",&castle[i][j]);
            getchar();//吃掉回车
        }
        
    
        MaxNum=0;
        search(0);

        printf("%d\n",MaxNum);
    }
    

    return 0;
}