#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<set>
#include<cstring>
#define rep(i,j,k) for(register int i = j; i <= k; i++)
#define dow(i,j,k) for(register int i = j; i >= k; i--) 
#define ll long long
using namespace std;

inline int read() {
	int s = 0, t = 1; char c = getchar();
	while( !isdigit(c) ) { if( c == '-' ) t = -1; c = getchar(); }
	while( isdigit(c) ) s = s * 10 + c - 48, c = getchar();
	return s * t;
}

const int N = 5e3+5; const ll inf = 1e16;
int v[N], q[N]; ll h[N], g[N], f[N][N];  
struct node{ 
	int x, y; bool operator < (const node&a) const { return x < a.x; } 
} A[N];

inline int Abs(int x) { return x >= 0 ? x : -x; } 

int main() {
	int n = read(), m = read();
	rep(i,1,n) v[i] = read(); 
	rep(i,1,m) A[i].x = read(), A[i].y = read();
	sort(v+1,v+n+1), sort(A+1,A+m+1);
	rep(i,0,m) rep(j,1,n) f[i][j] = inf;
	rep(i,1,m) { 
		rep(j,1,n) g[j] = Abs(A[i].x-v[j]);
		rep(j,2,n) g[j] += g[j-1];
		int l = 1, r = 0; q[++r] = 0, h[r] = 0;
		rep(j,1,n) { 
			while( l <= r && f[i-1][j] - g[j] <= h[r] ) r--;
			q[++r] = j, h[r] = f[i-1][j] - g[j]; 
			while( j - q[l] > A[i].y ) l++; 
			f[i][j] = h[l] + g[j];
		}
	}
	if( f[m][n] < inf ) cout<<f[m][n]<<endl;
	else puts("-1");
	return 0;
}
