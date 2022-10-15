#include<stdio.h>
int answer=0;//用于输出“No ”用，显示这是第几个方案
char castle[8][8];
bool CanPlace(int i,int j){
    if(castle[i][j]=='A')//此处已放置
        return false;

    int row=i,col=j;
    while(row>=0){//判断此列可以放置
        if(castle[row][col]=='A')
            return false;
        row--;
    }
    row=i,col=j;
    while(col>=0){//判断此行可以放置
        if(castle[row][col]=='A')
            return false;
        col--;
    }
    row=i,col=j;
    while(col>=0&&row>=0){//交叉方向可以放置--左上
        if(castle[row][col]=='A')
            return false;
        col--;
        row--;
    }
    row=i,col=j;
    while(col!=8&&row>=0){//交叉方向可以放置--右上
        if(castle[row][col]=='A')
            return false;
        col++;
        row--;

    }
    //左下、右下无需判断，因为是从上到下放置

    return true;
}

void display(){
    printf("No %d:",answer);
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            printf("%c",castle[i][j]);
        }
        printf("\n");
    }
}

void Queen(int i){
    if(i==8){
        answer++;
        display();
    }
    else{
        for(int j=0;j<8;j++){
            Queen(i+1);//此处不放
            if(CanPlace(i,j)){
                castle[i][j]='A';
                Queen(i+1);
                castle[i][j]='.';
            }
        }
    }
}
int main(){
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            castle[i][j]='.';
        }
    }
    Queen(0);
    return 0;
}