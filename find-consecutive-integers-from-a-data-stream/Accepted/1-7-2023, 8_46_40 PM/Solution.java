// https://leetcode.com/problems/find-consecutive-integers-from-a-data-stream

class DataStream {
    
    int val, k, matched = 0;
    public DataStream(int value, int k) {
        this.val = value;
        this.k = k;
    }
    
    public boolean consec(int num) {
        if(num==this.val){
            this.matched++;
            if(this.matched>=k) return true;
            return false;
        }
        this.matched = 0;
        return false;
        
    }
}

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream obj = new DataStream(value, k);
 * boolean param_1 = obj.consec(num);
 */