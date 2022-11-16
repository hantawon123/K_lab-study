#include <string>
#include <vector>
#include <math.h>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    vector<int> arr;
    for(int i=0; i<progresses.size(); i++) {
        arr.push_back(ceil((100 - progresses[i])/(float)speeds[i]));
    }
    int cnt = 1;
    for(int i=0; i<=progresses.size() - 1; i++) {
        for(int j=i+1; j<=progresses.size(); j++) {
            if(j == progresses.size() || arr[i] < arr[j]) {
                answer.push_back(cnt);
                cnt = 1;
                i = j-1;
                break;
            }
            else
                cnt++;
        }
    }
    //return arr;
    return answer;
}
