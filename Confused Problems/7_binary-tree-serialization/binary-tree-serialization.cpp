/*
@Copyright:LintCode
@Author:   yzcmf
@Problem:  http://www.lintcode.com/problem/binary-tree-serialization
@Language: C++
@Datetime: 16-07-11 02:55
*/

// /**
//  * Definition of TreeNode:
//  * class TreeNode {
//  * public:
//  *     int val;
//  *     TreeNode *left, *right;
//  *     TreeNode(int val) {
//  *         this->val = val;
//  *         this->left = this->right = NULL;
//  *     }
//  * }
//  */
// class Solution {

// public:
//     /**
//      * This method will be invoked first, you should design your own algorithm 
//      * to serialize a binary tree which denote by a root node to a string which
//      * can be easily deserialized by your own "deserialize" method later.
//      */
     
     
// string output;
// int index=0;

//     string serialize(TreeNode *root) {
//         // write your code here
       
//       if(root == NULL)
//       {
//              output.push_back('#');
//              return output;
//       }

//       output.push_back(root->val + '0');
//       output=serialize(root->left);
//       output=serialize(root->right);
//     }

//     /**
//      * This method will be invoked second, the argument data is what exactly
//      * you serialized at method "serialize", that means the data is not given by
//      * system, it's given by your own serialize method. So the format of data is
//      * designed by yourself, and deserialize it here as you serialize it in 
//      * "serialize" method.
//      */
//     TreeNode *deserialize(string output) {
//         // write your code here
        
//         if(index > output.size() || output[index] == '#') return NULL;

//       TreeNode *root = new TreeNode(output[index] -'0');
//       index ++;
//       root->left = deserialize(output);
//       index++;
//       root->right = deserialize(output);
//       return root;
//     }
// };

//http://fisherlei.blogspot.com/2013/03/interview-serialize-and-de-serialize.html

class Solution {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream out;
        serialize(root, out);
        return out.str();
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }
private:
    void serialize(TreeNode *root, ostringstream &out) {
        if (root) {
            out << root->val << ' ';
            serialize(root->left, out);
            serialize(root->right, out);
        } else {
            out << "# ";
        }
    }
    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "#") return nullptr;
        TreeNode *root = new TreeNode(stoi(val));
        root->left = deserialize(in);
        root->right = deserialize(in);
        return root;
    }
};
