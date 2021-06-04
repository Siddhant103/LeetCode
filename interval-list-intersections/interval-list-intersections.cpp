class Solution {
public:
    vector<int> getIntersection(vector<int>& first, vector<int> second){
        vector<int> intersection(4);
        //total 4 cases
        //1. first included in second
        //2. second included in first
        //3. first ending before second
        //4. second ending before first
        cout << "getIntesection\n";
        if(first[0] >= second[0] && first[1] <= second[1]) {
            intersection[0] = first[0];
            intersection[1] = first[1];
            intersection[2] = 1;
            intersection[3] = 0;
        } else if(second[0] >= first[0] && second[1] <= first[1]){
            intersection[0] = second[0];
            intersection[1] = second[1];
            intersection[2] = 0;
            intersection[3] = 1;
        } else if(second[0] > first[0] && second[1] > first[1]){
            intersection[0] = second[0];
            intersection[1] = first[1];
            intersection[2] = 1;
            intersection[3] = 0;
        } else if(first[0] > second[0] && first[1] > second[1]){
            intersection[0] = first[0];
            intersection[1] = second[1];
            intersection[2] = 0;
            intersection[3] = 1;
        }
        cout << intersection[0] << " " << intersection[1] << " " << intersection[2] << " " << intersection[3] <<endl;
        return intersection;
    }
    
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        
        vector<vector<int>> result;
        int i = 0, j = 0;
        
        while(i < firstList.size() && j < secondList.size()){
            cout << i << " " << j << endl;
            if(firstList[i][1] < secondList[j][0]){
                i++;
            } else if(firstList[i][0] > secondList[j][1]){
                j++;
            } else{
                cout << "Intersection\n";
                vector<int> intersection = getIntersection(firstList[i], secondList[j]);
                result.push_back({intersection[0], intersection[1]});
                i += intersection[2];
                j += intersection[3];
            }
        }
        
        return result;
    }
};