public class Solution
{
    public void Rotate(int[] nums, int k)
    {
        if (nums.Length < 2 || k == nums.Length || k < 1)
            return;
        k %= nums.Length;
        int[] temps = new int[k];
        for (int i = 0; i < k; i++)
            temps[i] = nums[nums.Length - k + i];
        for (int i = 0; i < nums.Length; i++)
        {
            (temps[i % k], nums[i]) = (nums[i], temps[i % k]);
        }
    }
}
