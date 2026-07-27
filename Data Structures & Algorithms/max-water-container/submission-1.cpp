class Solution {
   public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int r = heights.size() - 1;
        int maxCapacity = 0;
        while(l < r){
          int capacity = min(heights[l], heights[r]) * abs(r-l);
          if(maxCapacity < capacity){
            maxCapacity = capacity;
          }
          if(heights[l] < heights[r]){
            ++l;
          }else{
            --r;
          }
        }
        return maxCapacity;
    }
};
