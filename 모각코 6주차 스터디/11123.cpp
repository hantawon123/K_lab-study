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
int check[100][100];
int t, h, w, ans;
void dfs(char arr[][100], int i, int j) {
	if (check[i][j] == 1 || arr[i][j] == '.' || i < 0 || j < 0 || i == h || j == w )
		return;
	check[i][j] = 1;
	dfs(arr, i + 1, j);
	dfs(arr, i - 1, j);
	dfs(arr, i, j + 1);
	dfs(arr, i, j - 1);
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> h >> w;
		char arr[100][100];
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				cin >> arr[j][k];
			}
		}
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				if (arr[j][k] == '#' && check[j][k] == 0) {
					ans++;
					dfs(arr, j, k);
				}
			}
		}
		cout << ans << endl;
		ans = 0;
		for (int j = 0; j < h; j++) {
			for (int k = 0; k < w; k++) {
				check[j][k] = 0;
			}
		}
	}
}