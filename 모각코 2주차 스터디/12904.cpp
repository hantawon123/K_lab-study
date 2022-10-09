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
int main() {
	cin >> s;
	cin >> t;
	while (t.size() > s.size()) {
		if (t[t.size() - 1] == 'A')
			t = t.substr(0, t.size() - 1);
		else {
			t = t.substr(0, t.size() - 1);
			reverse(t.begin(), t.end());
		}
	}
	cout << (int)(s == t);
}
