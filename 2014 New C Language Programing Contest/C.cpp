/*略*/
#include <stdio.h>
#include <string.h>
 
const int maxn = 110;
char s[maxn];
 
int main()
{
    // freopen("in.txt","r",stdin);
    while(gets(s) != NULL)
    {
        for(int i = 0; s[i]; i++)
            printf("%d", s[i]-'a'+1);
        printf("\n");
    }
    return 0;
}