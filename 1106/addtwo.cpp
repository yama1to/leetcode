// #include <stdio.h>
// #include <iostream>
// //  * Definition for singly-linked list.
// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum, plus, remain;
    sum = 0;
    plus = 0;
    remain = 0;

    ListNode *returnNode = new ListNode(0);
    ListNode *curr = new ListNode(0);
    int firstroop = 1;
    while (l1!=NULL || l2!=NULL || plus!=0){
        if (l1!=NULL){
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2!=NULL){
            sum += l2->val;
            l2 = l2->next;
        }
        sum += plus;
        plus = sum / 10;
        remain = sum % 10;

        curr->next = new ListNode(remain);
        if (firstroop){
            returnNode = curr;
            firstroop = 0;
        }
        curr = curr->next;
        sum = 0;

    }
    return returnNode->next;

    }

};

// int main(){
//     std::cout << 'aaa' << std::endl;
// }