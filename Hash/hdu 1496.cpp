/*通过hash后，时间复杂度为O(N^2)*/

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define min2(x, y)     min(x, y)
#define max2(x, y)     max(x, y)
#define min3(x, y, z)  min(x, min(y, z))
#define max3(x, y, z)  max(x, max(y, z))
#define clr(x, y)      memset(x, y, sizeof(x))
#define fr(i,n)        for(int i = 0; i < n; i++)
#define fr1(i,n)       for(int i = 1; i <= n; i++)
#define upfr(i,j,n)    for(int i = j; i <= n; i++)
#define dowfr(i,j,n)   for(int i = n; i >= j; i--)
#define scf(n)         scanf("%d", &n)
#define scf2(n,m)      scanf("%d %d",&n,&m)
#define scf3(n,m,p)    scanf("%d %d %d",&n,&m,&p)
#define ptf(n)         printf("%d",n)
#define ptf64(n)       printf("%I64d",n)
#define ptfs(s)        printf("%s",s)
#define ptln()         printf("\n")
#define ptk()          printf(" ")
#define ptc(c)         printf("%c",c)
#define srt(a,n)       sort(a,n)
#define fre(f)         freopen(f, "r", stdin);
#define LL long long
#define pi acos(-1.0)
#define eps 0.00001
#define maxn 1000005
#define mod 10000007


int hash1[maxn];   //存正数
int hash2[maxn];   //存负数

int main()
{
    // freopen("in.txt","r",stdin);
    int a, b, c, d;
    while(scanf("%d %d %d %d", &a, &b, &c, &d) != EOF)
    {
        if((a > 0 && b > 0 && c > 0 && d > 0) || (a < 0 && b < 0 && c < 0 && d < 0))
        {
            printf("0\n");
            continue;
        }
        clr(hash1, 0);
        clr(hash2, 0);
        int tmp;
        for(int i = 1; i <= 100; i++)
        {
            for(int j = 1; j <= 100; j++)
            {
                tmp = a*i*i + b*j*j;
                if(tmp >= 0)
                    hash1[tmp] ++; 
                else
                    hash2[-tmp] ++;
            }
        }
        int cnt = 0;
        for(int i = 1; i <= 100; i++)
        {
            for(int j = 1; j <= 100; j++)
            {
                tmp = c*i*i + d*j*j;
                if(tmp > 0)             //结果为正，就查找对应的负值是否存在
                    cnt += hash2[tmp];  
                else
                    cnt += hash1[-tmp];  //结果为负，就查找对应的正值是否存在
            }
        }  
        printf("%d\n", cnt*16);          //对于每一组存在的值，四个解的取值有正负，所以是16种情况
    }
    return 0;
}


Hash函数优化后  31MS

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>

using namespace std;

#define min2(x, y)     min(x, y)
#define max2(x, y)     max(x, y)
#define min3(x, y, z)  min(x, min(y, z))
#define max3(x, y, z)  max(x, max(y, z))
#define clr(x, y)      memset(x, y, sizeof(x))
#define fr(i,n)        for(int i = 0; i < n; i++)
#define fr1(i,n)       for(int i = 1; i <= n; i++)
#define upfr(i,j,n)    for(int i = j; i <= n; i++)
#define dowfr(i,j,n)   for(int i = n; i >= j; i--)
#define scf(n)         scanf("%d", &n)
#define scf2(n,m)      scanf("%d %d",&n,&m)
#define scf3(n,m,p)    scanf("%d %d %d",&n,&m,&p)
#define ptf(n)         printf("%d",n)
#define ptf64(n)       printf("%I64d",n)
#define ptfs(s)        printf("%s",s)
#define ptln()         printf("\n")
#define ptk()          printf(" ")
#define ptc(c)         printf("%c",c)
#define srt(a,n)       sort(a,n)
#define fre(f)         freopen(f, "r", stdin);
#define LL long long
#define pi acos(-1.0)
#define eps 0.00001
#define maxn 200005
#define mod 10000007

int hash[maxn];
int flag[maxn];

int Hash(int k)
{
	int p = k % maxn;
	if(p < 0)
		p += maxn;
	while(flag[p] && hash[p] != k)
		p = (p+1) % maxn;
	return p;
}

int main()
{
	// fre("in.txt");
	int a, b, c, d;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) == 4)
	{
		if((a < 0 && b < 0 && c < 0 && d < 0) || (a > 0 && b > 0 && c > 0 && d > 0))
		{
			printf("0\n");
			continue;
		}
		clr(flag, 0);
		int p;
		for(int i = 1; i <= 100; i++)     //插入
		{
			for(int j = 1; j <= 100; j++)
			{
				p = Hash(a*i*i + b*j*j);
				hash[p] = a*i*i + b*j*j;
				flag[p]++;
			}
		}
		int cnt = 0;
		for(int i = 1; i <= 100; i++)     //查找
		{
			for(int j = 1; j <= 100; j++)
			{
			    p = Hash(-(c*i*i + d*j*j));
				if(flag[p])
					cnt += flag[p];
			}
		}
		printf("%d\n", cnt*16);
	}
	return 0;
}

