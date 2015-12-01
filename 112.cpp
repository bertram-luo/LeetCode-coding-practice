#include <vector>
#include <iostream>
using namespace std;
class SolutionRecursive {
	public:
		vector<vector<int>> subsetsWithDup(vector<int>& nums) {
			sort(nums.begin(), nums.end());
			vector<vector<int>> res;
			res.push_back(vector<int>());
			for(int set_size = 1; set_size <= nums.size(); ++set_size){
				vector<int> instance(set_size, -1);
				subsets(res, nums, instance, 0, 0);
			}
			return res;
		}
		void subsets(vector<vector<int>>&res, vector<int>&nums, vector<int>& instance, int s_pos, int des_pos){
			for(int i = s_pos; i < nums.size(); ++i){
				if (i == s_pos || nums[i] > nums[i-1]){
					instance[des_pos] = nums[i];
					if (des_pos == instance.size() - 1){
				            res.push_back(instance);
					} else {
					    subsets(res, nums, instance, i + 1, des_pos + 1);
					}
				} 
			}
		}
};
int main(){
	vector<int> input = {1, 2, 2};
	auto res = Solution().subsetsWithDup(input);
	for(auto& item  : res){
		copy(item.begin(), item.end(), ostream_iterator<int>(cout, "\t"));
		cout << endl;
	}
}
