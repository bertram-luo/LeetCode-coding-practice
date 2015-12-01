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
			num_islands = num_islands + 1 - merge(board, item.first, item.second);
			res.push_back(num_islands);
		}
		return res;
	}
	// root tree containing neighbour node to self
	// not as efficienty as rooting lower tree to higher tree, modified for simplicity
	int merge(vector<vector<int>>& board, int row, int col){
	        board[row][col] = row * board[0].size() + col;
		set<int> neighbour_set;
		for(auto& item : directions){
			int check_row = row + item.first;
			int check_col = col + item.second;
			if (check_row >= 0 && check_row < board.size() && check_col >= 0 && check_col < board[0].size() && board[check_row][check_col] != -1 && board[check_row][check_col] != board[row][col]){
				path_compression(board, check_row, check_col);
				if (board[check_row][check_col] != board[row][col]){
					neighbour_set.insert(board[check_row][check_col]); // there may be neighbours share root;
					int neigh_father = board[check_row][check_col] ;
					board[neigh_father / board[0].size()][neigh_father % board[0].size()] = board[row][col]; // neighbour -> neighbour'root-> self
				}
			}
		}
		return neighbour_set.size(); // num of unique trees containing neighbour node
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
