class Solution {
public:
    string sortSentence(string s) {
        priority_queue<pair<int, string>> pq;
        
        stringstream ss(s);
        string word;
        while(ss >> word){
            int wordPos = word[word.size() - 1] - '0';
            string actualWord = word.substr(0, word.size()-1);
            cout << wordPos << " " << actualWord << endl;
            pq.push(make_pair(-wordPos, actualWord));
        }
        
        string result = "";
        while(!pq.empty()){
            result += pq.top().second;
            result += " ";
            pq.pop();
        }
        result = result.substr(0, result.size()-1);
        return result;
    }
};