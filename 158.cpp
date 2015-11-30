int read4(char *buf);

class Solution {
	char* _buf;
	int _buf_len;
	int _s_pos;
	public:
	/**
	 *      * @param buf Destination buffer
	 *           * @param n   Maximum number of characters to read
	 *                * @return    The number of characters read
	 *                     */
	Solution() : _buf((char*)malloc(sizeof(char) * 3)), _buf_len(0), _s_pos(0){

	}
	~Solution(){
		delete _buf;
	}
	int read(char *buf, int n) {
		int received_sum = 0;
		if (_buf_len > 0){
			int used_cache = min(_buf_len, n);
			for(int i = 0; i < used_cache; ++i){
				*(buf + i)  = *(_buf + (i + _s_pos) % 3);
			}
			buf += used_cache;
			_s_pos = (_s_pos + used_cache) % 3;
			received_sum += used_cache;
			_buf_len -= used_cache;
			n -= used_cache;
		}
		while(n > 0){
			int current = 0;
			current = read4(buf);
			buf += current;
			received_sum += min(n, current);
			if (current >= n){
				for(int i = current - n - 1; i >=0; --i){
					*(_buf + (_s_pos + _buf_len++) % 3) = *(buf - i - 1);
					*(buf - i - 1) = '\0';
				}
				return received_sum;
			}
			if (current < min(4, n))
				return received_sum;
			n -= 4;
		}
		return received_sum;
	}
};
