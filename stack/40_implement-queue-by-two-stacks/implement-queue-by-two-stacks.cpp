/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/implement-queue-by-two-stacks
@Language: C++
@Datetime: 16-06-20 04:03
*/

class Queue {
public:
    stack<int> stack1;
    stack<int> stack2;

    Queue() {
        // do intialization if necessary
    }

    void push(int element) {  
        // write your code here  
        while (stack2.size() > 0)  
        {  
            stack1.push(stack2.top());  
            stack2.pop();  
        }  
          
        stack1.push(element);  
    }  
      
    int pop() {  
          
        while (stack1.size() > 0)  
        {  
            stack2.push(stack1.top());  
            stack1.pop();  
        }  
          
        if (stack2.size() > 0)  
        {  
            int tmp = stack2.top();  
            stack2.pop();  
            return tmp;  
        }  
          
        return -1;  
        // write your code here  
    }  
  
    int top() {  
          
        while (stack1.size() > 0)  
        {  
            stack2.push(stack1.top());  
            stack1.pop();  
        }  
          
        if (stack2.size() > 0)  
        {  
            return stack2.top();  
        }  
          
        return -1;  
        // write your code here  
    } 
    
};

//两个栈，stack1用来存push进来的元素，stack2用来存准备要pop出去的元素。push没什么好说的，pop操
//时，如果stack2里面有东西，直接pop就好了，没有的话，把stack1的所有元素全存进来，再pop
