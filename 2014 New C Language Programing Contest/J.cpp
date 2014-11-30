/*题目有点长，耐心点。根据友方英雄的数目，划分不同的情况（其实就是一个分段函数）
  对于每一种情况，判断x与y和x与z的关系，得出最大的距离。*/
#include <stdio.h>
int main()
{
    //freopen("in.txt","r",stdin);
    int t,m;
    double x,y,z;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf %lf %lf",&x,&y,&z);
        scanf("%d",&m);
        double sum=0;
        if(m>=4)
        {
            if(x>=0.5*y)
                sum+=y;
            if(x>=y*0.9&&x>=z)
            sum+=z;
        }else if(m==3)
        {
            if(x>=0.6*y)
                sum+=y;
            if(x>=y*0.9&&x>=z)
               sum+=z;
        }else if(m==2)
        {
            if(x>=0.7*y)
                sum+=y;
            if(x>=y*0.9&&x>=z)
                sum+=z;
        }else if(m==1)
        {
            if(x>=0.8*y)
                sum+=y;
            if(x>=y*0.9&&x>=z)
                sum+=z;
        }else if(m==0)
        {
            if(x>=0.9*y)
                sum+=y;
            if(x>=y*0.9&&x>=z)
                sum+=z;
        }else
        {
            if(x>=y)
                sum+=y;
            if(x>=y*0.9&&x>=z)
                sum+=z;
        }
        printf("%.2lf\n",sum);
 
    }
    return 0;
}