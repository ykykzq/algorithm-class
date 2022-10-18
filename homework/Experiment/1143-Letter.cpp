// 结构体内不能赋值，否则noj会编译错误
// 注意每一个解得后面只有回车没有空格（参见第36,37行）
#include<stdio.h>   
struct mstack{
    char stack[200];
    char ptr;
};

void mPush(struct mstack *p,char i){
    p->ptr++;
    p->stack[p->ptr]=i;
    return;
}

char mPop(struct mstack *p){
    if(p->ptr<0)return -1;
    p->ptr--;
    return p->stack[p->ptr+1];
    
}

char now_op[200];//当前的操作顺序

char letter[200];//原序列
int ptr_le;//指向原序列

char goal[200];//目标序列
int ptr_goa;//指向目标序列

struct mstack s;


void dfs(int i,int NofLetter){//i是第几次操作,从0开始
    if(i==NofLetter*2&&ptr_goa==NofLetter){
        for(int j=0;j<NofLetter*2-1;j++)
            printf("%c ",now_op[j]);
        printf("%c\n",now_op[NofLetter*2-1]);
    }
    else {
        //入栈
        if(ptr_le<NofLetter){
            mPush(&s,letter[ptr_le]);
            ptr_le++;
            now_op[i]='i';
            dfs(i+1,NofLetter);
            mPop(&s);
            ptr_le--;
        }
        
        // 出栈（栈里有元素）
        if(s.ptr>=0&&s.stack[s.ptr]==goal[ptr_goa]){
            char temp=mPop(&s);
            ptr_goa++;
            now_op[i]='o';
            dfs(i+1,NofLetter);
            ptr_goa--;
            mPush(&s,temp);
        }        
    }
}
int main(){
    while(scanf("%s",letter)!=EOF){

        scanf("%s",goal);
        

        int i=0;
        while(letter[i]!='\n'&&letter[i]!=0)
            i++;
        
        s.ptr=-1;
        ptr_le=ptr_goa=0;//初始化

        printf("[\n");
        dfs(0,i);
        printf("]\n");

    }
    return 0;
}