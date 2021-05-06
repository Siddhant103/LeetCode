class Solution {
    public String[] uncommonFromSentences(String A, String B) {
        HashMap<String, Integer> count = new HashMap<String, Integer>();
        for(String s: (A + " " + B).split(" "))
            count.put(s, count.getOrDefault(s,0)+1);
        
        List<String> result = new LinkedList();
        for(String word: count.keySet()){
            if(count.get(word)==1){
                result.add(word);
            }
        }
        
        return result.toArray(new String[result.size()]);
    }
}