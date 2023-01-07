class Solution {
public:
    string getHint(string secret, string guess) {
         int bulls=0,cows=0,n=secret.size();
         map<char,int>s_bulls;
         for(int i=0;i<n;i++) { 
             if(secret[i]==guess[i]) {
                 cows++;secret[i]=guess[i]='+';
             }
             else {
                 s_bulls[secret[i]]++;
             }
         }
         for(auto it:guess) { 
             if(it!='+' and s_bulls[it]>0) { 
                 bulls++;s_bulls[it]--;
             }
         }
         string a=to_string(bulls);
         string b=to_string(cows);
         return b+"A"+a+"B";
    }
};
