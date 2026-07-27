class Solution {
public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;
        int minimum = nums[0];

        while(r >= l){
            
            if(nums[l] < nums[r]){
                if(nums[l] < minimum){
                    minimum = nums[l];
                }
                break;
            }
            int m = l + (r-l)/2;
            if(nums[m] < minimum){
                minimum = nums[m];
            }
            if(nums[l] <= nums[m]){
                l = m + 1;
            }else{
                r = m-1;
            }
        }
       return minimum;
    }
};
