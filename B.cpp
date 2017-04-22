#define _CRT_SECURE_NO_DEPRECATE
#define rep(i, b, e) for (int i = b; i < e; ++i)
#include <stdio.h>
#include <math.h>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long int64;

int main()
{
    int n, s = 0, s1= 0, mn = -12345, mx = 12345;
    scanf("%d", &n);
    int x;
    rep(i, 0, n) {
        scanf("%d", &x);
        if (x & 1) {
            if (x > 0) {
                s1 += x;
                mx = min(mx, x);
            }
            else
                mn = max(mn, x);
        }
        else {
            if (x > 0) s += x;
        }
    }
    if ((s1 & 1) == 0) {
        if (-mn < mx)
            s1 += mn;
        else
            s1 -= mx;
    }
    printf("%d", s + s1);
    return 0;
}
