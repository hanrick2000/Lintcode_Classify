/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/insert-interval
@Language: C++
@Datetime: 16-08-12 15:21
*/

/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */
 
/*思路：

题目涉及两个问题：
1. 如何判断两个interval有重合。
2. 如果重合，如何合并。
3. 如何判断[s1, e1]是否在[s2, e2]前面

A1. 两个interval有重合有很多种可能性，但判断它们不重合则比较简单直观。无非两种情况：

(1) [s1, e1]  [s2, e2]：即s2>e1 
(2) [s2, e2]  [s1, e1]：即s1>e2

不重合的条件为：s2>e1 || s1>e2，反之则重合。

A2. 对于两个有重合的interval： [s1, e1]，[s2, e2]。合并后变为[min(s1,s2), max(e1,e2)]。

A3. [s1, e1]在[s2, e2]前面的条件：e1<s2

所以插入interval a的算法为：扫描队列中每个interval I[i]：
如果a已经被插入了，则只要插入I(i)就行。
如果a在I(i)前，则先插入a再插入I(i)到结果。
如果a和I(i)有重合，则将I(i)合并入a，但并不插入结果。
如果a在I(i)后，则插入I(i)到结果。
*/

class Solution {
public:
    /**
     * Insert newInterval into intervals.
     * @param intervals: Sorted interval list.
     * @param newInterval: new interval.
     * @return: A new interval list.
     */
vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // write your code here
        
        vector<Interval> ret;
        bool isInsert = false;
        for(int i=0; i<intervals.size(); i++) {
            // already insert newInterval
            if(isInsert) {  
                ret.push_back(intervals[i]);
                continue;
            }
            
            // insert newInterval before current interval
            if(newInterval.end < intervals[i].start) {  
                ret.push_back(newInterval);
                ret.push_back(intervals[i]);
                isInsert = true;
                continue;
            }
            
            // combine newInterval with current interval
            if(newInterval.start<=intervals[i].end && intervals[i].start<=newInterval.end) {
                newInterval.start = min(newInterval.start, intervals[i].start);
                newInterval.end = max(newInterval.end, intervals[i].end);
                continue;
            }
            
            // newInterval after current interval
            ret.push_back(intervals[i]);
        }
        
        if(!isInsert) ret.push_back(newInterval);//Handle the ending case;
        return ret;
        
    }
};