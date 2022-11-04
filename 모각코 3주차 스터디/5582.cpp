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

string s, t;
int ans;
int dp[4001][4001];
int f() {
	int ans = 0;
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 1; j <= t.size(); j++) {
			if (s[i-1] == t[j-1]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
				ans = max(dp[i][j], ans);
			}
		}
	}
	return ans;
}
int main() {
	cin >> s;
	cin >> t;
	dp[0][0] = 0;
	if (t.size() > s.size()) {
		string tmp;
		tmp = t;
		t = s;
		s = tmp;
	}
	cout << f() << endl;
}