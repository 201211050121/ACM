/*将5组分前2化为一组，后3组为一组，hash第一组的和，然后顺序查找第二组和的相反数是否存在*/

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
#define LL __int64
#define pi acos(-1.0)
#define eps 0.00001
#define maxn 200005
#define mod 10000007

LL hash[maxn], a[5][202];
int flag[maxn];

int Hash(LL k)
{
    LL p = k % maxn;
    if(p < 0)
        p += maxn;
    while(flag[p] && hash[p] != k)
        p = (p+1) % maxn;
    return p;
}

int main()
{
    // fre("in.txt");
    int cs;
    scf(cs);
    while(cs--)
    {
        clr(flag, 0);
        int n;
        scf(n);
        for(int i = 0; i < 5; i++)
            for(int j = 0; j < n; j++)
                scanf("%I64d", &a[i][j]);
        int p;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
            {
                p = Hash(a[0][i] + a[1][j]);
                hash[p] = a[0][i] + a[1][j];
                flag[p] = 1;
            }
        int ok = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                for(int k = 0; k < n; k++)
                {
                    p = Hash(-(a[2][i] + a[3][j] + a[4][k]));
                    if(flag[p])
                    {
                        ok = 1;
                        printf("Yes\n");
                        break;
                    }
                }
                if(ok)
                    break;
            }
            if(ok)
                break;
        }
        if(!ok)
            printf("No\n");
    }
    return 0;
}
