#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int>st;
    for(int i=0; i<moves.size(); i++) {
        
        int idx = 0;
        while(idx < board.size() && board[idx][moves[i]-1] == 0)
            idx++;
        if(idx == board.size())
            continue;
        
        if(st.size() == 0 || st.top() != board[idx][moves[i]-1]) {
            st.push(board[idx][moves[i]-1]);
            board[idx][moves[i]-1] = 0;
        }
        else if(st.top() == board[idx][moves[i]-1]) {
            board[idx][moves[i]-1] = 0;
            answer+=2;
            st.pop();
        }
    }
    return answer;
}
