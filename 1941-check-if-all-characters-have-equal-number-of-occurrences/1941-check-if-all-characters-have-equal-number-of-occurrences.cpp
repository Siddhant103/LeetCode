class Solution {
public:
    bool areOccurrencesEqual(string s) {
        vector<int> c(156, 0);
        int threshold = 0;
        
        for (char ch: s) {
            cout << ch;
            c[ch]++;
            cout << c[ch] << " ";
            threshold = (threshold > c[ch]) ? threshold : c[ch];
        }
        
        cout << threshold << endl;
        for (int i=0;i<=155;i++)
            cout<<c[i] << " | ";

        for (int i=97;i<=122;i++) {
            if (!c[i]) {
                continue;
            }
            if (c[i] != threshold) {
                return false;
            }
        }
        
        return true;
    }
};