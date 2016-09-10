/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/single-number-ii
@Language: C++
@Datetime: 16-08-17 21:30
*/

class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
int singleNumberII(vector<int> &A) {
    // write your code here
    
    int ones = 0, twos = 0;
        
    for (int a : A) {
            ones = (ones ^ a) & ~twos;
            twos = (twos ^ a) & ~ones;
        }
        
    return ones;
}
};

/*
强大的解法，假设数a第一次出现，只存在ones里，第二次出现，从ones里消去，然后存在twos里，第三次出现，由于ones不存取已经在twos里的数，就只从twos里消去。整个过程相当于，直接在ones和twos里去掉既是ones又是twos的threes。所以最后返回的ones，一定是只出现过一次的single number，而出现两次的都在twos里，出现三次的都被消去了。
*/