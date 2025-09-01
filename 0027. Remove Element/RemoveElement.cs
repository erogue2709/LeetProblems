public class Solution {
    public int RemoveElement(int[] nums, int val) {
        if(nums.Length==0)
            return 0;
        if(nums.Length==1)
            return nums[0]==val?0:1;

        int k = 0;
        for(int idx = nums.Length-1; idx >= 0; idx--)
        {
            if(nums[idx] == val)
                nums[idx] = nums[nums.Length - ++k];
        }
        return nums.Length-k;
    }
}