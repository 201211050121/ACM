/*简单的模拟*/
#include <stdio.h>
 
int main ()
{
    // freopen("in.txt","r",stdin);
    int n;
    scanf("%d", &n);
        int m;
    int ca = 1;
        while(n--)
        {
            printf("Case #%d: ", ca++);
            int gun = 0;
            int i = 0;
            char a[100];
            scanf("%d\n",&m);
            gets(a);
            for(i = 0; i < m; i++)
            {
                if(a[i] == '~' && gun == 0) gun++;
                if(a[i] == '!') gun--;
            }
            if(gun < 0) printf("dead -_-\n");
                else printf("alive ^-^\n");
        }
    return 0;
}