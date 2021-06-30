class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int area1 = (ay2 - ay1) * (ax2 - ax1);
        int area2 = (by2 - by1) * (bx2 - bx1);
        
        int total_area = area1 + area2;
        
        if(ay1 > by2 || by1 > ay2) 
            return total_area;
        
        if(ax1 > bx2 || bx1 > ax2)
            return total_area;
        
        int h = 0, w = 0;
        if(ay2 > by2){
            h = by2 - max(ay1, by1);
        } else{
            h = ay2 - max(ay1, by1);
        }
        
        if(ax2 > bx2){
            w = bx2 - max(ax1, bx1);
        } else{
            w = ax2 - max(ax1, bx1);
        }
        
        return total_area - h * w;
    }
};