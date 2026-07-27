class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int rigth = numbers.size()-1;
        int sum = numbers[left] + numbers[rigth];
        while (sum != target){
            if(sum > target){
                rigth--;
            }
            else{
                left++;
            }
            sum = numbers[left] + numbers[rigth];
        }
        return {left+1, rigth+1};

    }
};
