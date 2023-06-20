class Solution {
public:
vector<int> getAverages(vector<int>& nums, int k) {
    int n = nums.size();
    int dia=k+k+1,i=0,start=0;
	long long avg=0,avg_ans=0;
    vector<int> out(n,-1);               // creating array with size -1 so that we dont have to push -1 at every step.
    if(n<dia)
           return  out;   
    for(i=0;i<dia;i++)
    {
        avg+=nums[i];
    }
    avg_ans=avg/dia;
    out[i-k-1]=avg_ans;
    while(i<n)
    {
        avg+=nums[i++];
        avg-=nums[start++];
        avg_ans=avg/dia;
        out[i-k-1]=avg_ans;
    }
    return out;
}
};