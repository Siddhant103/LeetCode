class Solution {
public:
    int maximum69Number (int num) {
        int revNum=0;
        int temp=num;
        while(temp){
            revNum=revNum*10+temp%10;
            temp/=10;
        }
        cout<<revNum;
        temp=0;
        int flag=0;
        while(revNum){
            int n = revNum%10;
            if(n==6 && flag==0){
                flag=1;
                n=9;
            }
            temp=temp*10 + n;
            revNum/=10;
        }
        return temp;
    }
};