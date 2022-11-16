#include <string>
#include <vector>

using namespace std;

void find(int n,int i, vector<vector<int>> computers, int check[]) {
    for(int j=0 ; j<n ; j++){
        if(computers[i][j] == 1) {
            if(check[j] == 0) {
                check[j] = 1;
                find(n ,j, computers, check);
            }
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    int check[201];
    
    for(int i=0; i<n; i++)
        check[i] = 0;
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(computers[i][j] == 1) {
                if(check[j] == 1)
                    continue;
                else {
                    answer++;
                    check[j] = 1;
                    find(n, j, computers, check);
                }
            }
        }
    }
    return answer;
}
