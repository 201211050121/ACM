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


int a[maxn];

int cmp(int a, int b)
{
    return a > b;
}

int main()
{
    // freopen("in.txt","r",stdin);
    int n, m;
    while(scf2(n, m) == 2)
    {
        fr(i, n)
        scf(a[i]);
        sort(a, a+n, cmp);
        printf("%d", a[0]);
        upfr(i, 1, m-1)
        printf(" %d", a[i]);
        printf("\n");
    }
    return 0;
}