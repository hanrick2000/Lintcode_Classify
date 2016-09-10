/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/permutation-index-ii
@Language: C++
@Datetime: 16-08-30 05:34
*/

/*
这一题有了重复元素，就是要去掉重复的排列，其实很想排列组合问题，
对于重复的数字我们应该去掉他们重复的组合，
就是不在乎重复数字的重复排列，
应该从原来的结果中除以重复元素个数的阶乘 用hashmap记录重复元素的个数

1,4,2,2,3,3,5,3:

统计到 最左 3 的时候，hash［3］＝3；hash［5］＝1；
dupPerm(hash)=3!*1!

统计到 最左 2 的时候，hash［2］＝2；hash［3］＝3；hash［5］＝1；
dupPerm(hash)=（2!*3!*1!）

统计到 最左 4 的时候，hash［4］＝1；hash［2］＝2；hash［3］＝3；hash［5］＝1
dupPerm(hash)=（2!*3!*1!*1!）
*/

class Solution {
public:
    /**
     * @param A an integer array
     * @return a long integer
     */
long long permutationIndexII(vector<int>& A) {
        if (A.empty()) return 0;

        long long index = 1;
        long long factor = 1;
        for (int i = A.size() - 1; i >= 0; --i) {
            int rank = 0;
            unordered_map<int, int> hash;
            hash[A[i]]++;
            for (int j = i + 1; j < A.size(); ++j) {
                hash[A[j]]++;

                if (A[i] > A[j]) {
                    ++rank;
                }
            }
            index += rank * factor / dupPerm(hash);
            factor *= (A.size() - i);
        }

        return index;
    }

private:
    long long dupPerm(unordered_map<int, int> hash) {
        if (hash.empty()) return 1;

        long long dup = 1;
        for (auto it = hash.begin(); it != hash.end(); ++it) {
            dup *= fact(it->second);
        }

        return dup;
    }

    long long fact(int num) {
        long long val = 1;
        for (int i = 1; i <= num; ++i) {
            val *= i;
        }

        return val;
    }
};
