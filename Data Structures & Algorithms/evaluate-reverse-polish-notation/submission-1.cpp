class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //Make a stack
        //Then introduce the elements in the stack
        //If the element is a operator do the operation with the last 2 values
        //Insert the result
        stack<int> calculations;
        for(const string& value : tokens){
            int num1 = 0;
            int num2 = 0;
            if(value == "+"){
                num2 = calculations.top();
                calculations.pop();
                num1 = calculations.top();
                calculations.pop();
                calculations.push(num1+num2);
            }
            else if(value == "-"){
                num2 = calculations.top();
                calculations.pop();
                num1 = calculations.top();
                calculations.pop();
                calculations.push(num1-num2);
            }
            else if(value == "/"){
                num2 = calculations.top();
                calculations.pop();
                num1 = calculations.top();
                calculations.pop();
                calculations.push(num1/num2);
            }
            else if(value == "*"){
                num2 = calculations.top();
                calculations.pop();
                num1 = calculations.top();
                calculations.pop();
                calculations.push(num1*num2);
            }
            else{
                calculations.push(stoi(value));
            }
        }
        return calculations.top();
    }
};
