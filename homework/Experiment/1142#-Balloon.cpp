#include<stdio.h>
bool flag_a,flag_b;

// int now_a,now_b;
//对于100以内的数i，只有三种状态：a的约数，b的约数，不是约数
void search(int i,int now_a,int now_b,int a,int b){
    if(i==101){
        if(now_a==a&&now_b==b){
            flag_a=true;
            flag_b=true;
        }
        else if(now_a==a){
            flag_a=true;
        }
            
    }
    else {
        if(now_a<a&&a%(i+1)==0)
            search(i+1,now_a*(i+1),now_b,a,b);
        if(now_b<b&&b%(i+1)==0)
            search(i+1,now_a,now_b*(i+1),a,b);
        if(now_a<=a&&now_b<=b)
            search(i+1,now_a,now_b,a,b);
    }
    return;
}
int main(){
    while(1){
        int a,b;
        scanf("%d %d",&a,&b);
        if(!(a||b))//a，b均为0
            break;

        if(a>b){//确保a<b
            a=a^b;
            b=a^b;
            a=a^b;
        }

        flag_a=flag_b=false;//初始化
        // now_a=now_b=1;
        
        search(1,1,1,a,b);

        if(!flag_a){//a说假话
            if(flag_b)//b说真话
                printf("%d\n",b);
            else    
                printf("%d\n",b);
        }
        else{//a是真话
            if(flag_b)
                printf("%d\n",b);
            else
                printf("%d\n",a);
        }
    }
    return 0;
}