class Solution {
public:
    
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        
        int j=0;
        while(s[j]==' '){
            j++;
        }
        s = s.substr(j);
        
        j = s.size()-1;
        while(s[j]==' ')
            j--;
        s = s.substr(0, j+1);
        
        int start = 0;
        int i=0;
        bool flag = false;
        while(i<s.size()){
            s[start]=s[i];
            while(i<s.size() && s[i]==' '){
                flag=true;
                i++;
            } 
            start++;
            if(flag==false)
                i++;
            flag=false;
        }
        
        cout<<s.substr(0, start)<<endl;
        s=s.substr(0, start);
        start=0;
        int end;
        
        cout<<s<<endl;
        for(i=0;i<s.size();i++){
            if(s[i]==' ' || i==s.size()-1){
                //reverse start-(i-1)
                end = (i==s.size()-1)?i: i-1;
                while(start<end){
                    char temp = s[start];
                    s[start] = s[end];
                    s[end] = temp;
                    start++;
                    end--;
                }
                start=i+1;
            }
        }
        while(start<end){
                    char temp = s[start];
                    s[start] = s[end];
                    s[end] = temp;
                    start++;
                    end--;
                }
        
        cout<<s;
        
        return s;
    }
};