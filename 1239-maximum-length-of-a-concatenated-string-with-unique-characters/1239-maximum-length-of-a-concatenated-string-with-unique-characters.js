var maxLength = function(arr) {
    const getMax = function(arr, index, res) {
        if(index === arr.length)
            return 0;
        
        let take = 0, notTake = 0, set = new Set(res + arr[index]);
        
        if(set.size === res.length + arr[index].length)
        {
            take = arr[index].length + getMax(arr, index + 1, res + arr[index]);
        }
        
        notTake = getMax(arr, index + 1, res);
        
        return Math.max(take, notTake);
    }
    return getMax(arr, 0, "")
};