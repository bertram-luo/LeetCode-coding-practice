//Number of Islands II 
#include <iostream>
#include <set>
#include <vector>
using namespace std;

class Solution {
	int num_islands;
	vector<pair<int, int>> directions;
	public:
	Solution() : num_islands(0), directions({{-1, 0}, {0, -1}, {1, 0}, {0, 1}}){

	}
	vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
		vector<vector<int>> board(m, vector<int>(n, -1));
		vector<int> res;
		for(auto& item : positions){
			board[item.first][item.second] = item.first * board[0].size() + item.second;
			num_islands = num_islands + 1 - merged(board, item.first, item.second);
			res.push_back(num_islands);
		}
		return res;
	}
	int merged(vector<vector<int>>& board, int row, int col){
		set<int> neighber_set;
		for(auto& item : directions){
			int check_row = row + item.first;
			int check_col = col + item.second;
			if (check_row >= 0 && check_row < board.size() && check_col >= 0 && check_col < board[0].size() && board[check_row][check_col] != -1 && board[check_row][check_col] != board[row][col]){
				path_compression(board, check_row, check_col);
				if (board[check_row][check_col] != board[row][col]){
					neighber_set.insert(board[check_row][check_col]);
					int neigh_father = board[check_row][check_col] ;
					board[neigh_father / board[0].size()][neigh_father % board[0].size()] = board[row][col];
				}
			}
		}
		return neighber_set.size();
	}
	void path_compression(vector<vector<int>>& board, int row, int col){
		int father = board[row][col];
		while(board[row][col] != board[father/board[0].size()][father % board[0].size()]){
			board[row][col] = board[father/board[0].size()][father % board[0].size()];
			father = board[row][col] ;
		}
	}
};


int main(){
	vector<pair<int, int>> changes = {{0,1},{1,2},{2,1},{1,0},{0,2},{0,0},{1,1}};
	Solution().numIslands2(3, 3, changes);
}
