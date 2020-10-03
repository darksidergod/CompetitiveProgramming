#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define int long long int
#define pb push_back
#define mk make_pair
#define flp(i, n) for(int i=0; i<n; i++)
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

int compute_hash(string const& s) {
    const int p = 31;
    const int m = 1e9 + 9;
    int hash_value = 0;
    int p_pow = 1;
    for (char c : s) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    
    return hash_value;
}

int32_t main(void)
{
    
}