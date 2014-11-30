/*排序问题，标程是冒泡排序，也可以用其他的排序算法，大家要熟练掌握基本的几种常用排序算法*/
#include <stdio.h>
int main()
{
    // freopen("in.txt","r",stdin);
    int n;
    int a[10000];
    scanf("%d",&n);
    while(n--)
    {
        int i,j,m,t;
        scanf("%d",&m);
        for(i=1;i<=m;++i)
        scanf("%d",&a[i]);
        for(i=1;i<=m;++i)
        {
            for(j=1;j<=m-i;++j)
              if(a[j]>a[j+1])
              {
                    t=a[j+1];
                    a[j+1]=a[j];
                    a[j]=t;
               }
        }
       printf("%d",a[1]);
       for(i=2;i<=m;++i)
       printf(" %d",a[i]);
       printf("\n");
    }
    return 0;
}