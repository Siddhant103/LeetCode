class Solution {
public:
    vector<int> getSumCarry(char a, char b, int c){
        int sum = a-'0' + b-'0' + c;
        
        if(sum == 3){
            return {1, 1};
        } else if(sum == 2){
            return {0, 1};
        } else if(sum == 1){
            return {1, 0};  
        } else{
            return {0, 0};
        }
    }
    string addBinary(string a, string b) {
        int m = a.size();
        int n = b.size();
        
        if(m == 0 && n == 0){
            return "";
        }
        
        if(m == 0)
            return b;
        if(n == 0)
            return a;
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        int carry = 0;
        int i = 0, j = 0;
        string ans = "";
        while(i<m && j<n){
            vector<int> sumCarry = getSumCarry(a[i], b[j], carry);
            cout << sumCarry[0] << " "  << sumCarry[1]<<endl;
            ans += to_string(sumCarry[0]);
            carry = sumCarry[1];
            i++;
            j++;
        }
        
        while(i<m){
            vector<int> sumCarry = getSumCarry(a[i], '0', carry);
            cout << sumCarry[0] << " "  << sumCarry[1]<<endl;
            ans += to_string(sumCarry[0]);
            carry = sumCarry[1];
            i++;
        }
        while(j<n){
            vector<int> sumCarry = getSumCarry('0', b[j], carry);
            cout << sumCarry[0] << " "  << sumCarry[1]<<endl;
            ans += to_string(sumCarry[0]);
            carry = sumCarry[1];
            j++;
        }
        if(carry == 1){
            ans += "1";
        }
        
        cout<<ans;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};