/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/anagrams
@Language: C++
@Datetime: 16-08-22 07:06
*/

// class Solution {
// public:    
//     /**
//      * @param strs: A list of strings
//      * @return: A list of strings
//      */
//     vector<string> anagrams(vector<string> &strs) {
//         // write your code here
        
//         vector<string> ret;
//         unordered_map<string,vector<int>> ht;
        
//         for(int i=0;i<strs.size();i++)
//         {
//             string key=strs[i];
//             sort(key.begin(),key.end());
//             ht[key].push_back(i);
//         }
        
//         for(unordered_map<string,vector<int>>::iterator it=ht.begin();it!=ht.end();it++)
//         {
//             if(it->second.size()>1)
//             {
//                 for(int i=0;i<it->second.size();i++)
//                 ret.push_back(strs[it->second[i]]);
//             }
//         }
        
//         return ret;
//     }
// };

//Good reference:http://bangbingsyb.blogspot.com/2014/11/leetcode-anagrams.html

/*
Anagrams指几个string有相同的字符，但不同的字符顺序。所以一个有效的检查方法是：当两个string排序以后相同，则它们是anagrams。可以使用一个hash table，string s的key是它自己排序后的string，这样anagrams会有相同的key。用一个vector<int>来记录相同key的string在input vector<string>中的index。最后扫描一遍hash table，当有两个或以上string有相同的key时，将它们输出到结果。
*/

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> ret;
        unordered_map<string,vector<int>> ht;
        
        for(int i=0; i<strs.size(); i++) {
            string key = strs[i];
            sort(key.begin(),key.end());
            ht[key].push_back(i);
        }
            
        for(unordered_map<string,vector<int>>::iterator it=ht.begin(); it!=ht.end(); it++) {
            if(it->second.size()>1) {
                for(int i=0; i<it->second.size(); i++) {
                    ret.push_back(strs[it->second[i]]);    
                }
            }
        }
        return ret;
    }
};



// class Solution {
// public:
//     vector<string> anagrams(vector<string> &strs) {
//         vector<string> res;
//         map<string,int> mp;
//         for (int i=0;i<strs.size();i++){
//             string ss = strs[i];
//             sort(ss.begin(),ss.end());
//             if (mp.find(ss)!=mp.end()){
//                 res.push_back(strs[i]);
//                 if (mp[ss]!=-1){
//                     res.push_back(strs[mp[ss]]);    
//                     mp[ss]=-1;
//                 }
//             }else{
//                 mp[ss]=i;
//             }
//         }
//         return res;
//     }
// };
