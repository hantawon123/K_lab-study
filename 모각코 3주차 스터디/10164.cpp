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

int n, m, k, x, y;
long long int dp[16][16];

long long int f1(int i, int j) {
	if (i == y && j == x)
		return 1;
	if (i > y || j > x)
		return 0;
	if (dp[i][j])
		return dp[i][j];
	else
		return dp[i][j] = f1(i + 1, j) + f1(i, j + 1);
}
long long int f2(int i, int j) {
	if (i == n - 1 && j == m - 1)
		return 1;
	if (i > n - 1 || j > m - 1)
		return 0;
	if (dp[i][j])
		return dp[i][j];
	else
		return dp[i][j] = f2(i + 1, j) + f2(i, j + 1);
}
int main() {
	cin >> n >> m >> k;
	y = ceil(k / (float)m) - 1;
	x = k % m - 1;
	if (k == 0) {
		y = 0;
		x = 0;
	}
	else if (x == -1)
		x = m - 1;
	cout << f1(0,0) * f2(y, x);
}