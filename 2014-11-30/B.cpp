/*当然也可以用减-2的方法做，大家试一试*/
#include<stdio.h>
 
int main()
{
    //freopen("in.txt","r",stdin);
    int n;
    while(scanf("%d",&n) == 1)
    {
        int a = 0;
        while(a < n)
            a += 2;
        if(a - n == 1)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}