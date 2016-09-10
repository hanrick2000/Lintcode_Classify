/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/merge-intervals
@Language: C++
@Datetime: 16-08-23 05:39
*/

/**
 * Definition of Interval:
 * class Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 */
class Solution {
public:
    /**
     * @param intervals: interval list.
     * @return: A new interval list.
     */
    
    struct comp{
        bool operator()(const Interval &a , const Interval &b) const
        {
            return a.start<b.start;
        }
    }; 
    
    vector<Interval> merge(vector<Interval> &intervals) {
        // write your code here
        sort(intervals.begin(),intervals.end(),comp());
        vector<Interval> ret;
        
        for(int i=0;i<intervals.size();i++)
        {
            if(ret.empty() || ret.back().end < intervals[i].start)//no-overlap
              ret.push_back(intervals[i]);
            else // overlap
              ret.back().end = max(ret.back().end,intervals[i].end);
        }
        
        return ret;
    }
};

// class Solution {
// public:
//     struct compInterval {
//         bool operator()(const Interval &a, const Interval &b) const {
//             return a.start<b.start;
//         }
//     };

//     vector<Interval> merge(vector<Interval> &intervals) {
//         sort(intervals.begin(),intervals.end(),compInterval());
//         vector<Interval> ret;
//         for(int i=0; i<intervals.size(); i++) {
//             if(ret.empty() || ret.back().end < intervals[i].start)  // no overlap
//                 ret.push_back(intervals[i]);
//             else   // overlap
//                 ret.back().end = max(ret.back().end, intervals[i].end);
//         }
//         return ret;
//     }
// };



/*
从Insert Interval那题的解法，我们知道了如何判断两个interval是否重合，如果不重合，如何判断先后顺序。那么这题就很简单了，首先按照start的大小来给所有interval排序，start小的在前。然后扫描逐个插入结果。如果发现当前interval a和结果中最后一个插入的interval b不重合，则插入a到b的后面；反之如果重合，则将a合并到b中。注意要给object排序需要定义一个compare structure作为sort函数的额外参数。
*/

//http://bangbingsyb.blogspot.com/2014/11/leetcode-merge-intervals.html