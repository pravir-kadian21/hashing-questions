class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int len = 0;
        unordered_map<char,int>m;
        
        while(right<s.length()){
            if(m.find(s[right])==m.end()){
                m[s[right]]=right;
                len = max(len,right-left+1);
                right++;
            }
            else{
                auto it1 = m.find(s[right]);
                int new_left = it1->second+1;
                for(int i=left;i<new_left;i++){
                    auto it = m.find(s[i]);
                    m.erase(it);
                }
                left = new_left;
            }
        }
        return len;
    }
};