class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] shuffleArray = new int[2*n];
        int k=0;
        int i=0,j=n;
        
        while(i<n && j<2*n){
            shuffleArray[k++] = nums[i++];
            shuffleArray[k++] = nums[j++];
        }
        
        return shuffleArray;
    }
}