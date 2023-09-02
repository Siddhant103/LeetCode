typedef long long ll;

class Solution {
public:
    bool can_all_be_repaired(vector<int>& ranks, int cars, long long time) {
        long long total_cars_repaired = 0;
        int ranks_size = ranks.size();
        for(int i=0; i<ranks_size; i++) {
            total_cars_repaired += (long long)sqrt(time/(long long)ranks[i]);
        }
        return total_cars_repaired >= cars;

    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long maxVal = 0;
        int size = ranks.size();
        for (int i=0; i<size; i++) {
            if (maxVal < ranks[i]) {
                maxVal = (long long) ranks[i];
            }
        }

        long long low = 1, high = maxVal*((long long)cars*(long long)cars);

        while (low <= high) {
            long long mid = (low + high) / 2;

            if(can_all_be_repaired(ranks, cars, mid)){
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return high + 1;
    }
};
 