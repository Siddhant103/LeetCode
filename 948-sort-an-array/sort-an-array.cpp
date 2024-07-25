class Solution {
public:
    void mergeSort(vector<int>& arr)
    {
        int n = arr.size();
        if(n==1)
        return;
        vector<int> l(n/2);
        vector<int> r(n-(l.size()));
        for(int i=0;i<n/2;i++)
        l[i] = arr[i];
        for(int i=n/2;i<n;i++)
        r[i-n/2] = arr[i];
        mergeSort(l);
        mergeSort(r);
        merge(l,r,arr);
    }
    void merge(vector<int>& l,vector<int>& r,vector<int>& arr)
    {
        int ptr1=0,ptr2=0,k=0;
        while(ptr1<l.size() && ptr2<r.size())
        {
            if(l[ptr1]<=r[ptr2])
            {
                arr[k++] = l[ptr1++];
            }
            else
            {
                arr[k++] = r[ptr2++];
            }
        }
        while(ptr1<l.size())
        {
            arr[k++] = l[ptr1++];
        }
        while(ptr2<r.size())
        {
            arr[k++] = r[ptr2++];
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums);
        return nums;
    }
};