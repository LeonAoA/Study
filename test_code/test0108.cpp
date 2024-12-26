// #include <iostream>
// #include <vector>

#include <bits/stdc++.h>
 
using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int length = 0;
        ListNode* node = head;
        while (node != nullptr) {
            length++;     // 计算节点个数
            node = node->next;  // node指向链表末尾空节点
        }
        ListNode* dummyHead = new ListNode(0, head);  // 构造了一个哨兵节点
        for (int subLength = 1; subLength < length; subLength <<= 1) {  // 每次循环后subLength将会向左移动一位，就是2^n。
            ListNode* prev = dummyHead, *curr = dummyHead->next;
            while (curr != nullptr) {
                ListNode* head1 = curr;
                for (int i = 1; i < subLength && curr->next != nullptr; i++) {  // 令当前节点curr向右移动subLength长度，或者移动到末尾
                    curr = curr->next;
                }
                ListNode* head2 = curr->next;  // head2暂存了对比链条的头结点
                curr->next = nullptr; // 切断了对比的两根链条
                curr = head2;  // curr指向第二根链条
                for (int i = 1; i < subLength && curr != nullptr && curr->next != nullptr; i++) {  // 令当前节点curr在第二根链条向右移动subLength长度，或者移动到末尾
                    curr = curr->next;
                }
                ListNode* next = nullptr;
                if (curr != nullptr) {  // 当前节点不为空，就是第二条链的长度够subLength长度
                    next = curr->next;    // next指向下一组可能得新链的头结点
                    curr->next = nullptr;  // curr的next置空，断开链条，为了进行重新的组合两个当前的比对链条
                }
                ListNode* merged = merge(head1, head2);
                prev->next = merged;   // 排好序的两个链条，接到前面排完序链表的后面
                while (prev->next != nullptr) {
                    prev = prev->next;   // prev指向排好序链表的最后，方便接后续排序链表
                }
                curr = next;  // curr指向未排序链表的头部next
            }
        }
        return dummyHead->next;
    }

    ListNode* merge(ListNode* head1, ListNode* head2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* temp = dummyHead, *temp1 = head1, *temp2 = head2;
        while (temp1 != nullptr && temp2 != nullptr) {
            if (temp1->val <= temp2->val) {
                temp->next = temp1;
                temp1 = temp1->next;
            } else {
                temp->next = temp2;
                temp2 = temp2->next;
            }
            temp = temp->next;
        }
        if (temp1 != nullptr) {
            temp->next = temp1;
        } else if (temp2 != nullptr) {
            temp->next = temp2;
        }
        return dummyHead->next;
    }
};



// int main(){
//     // s "cbaebabacd"   p"abc"  "abacbabc"
//     // string s = "cbaebabacd";  
//     string s = "abacbabc";  
//     string p = "abc";
//     // string s = "abab";   
//     // string p = "ab";
//     Solution sol;
//     sol.findAnagrams(s, p);

//     system("pause");
//     return 0;
// }

// 构建链表模板！！！
int main(){
    ListNode* head = new ListNode(4);
    ListNode* travel = head;

    // [4,2,1,3]
    vector<int> vec = {2,1,3};

    for(auto i : vec){
        ListNode* tmp = new ListNode(i);
        travel->next = tmp;
        travel = travel->next;
    }


    Solution sol;
    sol.sortList(head);

    system("pause");
    return 0;
}




/*
int main() {

    vector<vector<int>> map = {{1, 3, 1, 2, 4},
                               {1, 2, 1, 3, 2},
                               {2, 4, 7, 2, 1},
                               {4, 5, 6, 1, 1},
                               {1, 4, 1, 2, 2}};

    int value = 10;
    int val2 = 50;

    const int* ptr = &value;  // ptr 是一个常量指针

    std::cout << "Value: " << *ptr << std::endl;  // 输出值

    // *ptr = 20;  // 错误：不能通过常量指针修改指向的值
    value = 20;  // 可以直接修改变量本身
    std::cout << "New value1: " << *ptr << std::endl;

    ptr = &val2;
    std::cout << "New value2: " << *ptr << std::endl;

    int num = 0;
    int count = 0;
    string input = "1 2 3 4";
    istringstream iss(input);
    while(count--){
        iss >> num;
        cout << num << endl;
    }
    system("pause");
    return 0;
}
*/