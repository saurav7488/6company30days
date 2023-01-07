class Solution {
public:
    int evalRPN(vector<string>& tokens) {
         stack<int>number;
         for(auto it:tokens) {
             if(it=="+") {
                 int num1=number.top();
                 number.pop();
                 int num2=number.top();
                 number.pop();
                 number.push(num1+num2);
             }
             else if(it=="-"){ 
                 int num1=number.top();
                 number.pop();
                 int num2=number.top();
                 number.pop();
                 number.push(num2-num1);
             }
             else if(it=="*") {
                 int num1=number.top();
                 number.pop();
                 int num2=number.top();
                 number.pop();
                 number.push(num2*num1);
             }
             else if(it=="/") {
                 int num1=number.top();
                 number.pop();
                 int num2=number.top();
                 number.pop();
                 number.push(num2/num1);
             }
             else {
                 number.push(stoi(it));
             }
         }
         return number.top();
    }
};