//N-Queens II
class Solution {
	public:
		int totalNQueens(int n) {
			int res = 0;
			if (n == 0 || n == 1) return n;
			vector<int> instance;
			totalNQueens(instance, 0, n, res);
			return res;
		}
		void totalNQueens(vector<int>& instance, int s_index, int t_index, int& count){
			if (instance.size() == t_index){
				++count;
				return;
			}
			for(int i = 0; i < t_index; ++i){
				if (placeable(instance, instance.size(), i)){
					instance.push_back(i);
					totalNQueens(instance, s_index, t_index, count);
					instance.pop_back();
				}
			}
		}
		bool placeable(vector<int>& instance, int row, int col){
			for(int i = 0; i < instance.size(); ++i){
				if (col == instance[i] || (abs(row - i) == abs(col - instance[i]))){
					return false;
				}
			}
			return true;
		}
};
