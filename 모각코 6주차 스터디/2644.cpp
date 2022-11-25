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

int k, n, p, c, a, b;
vector<vector<int>> v(101);
vector<int> root_a;
vector<int> root_b;

void dfs_a(int c) {
	if (v[c].size() == 0) {
		root_a.push_back(c);
		return;
	}
	dfs_a(v[c][0]);
	root_a.push_back(c);
}

void dfs_b(int c) {
	if (v[c].size() == 0) {
		root_b.push_back(c);
		return;
	}
	dfs_b(v[c][0]);
	root_b.push_back(c);
}

int main() {
	cin >> k;
	cin >> a >> b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> p >> c;
		v[c].push_back(p);
	}
	dfs_a(a);
	dfs_b(b);

	if (root_a[0] != root_b[0])
		cout << -1;
	else {
		while (1) {
			if (root_a.size() == 0 || root_b.size() == 0)
				break;
			if (root_a[0] == root_b[0]) {
				root_a.erase(root_a.begin());
				root_b.erase(root_b.begin());
			}
			else
				break;
		}
		if (root_a.size()==0 || root_b.size()==0) {
			cout << root_a.size() + root_b.size();
		}
		else {
			int ans = 2;
			while (root_a[0] != a) {
				ans++;
				root_a.erase(root_a.begin());
			}
			while (root_b[0] != b) {
				ans++;
				root_b.erase(root_b.begin());
			}
			cout << ans;
		}
	}
}