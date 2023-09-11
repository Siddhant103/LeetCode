class Solution {
public:
    string getHint(string secret, string guess) {
        vector<int>tb_guess(10),tb_secret(10);
        int A=0,B=0;
        for (int i=0;i<secret.size();++i){
            if (secret[i]==guess[i]) A++;
            else {
                tb_guess[guess[i]-'0']++;
                tb_secret[secret[i]-'0']++;
            }
        }
        for (int i=0;i<10;++i){
            B=B+ min(tb_guess[i],tb_secret[i]);
        }
        return to_string(A)+'A'+to_string(B)+'B';
    }
};