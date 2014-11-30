/*暴力枚举这个数，然后取出它的每一位，再进行判断是否满足条件*/
#include<stdio.h>
 
void PaiXu(int *p,int n);
 
int main()
{
    int i=0;
    int a[4],max=0,min=0;
    for(i=4554;i<9876;++i)
    {
        a[0]=i/1000;
        a[1]=(i/100)%10;
        a[2]=(i%100)/10;
        a[3]=i%10;
        if(a[0]!=0&&a[1]!=0&&a[2]!=0&&a[3]!=0)
        {
            if(a[0]!=a[1]&&a[0]!=a[2]&&a[0]!=a[3]&&a[1]!=a[2]&&a[1]!=a[3]&&a[2]!=a[3])
            {
                PaiXu(a,4);
                max=a[3]*1000+a[2]*100+a[1]*10+a[0];
                min=a[0]*1000+a[1]*100+a[2]*10+a[3];
                if(3618==max-i&&4554==i-min)
                    {
                        printf("%d\n",i);
                        break;
                    }
            }
        }
    }
    return 0;
}
 
void PaiXu(int *p,int n)
{
    int i=0,j=0,temp=0;
    while(i<n)
    {
        j=i;
        while(j)
        {
            if(p[j]>p[j-1])  break;
            temp=p[j];p[j]=p[j-1];p[j-1]=temp;
            --j;
        }
        ++i;
    }
    return ;
}