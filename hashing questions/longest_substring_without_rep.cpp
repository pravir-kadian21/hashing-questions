class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 0;
	set<int> st;
	int left = 0;
	int right = 0;

	for (int i = 0; i < s.length(); i++)
	{
		while (st.find(s[right]) != st.end())
		{
			auto it = st.find(s[left]);
			st.erase(it);
			left++;
		}
		len = max(len, right - left + 1);
		st.insert(s[right]);
		right++;
	}
        return len;
    }
};