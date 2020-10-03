#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, k, n) for(int i=k; i<n; i++)
#define F first
#define S second

int power(int a, int b) {
int x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>mod) x%=mod;
        }
        y = (y*y);
        if(y>mod) y%=mod;
        b /= 2;
    }
    return x;
}

int totient(int n) {
int result = n;
for(int i=2;i*i <= n;i++) 
{
    if (n % i == 0) result -= result / i;   
    while (n % i == 0) n /= i;
}

if (n > 1) result -= result / n;
return result;
}

int readInt () {
    bool minus = false;
    int result = 0;
    char ch;
    ch = getchar();
    while (true) {
        if (ch == '-') break;
        if (ch >= '0' && ch <= '9') break;
        ch = getchar();
    }
    if (ch == '-') minus = true; else result = ch-'0';
    while (true) {
        ch = getchar();
        if (ch < '0' || ch > '9') break;
        result = result*10 + (ch - '0');
    }
    if (minus)
        return -result;
    else
        return result;
}

int32_t main(void)
{
    int t;
    scanf("%lli", &t);
    while(t--){
        int n, q;
        scanf("%lli", &n);
        scanf("%lli", &q);
        int a[n];
        flp(i, 0, n) scanf("%lli", &a[i]);
        int count1=0, count2=0;
        flp(i, 0, n)
             {
                if((__builtin_popcountll(a[i]))%2==0) count1++;
                else count2++;
             }

        flp(i, 0, q)
        {
            int p;
            scanf("%lli", &p);
            if((__builtin_popcountll(p))%2==0)
            {
                printf("%lli ",count1);
                printf("%lli \n", count2);
            }

            else
            {
                printf("%lli ", count2);
                printf("%lli \n",count1);
            }
        }
    }

    return 0;
}