class Solution {
public:
    // Utility method to form the integer format string of the given string
    string getSum(string s) {
        string sum = "";
        for (char c: s) {
            sum += to_string(c - 'a');
        }
        return sum;
    }
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        // Using the utility function to calculate number string and then converting string to number
        return stoi(getSum(firstWord)) 
            + stoi(getSum(secondWord)) 
            == stoi(getSum(targetWord));
    }
};