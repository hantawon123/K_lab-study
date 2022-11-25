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
string s;
int check[1000001];
int main() {
	cin >> n >> m;
	cin >> s;
	int ans = 0;
	if (s[0] == 'I')
		check[0] = 1;
	else
		check[0] = 0;
	for (int i = 1; i < m; i++) {
		if (s[i] != s[i - 1])
			check[i] = check[i - 1] + 1;
		else {
			if (s[i] == 'O')
				check[i] = 0;
			else
				check[i] = 1;
		}
	}
	//for (int i = 0; i < m; i++)
		//cout << check[i];
	for (int i = 0; i < m; i++) {
		if (check[i] % 2 == 1 && check[i] >= 2 * n + 1)
			ans++;
	}
	cout << ans;
}