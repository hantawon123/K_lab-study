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

int t, n, arr[1000001], high;
long long int sum;

int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		sum = 0;
		high = 0;
		for (int j = 0; j < n; j++)
			cin >> arr[j];
		for (int j = n - 1; j >= 0; j--) {
			if (high < arr[j]) {
				high = arr[j];
			}
			else {
				sum += high - arr[j];
			}
		}
		cout << sum << endl;
	}
}