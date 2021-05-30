class Solution {
public:
    int maximumGap(vector<int> &num) {
        int sSize = num.size();
        int i, res =0;
        int minV, maxV;
        int bucket_size, bucket_num, bucket_id;
        int maxGap = INT_MIN;
        int last_max;

        if(sSize>1)
        {
            minV =  maxV = num[0];
            for(i=1; i<sSize; i++)
            {
                if(minV > num[i]) minV = num[i];
                else if(maxV < num[i]) maxV = num[i];
            }

            bucket_size = max(1, (maxV - minV )/ (sSize - 1));
            bucket_num  = (maxV - minV)/bucket_size + 1;

            if(bucket_num <=1) return (maxV - minV); 
            vector<int> bucket_max(bucket_num, INT_MIN);
            vector<int> bucket_min(bucket_num, INT_MAX);
            vector<int> bucket_count(bucket_num, 0);

            for(i=0; i<sSize; i++)
            {
                bucket_id = (num[i] - minV)/bucket_size;
                bucket_count[bucket_id]++;
                bucket_min[bucket_id] = bucket_min[bucket_id] > num[i]? num[i]:bucket_min[bucket_id];
                bucket_max[bucket_id] = bucket_max[bucket_id] < num[i]? num[i]:bucket_max[bucket_id];
            }

            last_max = minV;
            for(i=0; i<bucket_num; i++)
            {
                if(bucket_count[i]>0)
                {
                    maxGap = max(maxGap, bucket_min[i]- last_max);
                    last_max = bucket_max[i];
                }
            }
            return maxGap;
        }
        return 0;
    }
};