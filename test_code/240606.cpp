#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
  
class Solution {
public:

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        size_t size = inorder.size();

        if(size == 1){
            TreeNode* cur_mid_node = new TreeNode(inorder[0]);  // TreeNode* cur_mid_node = TreeNode(inorder[0]); 指针需要new，不new是非指针的实例化。。
            return cur_mid_node;
        }
        // 处理中序遍历，构建哈希，方便通过后续遍历中找到的中间节点，确定其在中序遍历的索引
        unordered_map<int,int> in_map;  // unordered_map<int> in_map; map定义写错了。。

        for(int i = 0; i < size; i++){
            in_map[inorder[i]] = i;     // in_map[num[i]] = i;处理的是inorder，而不是不存在的num。。
        }

        int mid_node_val = postorder.back();  // 取中间节点值
        TreeNode* cur_mid_node = new TreeNode(mid_node_val);  // new TreeNode(mid_node);上面从mid_node改为了int mid_node_val，但这里忘了改了。。

        int inorder_mid_node_index = in_map[mid_node_val];    // inorder_mid_node_index = in_map[mid_node];声明忘了写数据类型。。
        
        // 需要确保中序里面，中间元素区分开的左右子树的元素个数大于0，不然vector处理会出问题！！！
        vector<int> inorder_left, inorder_right, postorder_left, postorder_right;
        if(inorder_mid_node_index == 0){  // 中间元素索引为0，说明左子树没有
            cur_mid_node->left = nullptr;
            inorder_right = vector<int>(inorder.begin() + 1, inorder.begin() + size); // 中序右子树元素集合
            postorder_right = vector<int>(postorder.begin(), postorder.begin() + inorder_right.size()); // 后序右子树元素集合  size - 1 / inorder_right.size()
        }else if(inorder_mid_node_index == size-1){ // 中间元素索引为size-1，说明右子树没有
            cur_mid_node->right = nullptr;
            inorder_left = vector<int>(inorder.begin(), inorder.begin() + inorder_mid_node_index);  // 中序左子树元素集合
            postorder_left = vector<int>(postorder.begin(), postorder.begin() + inorder_left.size());   // 后序左子树元素集合
        }else{    // 左右子树都存在情况
            inorder_left = vector<int>(inorder.begin(), inorder.begin() + inorder_mid_node_index);  // 中序左子树元素集合
            inorder_right = vector<int>(inorder.begin() + inorder_mid_node_index + 1, inorder.begin() + size); // 中序右子树元素集合
        
            postorder_left = vector<int>(postorder.begin(), postorder.begin() + inorder_left.size());   // 后序左子树元素集合
            postorder_right = vector<int>(postorder.begin() + inorder_left.size(), postorder.begin() + size - 1); // 后序右子树元素集合
        }

        if(cur_mid_node->left == nullptr) {
            cur_mid_node->right = buildTree(inorder_right, postorder_right);  // 遍历右子树
        }else if(cur_mid_node->right == nullptr){
            cur_mid_node->left = buildTree(inorder_left, postorder_left);   // 遍历左子树
        }else{
            cur_mid_node->left = buildTree(inorder_left, postorder_left);   // 遍历左子树
            cur_mid_node->right = buildTree(inorder_right, postorder_right);  // 遍历右子树
        }
        
        return cur_mid_node;
    }
};

int main(){
    // Solution sol;

    // vector<int> inorder = {9,3,15,20,7};
    // vector<int> postorder = {9,15,7,20,3};

    // sol.buildTree(inorder, postorder);

    int value = 10;
    int val2 = 50;

    const int* ptr = &value;  // ptr 是一个常量指针

    std::cout << "Value: " << *ptr << std::endl;  // 输出值

    // *ptr = 20;  // 错误：不能通过常量指针修改指向的值
    value = 20;  // 可以直接修改变量本身
    std::cout << "New value1: " << *ptr << std::endl;

    // ptr = &val2;
    std::cout << "New value2: " << *ptr << std::endl;

    system("pause");
    return 0;
}



/*

int main(){
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2;

    vec2 = std::vector<int>(vec1.begin(), vec1.begin() + 2);

    for (const auto& p : vec2) {
        // std::cout << "{" << p.first << ", " << p.second << "} ";
        std::cout << p << " ";

    }
    std::cout << std::endl;

    system("pause");
    return 0;
}


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};






*/





























