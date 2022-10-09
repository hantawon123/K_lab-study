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

int n, k, len;
char s[500001];
int arr[500001];
stack<int> st;
int main() {
	cin >> n >> k;
	cin >> s;
	len = n-k;
	for (int i = 0; i < n; i++) {
		if (st.size() == 0)
			st.push(s[i] - '0');
		else {
			if (st.top() >= s[i] - '0')
				st.push(s[i] - '0');
			else {
				while (k > 0 && st.size() > 0 && st.top() < s[i] - '0') {
					st.pop();
					k--;
				}
				st.push(s[i] - '0');
			}
		}
	}
	for (int i = st.size()-1; i >= 0; i--) {
		arr[i] = st.top();
		st.pop();
	}
	for (int i = 0; i < len; i++)
		cout << arr[i];
}