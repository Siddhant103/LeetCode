class Solution {
    public String customSortString(String order, String s) {
        Map<Character, Integer> sCount = new HashMap<>();
        for (char currChar: s.toCharArray()) {
            sCount.put(currChar, sCount.getOrDefault(currChar, 0) + 1);
        }
        
        StringBuilder result = new StringBuilder();
        for (char currChar: order.toCharArray()) {
            if (sCount.containsKey(currChar)) {
                int freq = sCount.get(currChar);
                while (freq-- > 0) {
                    result.append(currChar);
                }
                sCount.put(currChar, 0);
            }
        }
        
        for (char currChar: s.toCharArray()) {
            if (sCount.get(currChar) != 0) {
                result.append(currChar);
                sCount.put(currChar, sCount.get(currChar) - 1);
            }
        }
        
        return result.toString();
    }
}