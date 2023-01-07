class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) { 
        int n=nums.size(); 
        stack<int>st;
        int a=INT_MAX,b=INT_MIN;
        for(int i=0;i<n;i++){
             while(!st.empty() and st.top()>nums[i]){
                  st.pop();
                  a=min(a,(int)st.size());
             }
            st.push(nums[i]);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
             while(!st.empty() and st.top()<nums[i]){
                  st.pop();
                  b=max(b,n-(int)st.size());
             }
            st.push(nums[i]);
        }
        if(b==INT_MIN) return 0;
        return b-a;
    }
};

