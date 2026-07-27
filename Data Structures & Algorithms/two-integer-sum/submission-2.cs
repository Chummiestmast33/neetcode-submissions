public class Solution {
    public int[] TwoSum(int[] nums, int target) {
        Dictionary<int,int> numeros = new Dictionary<int,int>();
        for(int i = 0; i < nums.Length; i++){
            if(numeros.ContainsKey(target - nums[i])){
                return [numeros[target-nums[i]],i];
            }
            numeros.Add(nums[i],i);
        }
        return[];
    }
}
