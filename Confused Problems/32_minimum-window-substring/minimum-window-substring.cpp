/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/minimum-window-substring
@Language: C++
@Datetime: 16-06-25 02:24
*/

// class Solution {
// public:    
//     /**
//      * @param source: A string
//      * @param target: A string
//      * @return: A string denote the minimum window
//      *          Return "" if there is no such a string
//      */
//     string minWindow(string &source, string &target) {
//         // write your code here
        
//         for()
//     }
// };

class Solution {
public:
    string minWindow(string S, string T) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (S.size()<T.size()){return "";}
             
        map<char,int>mp; // store chars occurrence of T 
        for(int i=0;i<T.size();i++){mp[T[i]]++;}
         
        int res_len=INT_MAX; // result length
        int res_p=0;//result start posiion
         
        int p=0; //pointer start
        int q=S.size()-1; //pointer end
         
        while (mp[S[p]]==0){if(p>=S.size()){return "";} p++;} //remove irralevent starting chars
        while (mp[S[q]]==0){q--;if(q<0){return "";}} // remove irralevent ending chars
         
        map<char,int> tab; //store chars occurrence of S[p:q]
        for (int i=p;i<=q;i++){tab[S[i]]++;} 
                     
        while (tab[S[q]]>mp[S[q]] || mp[S[q]]==0){ // move q to left find the 1st covered substring
           tab[S[q]]--;
           q--;
        }
             
        for (int i=0;i<T.size();i++){  // if no covered substring found, return ""
            if (tab[T[i]]<mp[T[i]]){return "";}
        }
     
        if (q-p+1<res_len){res_len=q-p+1; res_p=p;} //store the result
         
         
        while (p<q){
            if (q-p+1<res_len){res_len=q-p+1; res_p=p;} //store the result
            if (mp[S[p]]==0){p++;continue;} // if current char is not in T, go next
            if (tab[S[p]]>mp[S[p]]){tab[S[p]]--;p++;continue;} // if more chars in this substring, go next
             
            q++; 
            while (q<S.size() && S[q]!=S[p]){ if (mp[S[q]]>0){tab[S[q]]++;} q++;} //move q to find a substring covers T
            if (q>=S.size()){q=S.size()-1;}else{tab[S[q]]++;}
             
            if (S[q]==S[p]){ tab[S[p]]--; if (tab[S[p]]<mp[S[p]]){break;} p++;continue;}        
            break;
        }
         
        return S.substr(res_p,res_len);
    }
};

//Strong recommend:http://www.geeksforgeeks.org/find-the-smallest-window-in-a-string-containing-all-characters-of-another-string/
//http://bangbingsyb.blogspot.com/2014/11/leetcode-minimum-window-substring.html
//http://yucoding.blogspot.com/2013/01/leetcode-question-57-minimum-window.html