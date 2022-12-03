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
int main() {
	cin >> n;
	if (n < 2)
		cout << -1;
	else {
		if (n % 5 == 0)
			cout << n / 5;
		else if (n % 5 % 2 == 0)
			cout << n / 5 + n % 5 / 2;
		else if (n / 5 >= 1)
			cout << n / 5 - 1 + (n % 5 + 5) / 2;
		else
			cout << -1;
	}
}