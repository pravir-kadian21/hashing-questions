class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>ans;
        if(nums.empty()){
            return ans;
        }
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                
                int front = j+1;
                int back = nums.size()-1;
                
                int target2 = target-nums[i]-nums[j];
                
                while(front<back){
                    if(nums[front]+nums[back]<target2){
                        front++;
                    }
                    else if(nums[front]+nums[back]>target2){
                        back--;
                    }
                    else{
                        vector<int>quad;
                        quad.push_back(nums[i]);
                        quad.push_back(nums[j]);
                        quad.push_back(nums[front]);
                        quad.push_back(nums[back]);
                        
                        ans.push_back(quad);
                        
                        while(front<back && nums[front]==quad[2]){
                            front++;
                        }
                        while(front<back && nums[back]==quad[3]){
                            back--;
                        }
                    }
                }
                while(j+1 < nums.size() && nums[j+1]==nums[j]){
                    j++;
                }
            }
            while(i+1 < nums.size() && nums[i+1]==nums[i]){
                i++;
            }
        }
        return ans;
    }
};