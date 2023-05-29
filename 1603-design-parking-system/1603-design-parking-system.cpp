class ParkingSystem {
    int big, medium, small;
    int b,m,s;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
        b = 0;
        m = 0;
        s = 0;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(b<big){
                cout<<b<<endl;
                b++;
                return true;
            } else{
                return false;
            }
        } else if(carType == 2){
            if(m<medium){
                cout<<m<<endl;
                m++;
                return true;
            } else{
                return false;
            }
        } else{
            if(s<small){
                cout<<s<<endl;
                s++;
                return true;
            } else{
                return false;
            }
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */