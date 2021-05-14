/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int row = binaryMatrix.dimensions()[0];
        int col = binaryMatrix.dimensions()[1];
        
        int j = col-1;
        
        for(int i=0;i<row;i++){
            while(j>=0 && binaryMatrix.get(i, j)==1){
                j--;
            }
        }
        
        return j==col-1? -1 : j+1;
    }
};