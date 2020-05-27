/**
 * 
 * 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 
 * 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：

输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
 * 
 * 
 * */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
#include <string>

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x) , next(nullptr){}
};


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr || l2 == nullptr)
            return nullptr;

        ListNode *p1 = l1;
        ListNode *p2 = l2;

        ListNode *result= nullptr;
        int priorVal = 0;//进位
        bool isHead = true;
        ListNode *preNode = nullptr;

        while(p1 != nullptr || p2 != nullptr){
            int leftVal = 0;
            if(p1 != nullptr){
                leftVal = p1->val;
            }

            int rightVal = 0;
            if(p2 != nullptr){
                rightVal = p2->val;
            }

            int resultVal = leftVal + rightVal + priorVal;
            if(resultVal >= 10){
                resultVal -= 10;
                priorVal = 1;
            }else{
                priorVal = 0;
            }

            //create new node
            ListNode *resultNode = new ListNode(resultVal);
            resultNode->next = nullptr;

            //std::cout << "resultVAL : " << resultVal << std::endl;
            
            if(preNode != nullptr){
                preNode->next = resultNode;
            }else{//head
                result = resultNode;
            }
            preNode = resultNode;
            
            //to next node
            if(p1 != nullptr){
                p1 = p1->next;
            }

            if(p2 != nullptr){
                p2 = p2->next;
            }
            
            //已结束  还需要考虑下进位问题
            if(p1 == nullptr && p2 == nullptr && priorVal != 0){
                ListNode *resultNode = new ListNode(priorVal); 
                //resultNode->val = priorVal;
                resultNode->next = nullptr;

                if(preNode != nullptr){
                    preNode->next = resultNode;
                }else{//head
                    result = resultNode;
                }
                break;
            }

            //std::cout <<p1 <<  "========"<< p2 << std::endl;
        }//end while

        return result;
    }
};

void printListNode(ListNode *pNode){
    std::cout << " [ ";
    ListNode *p = pNode;
    while(p != nullptr){
        std::cout << p->val << " ";
        p = p->next;
    }//end while
    std::cout << "]" << std::endl;
}

ListNode *createNode(std::string str){
    if(str == "")
        return nullptr;
    const char *data = str.c_str();
    int len = str.length();

    ListNode *result = nullptr;
    ListNode *preNode = nullptr;
    for(int i = len -1 ; i >= 0 ; i--){
        ListNode *node = new ListNode(data[i] - '0'); 
        node->val = data[i] - '0';
        node->next = nullptr;

        if(preNode != nullptr){
            preNode->next = node;
        }else{
            result = node;
        }

        preNode = node;
    }//end for i

    return result;
}

int main() {
    Solution solution;
    ListNode *list1 = createNode("342");
    ListNode *list2 = createNode("465");

    ListNode *r = solution.addTwoNumbers(list1 , list2);
    printListNode(r);

    //printListNode(list);

    return 0;
}