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
int arr[200001];
int max_dif;
int min_val;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) {
			max_dif = 0;
			min_val = arr[0];
		}
		else {
			max_dif = max(max_dif, arr[i] - min_val);
			min_val = min(min_val, arr[i]);
		}
		cout << max_dif << ' ';
	}
}