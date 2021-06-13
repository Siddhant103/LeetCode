class ProductOfNumbers {
    vector<int> prefixProduct = {1};
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num != 0){
            prefixProduct.push_back(prefixProduct.back() * num);
        } else{
            prefixProduct = {1};
        }
    }
    
    int getProduct(int k) {
        if(k < prefixProduct.size()){
            return prefixProduct.back()/prefixProduct[prefixProduct.size() - k - 1];
        }
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */