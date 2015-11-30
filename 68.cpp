//Text Justification
class Solution {
	public:
		vector<string> fullJustify(vector<string>& words, int maxWidth) {
			vector<string> res;
			if (maxWidth == 0){
				res.push_back("");
				return res;
			}

			int s_index = 0;
			while(s_index < words.size()){
				int t_index = s_index;
				int line_count = 0;
				while((t_index< words.size()
							&& (line_count + words[t_index].size() + 1)<= maxWidth)){
					line_count+= (words[t_index++].size() + 1);
				}

				if (t_index >= words.size()
						|| (line_count + words[t_index].size()) > maxWidth) {
					--t_index;
				}

				int k_count = 0;
				for(int i = s_index; i <= t_index; ++i){
					k_count += words[i].size();
				}

				int num_words = t_index - s_index + 1;
				int num_space_slots = num_words - 1;
				int num_space_slots_left = num_space_slots;

				string this_line;
				for(int i = 0; i < num_words; ++i){
					this_line += words[s_index + i];
					if (num_space_slots_left-- > 0){
						int num_spaces = 1;
						if (t_index< words.size() - 1){
							num_spaces = (maxWidth - k_count)/num_space_slots + (i < (maxWidth - k_count) % num_space_slots ? 1 : 0);
						}
						this_line += string(num_spaces, ' ');
					} 
				}

				while(this_line.size() < maxWidth){
					this_line += " ";
				}

				res.push_back(this_line);
				s_index = t_index + 1;
			}
			return res;
		}
};
