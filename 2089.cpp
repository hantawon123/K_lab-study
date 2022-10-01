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

int n, cnt;
int arr[100];
void f(int x, int len) {
	if (x == 1 || x == 0) {
		arr[len] = x;
		cnt = len;
		return;
	}
	f(x / 2, len + 1);
	arr[len] = x % 2;
}
int main() {
	cin >> n;
	f(abs(n), 0);
	for (int i = 0; i <= cnt; i++) {
		if (n > 0) {
			if (i % 2 == 1 && arr[i] == 1) {
				arr[i + 1] += 1;
				if (arr[i + 1] == 2) {
					arr[i + 1] = 0;
					arr[i + 2] += 1;
					cnt = max(cnt, i + 2);
				}
				else
					cnt = max(cnt, i + 1);
			}
			else if (arr[i] == 2) {
				arr[i] = 0;
				arr[i + 1] += 1;
				cnt = max(cnt, i + 1);
			}
		}
		else {
			if (i % 2 == 0 && arr[i] == 1) {
				arr[i + 1] += 1;
				if (arr[i + 1] == 2) {
					arr[i + 1] = 0;
					arr[i + 2] += 1;
					cnt = max(cnt, i + 2);
				}
				else
					cnt = max(cnt, i + 1);
			}
			else if (arr[i] == 2) {
				arr[i] = 0;
				arr[i + 1] += 1;
				cnt = max(cnt, i + 1);
			}
		}
	}

	for (int i = cnt; i >= 0; i--)
		cout << arr[i];
}