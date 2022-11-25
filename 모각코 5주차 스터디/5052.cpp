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

int t, n;
vector<string> s;
string num;
bool ans = true;
bool cmp(string s1, string s2) {
	return s1 < s2;
}
int main() {
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n;
		for (int j = 0; j < n; j++) {
			cin >> num;
			s.push_back(num);
		}
		sort(s.begin(), s.end(), cmp);
		ans = true;
		for (int i = 0; i < n - 1; i++) {
			if (s[i] == s[i + 1].substr(0, s[i].size())) {
				ans = false;
				break;
			}
		}
		if (ans)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		//for (int i = 0; i < n; i++)
			//cout << s[i] << endl;
		s.clear();
	}
}