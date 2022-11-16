#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    int arr[50001] = {0};
    int idx = 0;
    
    for(int i=0; i < works.size(); i++) {
        arr[works[i]]++;
        if(idx < works[i])
            idx = works[i];
    }
    
    for(int i = 0; i<n; i++) {
        if(idx == 0)
            break;
        
        while(idx > 0 && arr[idx] == 0)
            idx--;
        
        arr[idx]--;
        arr[idx-1]++;
    }
    
    for(int i=idx; i> 0; i--)
        answer += (i * i) * arr[i];
    
    return answer;
}
