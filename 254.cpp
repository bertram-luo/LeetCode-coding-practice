#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
	vector<vector<int>> combinations;
	vector<int> combination;
	vector<int> candidates;
	public:
	vector<vector<int>> getFactors(int n) {
		getFactor(n);
		if (candidates.size() == 0) return combinations;
		sort(candidates.begin(), candidates.end());
		combinationProduct(n, 0);
		return combinations;
	}
	void getFactor(int n){
		int root = sqrt(n);
		for(int i = 2; i <= root; ++i){
			if (n % i == 0){
				candidates.push_back(i);
				if (i != root)
				candidates.push_back(n / i);
			}
		}
	}
	void combinationProduct(int target, int s_pos){
		for(int i = s_pos; i < candidates.size() && target >= candidates[i]; ++i){
			if (i == s_pos || candidates[i] != candidates[i-1]){
				if (target % candidates[i] == 0){
					combination.push_back(candidates[i]);
					if (target == candidates[i]){
						combinations.push_back(combination);
					}else{
						combinationProduct(target / candidates[i], i);
					}
					combination.pop_back();
				}
			}
		}
	}

};

int main(){
	vector<vector<int>> res = Solution().getFactors(pow(2, 22));
	cout << res.size() << endl;
	for(auto& item : res){
		copy(item.begin(), item.end(), ostream_iterator<int>(cout, "\t"));
		cout << endl;
	}
}
