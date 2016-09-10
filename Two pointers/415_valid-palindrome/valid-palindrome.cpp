/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/valid-palindrome
@Language: C++
@Datetime: 16-08-25 23:46
*/

class Solution {
public:
    /**
     * @param s A string
     * @return Whether the string is a valid palindrome
     */
    // bool isPalindrome(string& s) {
    //     // Write your code here
    //     string mystr=s;
    //     reverse(s.begin(),s.end());
    //     return s==mystr;
    // }
    bool isPalindrome(string& str) {
	int l=0, r = str.length()-1;
	
	while(l<r) 
	{
		
		if(!isalnum(str[l]))
		{
		    l++;
		    continue;
		}
		if(!isalnum(str[r]))
		{
		    r--;
		    continue;
		}
		
		if(tolower(str[l])==tolower(str[r]))
		{
		    l++;
		    r--;
		}
		else
		{
		return false;
		}
    }
    
    return true;
    }
// Note:considering only alphanumeric characters and ignoring cases;
};