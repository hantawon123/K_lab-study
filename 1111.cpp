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

int n,a,b;
int arr[51];
bool ans = true;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	if (n <= 2) {
		if (n == 2 && arr[0] == arr[1])
			cout << arr[1];
		else
			cout << 'A';
	}
	else {
		if (arr[1] != arr[0]) {
			a = (arr[2] - arr[1]) / (arr[1] - arr[0]);
			b = arr[1] - arr[0] * a;
		}
		else {
			if (arr[2] == arr[1]) {
				a = 0;
				b = arr[1];
			}
			else {
				a = 0;
				b = 0;
			}
		}
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] * a + b != arr[i + 1]) {
				ans = false;
				break;
			}
		}
		if (ans)
			cout << arr[n - 1] * a + b;
		else
			cout << 'B';
	}

}