#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {

public:
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<int>> f(board.size(), vector<int>(board[0].size(), 0));

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                if (backtrack(board, word, i, j, 0, f)) return true;
            }
        }

        return false;
    }
private:
    bool backtrack(vector<vector<char>>& board, string word,
        int x, int y, int index, vector<vector<int>>& visited) {

		if (index == word.size()) {
			return true;
		}

        if (x >= board.size() || y >= board[0].size() || x < 0 || y < 0) {
            return false;
        }
        if (board[x][y] != word[index]) return false;

        if (!visited[x][y]) {
            visited[x][y] = 1;

            cout << "x: " << x << ", y: " << y << ", index: " << index << endl;

			if (backtrack(board, word, x + 1, y, index + 1, visited) ||
				backtrack(board, word, x - 1, y, index + 1, visited) ||
				backtrack(board, word, x, y + 1, index + 1, visited) ||
				backtrack(board, word, x, y - 1, index + 1, visited)
				) {

                return true;
			}
            
            visited[x][y] = 0;
        }

        return false;
    }

};
