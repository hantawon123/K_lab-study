#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
using namespace std;

int n, m;
long long int dp[1001][10001];
long long int f(int n, int m) {
	if (n < 1 || m < 1)
		return 0;
	if (n == 1 && m == 1)
		return 1;
	if (dp[n][m])
		return dp[n][m];
	else
		return dp[n][m] = (f(n - 1, m)%1000000007 + f(n, m - 1) % 1000000007 + f(n - 1, m - 1) % 1000000007) % 1000000007;
}
int main() {
	cin >> n >> m;
	dp[1][1] = 1;
	cout << f(n, m);
}
