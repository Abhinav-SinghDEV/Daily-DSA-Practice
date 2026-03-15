class Fancy {
private:
    const int MOD = 1e9+7;
    vector<long long> v;
    long long a,b;
    long long modpow(long long x, long long y, long long MOD){
        long long res = 1;
        x = x%MOD;
        while(y>0){
            if(y%2 == 1) res = (res*x)%MOD;
            y = y/2;
            x = (x*x)%MOD;
        }
        return res;
    }
public:
    Fancy() {
        a = 1, b = 0;
    }
    
    void append(int val) {
        long long x = (val - b + MOD) % MOD;
        this->v.push_back((x * modpow(a, MOD-2, MOD)) % MOD);
    }
    
    void addAll(int inc) {
        b = (b+inc)%MOD;
    }
    
    void multAll(int m) {
        a = (a*m)%MOD;
        b = (b*m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= v.size()) return -1;
        return (a*v[idx]+b)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
