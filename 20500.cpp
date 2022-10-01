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

int n;
long long int sum;
int dp[1516][1516];
int f(int n, int r) {
	if (n == r || r == 0)
		return dp[n][r] = 1;
	else if (dp[n][r])
		return dp[n][r];
	else
		return dp[n][r] = (f(n - 1, r - 1)%1000000007 + f(n - 1, r) % 1000000007) % 1000000007;
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		if ((n - i*2) % 3 == 0 || i == n-i) {
			sum += f(n - 1, i-1);
			sum %= 1000000007;
		}
	}
	cout << sum;
}