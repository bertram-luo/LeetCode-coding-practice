//N-Queens
class Solution {
	public:
		vector<vector<string>> solveNQueens(int n) {
			vector<vector<string>> res;
			if (n == 0) return res;
			vector<string> instance;
			totalNQueens(res, instance, n);
			return res;
		}
		void totalNQueens(vector<vector<string>>& res, vector<string>& instance, int n_column){
			if (instance.size() == n_column){
				res.push_back(instance);
				return;
			}
			for(int i = 0; i < n_column; ++i){
				if (placeable(instance, instance.size(), i)){
					instance.push_back(gen_row(i, n_column));
					totalNQueens(res, instance, n_column);
					instance.pop_back();
				}
			}
		}
		string gen_row(int col, int n_column){
			string this_row;
			for(int j = 0; j < n_column; ++j){
				if (col == j){
					this_row += 'Q';
				} else {
					this_row += '.';
				}
			}
			return this_row;
		}
		bool placeable(vector<string>& instance, int row, int col){
			for(int i = 0; i < instance.size(); ++i){
				if (instance[i][col] == 'Q' || (abs(row - i) == abs(col - (int)(instance[i].find('Q'))))){
					return false;
				}
			}
			return true;
		}
};
