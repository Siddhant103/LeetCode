class Solution {
public:
    vector<int> threeEqualParts(vector<int>& A) {
        vector<int> res;  
        int n = A.size();
        int zeros = 0; // number of zero at the end
        int nums = 0; // total number of one
        
        // get number of zero at the end
        for(int i = n - 1; i >= 0;i--)
        {
            if(A[i] == 1) break;
            zeros++;
        }
        // get total number of one
        for(int i = 0;i < n;i++)
        {
            if(A[i] == 1) nums++;
        }
        
        // all data in this array is 0, we can divide the array at every place
        if(nums == 0)
        {
            return {0, n - 1};
        }
        
        // the total number of 1 can't be divided by 3. return false.
        if(nums % 3) return {-1, -1};

        int count = nums / 3;
        string target;
                
        // check if the array can be split into 3 parts
        // each parts has (ones/3)'s 1, and has (zeros)'s 0 at at the end
        int i = 0;
        for(int k = 0; k < 3;k++)
        {
            string str;
            int one_nums = 0;
            int zero_nums = 0;
            for(;i < n; i++)
            {
                if(one_nums == count && zero_nums == zeros) break;
                if(A[i] == 0)
                {
                    if(one_nums == count)
                    {
                        zero_nums++;
                    }
                    if(!str.empty()) // skip the leading 0.
                        str.push_back(A[i]);
                }
                else if(A[i] == 1)
                {
                    if(one_nums == count) // the number of 0 at the end is not match
                    {
                        return {-1, -1};
                    }
                    one_nums++;
                    str.push_back(A[i]);
                }   
            }

            if(target.empty())
            {
                target = str;
            }
            else
            {
                if(target != str) return {-1, -1};  // current part and last part is not match             
            }
            if(k == 0) res.push_back(i - 1); // record the index
            else if(k == 1) res.push_back(i);
        }
        
        return res;
    }
};