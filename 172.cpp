//Factorial Trailing Zeroes
class Solution {
	public:
		int trailingZeroes(int n) {
			int tz = 0;

			while( n > 0){
				tz += n/5;
				n /=5;
			}
			return tz;
		}
};
