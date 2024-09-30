// 1381. Design a Stack With Increment Operation

class CustomStack {
public:
    // Array + Lazy Propagation
    // working of lazy increment, it increase one by one,[lazy,like me]
    // being lazy peoples have more power!
    // i will improving every single day!
    // date [30,sep,2024]
    // we will meet again!

    vector<int> st;
    vector<int> LazyIncrement;
    int n;
    CustomStack(int maxSize) {
        n = maxSize;
    }
    
    void push(int x) {
        // maximum length [limit me hai, then only push new element]
         if(st.size() < n){
            st.push_back(x);
            // there is no increment, so we have to add only zero (0).
            LazyIncrement.push_back(0);
         }
    }
    
    int pop() {
      // there is no more element into stack,return -1;
      // stk.pop(); return -1 --> Stack is empty return -1.
        if(st.size() == 0){
            return -1;
        }
        
        int currIndex = st.size() - 1;
        if(currIndex > 0){
            // update the privours using currentValue
            // pop the currentValue 
            LazyIncrement[currIndex-1] += LazyIncrement[currIndex];
        }

        // Now, remove the element into top
        int removeElement = st[currIndex] + LazyIncrement[currIndex];
        st.pop_back();
        LazyIncrement.pop_back();
        return removeElement;
    }
    
    void increment(int k, int val) {

        //Note that input might contain K which is greater than st.size()
        int currIndex = min(k,(int)st.size()) - 1;
        // bas us index par increment value ko insert kar do 
        // kis value ko ? increment wali value of 
        // no need increment all the elements in the stack. just need to increment only one element
        // we will apply Lazy Propagations
        if(currIndex >= 0){
            LazyIncrement[currIndex] += val;
        } 
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */






