/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/flatten-nested-list-iterator
@Language: C++
@Datetime: 16-08-31 21:16
*/

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer,
 *     // rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds,
 *     // if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds,
 *     // if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
/*
迭代器一般都是用迭代的方法来解的，而递归一般都需用栈来辅助遍历，
由于栈的后进先出的特性，我们在对向量遍历的时候，
从后往前把对象压入栈中，那么第一个对象最后压入栈就会第一个取出来处理，
我们的hasNext()函数需要遍历栈，并进行处理，如果栈顶元素是整数，直接返回true，
如果不是，那么移除栈顶元素，并开始遍历这个取出的list，还是从后往前压入栈，
循环停止条件是栈为空，返回false.
*/ 
// class NestedIterator {
// public:
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         // Initialize your data structure here.
//         for(int i=nestedList.size()-1;i>=0;i--)//For the stack 
//           s.push(nestedList[i]);
//     }

//     // @return {int} the next element in the iteration
//     int next() {
//         // Write your code here
//         NestedInteger t = s.top(); s.pop();
//         return t.getInteger();
//     }

//     // @return {boolean} true if the iteration has more element or false
//     bool hasNext() {
//         // Write your code here
//         while(!s.empty())
//         {
//             NestedInteger t = s.top();
//             if(t.isInteger()) return true;
//             s.pop();
//             for(int i= t.getList().size()-1;i>=0;i--)
//               s.push(t.getList()[i]);
//         }
//         return false;
//     }
  
// private:
//     stack<NestedInteger> s;
// };

//我们也可以使用deque来代替stack:
class NestedIterator {
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        for (auto a : nestedList) {
            d.push_back(a);
        }
    }

    int next() {
        NestedInteger t = d.front(); d.pop_front();
        return t.getInteger();
    }

    bool hasNext() {
        while (!d.empty()) {
            NestedInteger t = d.front();
            if (t.isInteger()) return true;
            d.pop_front();
            for (int i = 0; i < t.getList().size(); ++i) {
                d.insert(d.begin() + i, t.getList()[i]);
            }
        }
        return false;
    }

private:
    deque<NestedInteger> d;
};


/*
虽说迭代器是要用迭代的方法，但是我们可以强行使用递归来解，
怎么个强行法呢，就是我们使用一个队列queue，
在构造函数的时候就利用迭代的方法把这个嵌套链表全部压平展开，
然后在调用hasNext()和next()就很简单了
*/
// class NestedIterator {
// public:
//     NestedIterator(vector<NestedInteger> &nestedList) {
//         make_queue(nestedList);
//     }

//     int next() {
//         int t = q.front(); q.pop();
//         return t; 
//     }

//     bool hasNext() {
//         return !q.empty();
//     }
    
// private:
//     queue<int> q;
//     void make_queue(vector<NestedInteger> &nestedList) {
//         for (auto a : nestedList) {
//             if (a.isInteger()) 
//               q.push(a.getInteger());
//             else 
//               make_queue(a.getList());
//         }
//     }
// };

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) v.push_back(i.next());
 */
 
 //Good reference:http://www.cnblogs.com/grandyang/p/5358793.html