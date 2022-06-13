
public class count_subarrays_with_score_less_than_k {
    public static void main(String[] args) {
        int[] nums = {1,1,1,};
        int k = 5;
        countSubarrays(nums, k);
    }
    public static long countSubarrays(int[] nums, long k) {
        long[] arr = new long[nums.length];
        int startIndex = 0;
        long count = 0;
        long tempSum = 0L;
        for (int i = 0; i < nums.length; i++) {
            if (startIndex == i) {
                if (nums[i] < k) {
                    count++;
                    tempSum += nums[i];
                } else {
                    startIndex++;
                }
            } else {
                tempSum += nums[i];
                while (tempSum * (i - startIndex + 1) >= k) {
                    tempSum -= nums[startIndex++];
                }
                count += (i - startIndex + 1);
            }
        }
        return count;
    }
}
