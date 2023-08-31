// Interval to define the boundaries of a tap
struct Interval {
    int start;
    int end;
    Interval(int start,int end) {
        this->start=start;
        this->end=end;
    }
};

// Sort on the basis of increasing starting points and decreasing endin points
bool compare(const Interval* i1,const Interval* i2) {
    if (i1->start!=i2->start) 
        return i1->start<i2->start;
    else
        return i1->end>i2->end;
}

class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
	
		// Vector of Intervals
        vector<Interval*> A(n+1);
        for (int i=0;i<ranges.size();i++) {
            A[i]=new Interval(max(i-ranges[i],0),min(i+ranges[i],n));
        }
        sort(A.begin(),A.end(),compare);
		
        int cnt=0;
        int i=0;
		
		// Max watered area until now
        int watered=A[i]->end; 
       
	   cnt++;
		
		// If first tap can't water the interval starting from 0 no one can
        if (A[i]->start>0)
            return -1;
			
		// If first tap is sufficient
        if (watered>=n)
            return 1;
        //last watered tap
		int j=0;
       // find the next optimal tap
	   i=1;
	   
        while (j<n+1 && watered<n) {
            int nextTap=-1;
            while (i<n+1 && watered<n) {
			    // Ignore if watering less area
                if (A[i]->end<=watered) {
                    i++;
                } else if (A[i]->end>watered) {
					// check if maintains continuity
                    if (A[i]->start<=A[j]->end) {
                        nextTap=i; // probable next tap
                        watered=A[i]->end;  // Update the max area watered
                        i++;
                    } else {
                        break; // Moving further will cause discontinuity
                    }
                }
            }
            if (nextTap==-1)  // No tap can maintain the continuity
                return -1;
            cnt++;
            j=nextTap; // next optimal tap
            
        }
        return cnt; 
    }
};