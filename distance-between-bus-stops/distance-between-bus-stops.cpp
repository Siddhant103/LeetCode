class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int d1=0,d2=0;
        int n = distance.size();
        int s=start,d=destination;
        while(s != destination){
            d1+=distance[s];
            s++;
            s=s%n;
        }
        while(d != start){
            d2+=distance[d];
            d++;
            d%=n;
        }
        return min(d1,d2);
    }
};