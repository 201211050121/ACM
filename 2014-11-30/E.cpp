/*先把7进制和3进制转化为10进制，计算出总额后，再转换为3进制输出*/
#include <stdio.h>
int main(){
int a,b;
while (scanf("%d %d",&a,&b)!=EOF && a+b!=0)
{
    if (a==0 || b==0)
    {
        printf("0\n");
    }
    else
    {
    int resa=0,resb=0;
    int sev=1;
    int thr=1;
    while (a!=0)
    {
        resa+=sev*(a%10);
        a/=10;
        sev*=7;
    }
    while (b!=0)
    {
        resb+=thr*(b%10);
        b/=10;
        thr*=3;
    }
    int res=resa*resb;
    int data[500];
    int len=0;
    while (res!=0)
    {
        data[len++]=res%3;
        res/=3;
    }
    int i;
 
    for (i=len-1;i>=0;i--)
    {
        printf("%d",data[i]);
    }
    printf("\n");
    }
 
}
return 0;}