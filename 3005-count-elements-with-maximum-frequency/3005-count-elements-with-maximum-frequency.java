class Solution {
    public int maxFrequencyElements(int[] nums) {
        Map<Integer, Integer> m = new HashMap<>();
        int maxCount = 0;
        for (int num: nums) {
            m.put(num, m.getOrDefault(num, 0) + 1);
            if (m.get(num) > maxCount) {
                maxCount = m.get(num);
            }
        }
        int result = 0;
        for (int num: nums) {
            if (m.get(num) == maxCount) {
                result += maxCount;
                m.put(num, 0);
            }
        }
        
        return result;
    }
}