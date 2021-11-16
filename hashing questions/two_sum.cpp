class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>v;
        unordered_map<int,int>m;
        for(int i=0;i<nums.size();i++){
            int key = target-nums[i];
            auto it = m.find(key);
            if(it==m.end()){
                m[nums[i]]=i;
            }
            else{
                
                v.push_back(i);
                v.push_back(it->second);
                break;
            }
        }
        return v;
    }
};