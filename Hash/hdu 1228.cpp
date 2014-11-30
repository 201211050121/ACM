/*自己yy出的想法，感谢P哥给了我一个神数据*/

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
#define maxn 1024
#define mod 10000007

std::map<string, int> mp;
char str1[maxn], str2[maxn];
int num1[maxn], num2[maxn];

int main()
{
    //freopen("in.txt","r",stdin);
    mp.clear();
    mp["zero"] = 0; mp["one"] = 1; mp["two"] = 2; mp["three"] = 3; mp["four"] = 4; 
    mp["five"] = 5; mp["six"] = 6;  mp["seven"] = 7; mp["eight"] = 8; mp["nine"] = 9;
    int cnt1, cnt2;
    while(scanf("%s", str1))
    {
        clr(num1, -1);
        clr(num2, -1);
        cnt1 = 0;
        cnt2 = 0;
        num1[cnt1++] = mp[str1];
        int flag = 1;
        while(scanf("%s", str1))
        {
            if(!strcmp(str1, "="))
                break;
            if(!strcmp(str1, "+"))
                {
                    flag = 0;
                    continue;
                }
            if(flag)
                num1[cnt1++] = mp[str1];
            else
                num2[cnt2++] = mp[str1];
        }
        int a, b;
        if(num1[1] != -1)
            a = num1[0] * 10 + num1[1];
        else
            a = num1[0];
        if(num2[1] != -1)
            b = num2[0] * 10 + num2[1];
        else
            b = num2[0];
        if(a + b == 0)
            break;
        printf("%d\n", a+b);
    }
    return 0;
}