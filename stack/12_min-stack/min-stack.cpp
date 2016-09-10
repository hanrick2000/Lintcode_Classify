/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/min-stack
@Language: C++
@Datetime: 16-07-12 01:59
*/

// class MinStack {
// public:
//     MinStack() {
//     }
 
//     void push(int number) {
//         s.push(number);
//         if(m.empty() || number <= m.top())
//             m.push(number);
//     }
 
//     int pop() {
//         int val = s.top();
//         s.pop();
//         if(val==m.top()) m.pop();
//         return val;
//     }
 
//     int min() {
//         return m.top();
//     }
// private:
//     stack<int> s;
//     stack<int> m;
// };


class MinStack {
public:
    MinStack() {
    }
 
    void push(int number) {
    s.push(number);
    if(m.empty()||number<=m.top())
    m.push(number);

    }
 
    int pop() {
    int val=s.top();
    s.pop();
    if(val==m.top())
    m.pop();
    return val;
    }
    
    int min() {
    return m.top();
    }
private:

stack<int>s;//for the main stack
stack<int>m;//for the min stack

};
