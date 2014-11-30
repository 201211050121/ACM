/*只要大家对题目真正理解了，就能做正确了，下面的只是参考代码*/
#include <stdio.h>
#include <string.h>
int main()
{
    int n,d,t,b;
    scanf("%d",&n);
    while(n--){
        scanf("%d %d %d",&d,&t,&b);
        if(b==1){
            printf("P\n");
            continue;
        }
        else{
            if(d==t){
                printf("It's my bing!\n");
                continue;
            }
            if(d<0&&t<0){
                printf("P\n");
                continue;
            }
            if(d<t)
                printf("T\n");
            else
                printf("D\n");
            continue;
        }
    }
    return 0;
}