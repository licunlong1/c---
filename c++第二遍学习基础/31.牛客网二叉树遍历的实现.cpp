//#define _CRT_SECURE_NO_WARNINGS 1
//#include <iostream>
//#include <string>
//#include <stack>
//using namespace std;
//class TreeNode {
//    typedef TreeNode TNode;
//public:
//    //¹¹Ôìº¯Êý
//    TreeNode() :left(nullptr), right(nullptr) {}
//    TreeNode(char ch) :data(ch), left(nullptr), right(nullptr) {}
//    //private:
//    TreeNode* left;
//    TreeNode* right;
//    char data;
//};
//
//TreeNode* Create_Tree(string str, int& i) {
//    if (str[i] == '#') {
//        i++;
//        return NULL;
//    }
//    TreeNode* node = new TreeNode(str[i++]);
//    //node->data = str[i];
//    node->left = Create_Tree(str, i);
//    node->right = Create_Tree(str, i);
//    return node;
//}
//void print_InOrder(TreeNode* root) {
//    if (!root) return;
//    print_InOrder(root->left);
//    cout << root->data << " ";
//    print_InOrder(root->right);
//}
//int main()
//{
//    string ret;
//    while (cin >> ret) {
//        int i = 0;
//        TreeNode* root = new TreeNode();
//        if (!root) return 0;
//        root = Create_Tree(ret, i);
//        print_InOrder(root);
//    }
//    return 0;
//}