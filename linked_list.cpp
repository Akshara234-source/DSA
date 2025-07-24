//Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem 
// without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.) 
//Example 1:
// Input: head = [1,2,3,4]
// Output: [2,1,4,3]

// Example 2:
// Input: head = []
// Output: []

// Example 3:
// Input: head = [1]
// Output: [1]

// Example 4:
// Input: head = [1,2,3]
// Output: [2,1,3]

#include <iostream>
#include <vector>
using namespace std;

/**
 * Definition for singly-linked list.
 */
//already given in the leetcode question
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while (fast != NULL && slow != NULL) {
            int x = fast->val;
            fast->val = slow->val;
            slow->val = x;

            slow = fast->next;
            if (slow != NULL) {
                fast = slow->next;
            }
        }
        return head;
    }
};

// Helper function to print linked list
void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
        cout << temp->val << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Helper function to create a linked list from an array
ListNode* createList(const vector<int>& values) {
    if (values.empty()) 
    return NULL;
    ListNode* head = new ListNode(values[0]);
    ListNode* temp = head;
    for (int i = 1; i < values.size(); i++) {
        temp->next = new ListNode(values[i]);
        temp = temp->next;
    }
    return head;
}

int main() {
    vector<int> values;
    int n;
    cout<<"enter the no of elements you need to input"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cout<<"enter the element"<<endl;
        cin>>x;
        values.push_back(x);
    }
    ListNode* head = createList(values);

    cout << "Original List: ";
    printList(head);

    Solution sol;
    ListNode* swapped = sol.swapPairs(head);

    cout << "List after swapping pairs: ";
    printList(swapped);

    return 0;
}
