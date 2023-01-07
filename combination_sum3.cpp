class Solution {
public:
    vector<vector<int>>valid_pair;
    void make_pair(int u,int k,int n,vector<int>pair,int sum) {
        if(pair.size()==k and sum==0) {
           valid_pair.push_back(pair);
           return;
        }
        for(int i=u;i<=9;i++) {
              pair.push_back(i);
              make_pair(i+1,k,n,pair,sum-i);
              pair.pop_back();     
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<int>pair;
         make_pair(1,k,n,pair,n);
         return valid_pair;
    }
};
