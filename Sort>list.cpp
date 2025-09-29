#include<iostream> 

using namespace std; 

struct ListNode{
public: 
     int val; 
     ListNode* next; 
     ListNode(): val(0), next(nullptr){}
     ListNode(int _val): val(_val), next(nullptr){}
     ListNode(int _val, ListNode* _next): val(_val), next(_next){}
};
class Solution{
public: 
    ListNode* getMid(ListNode* head){
      ListNode* slow = head; 
      ListNode* fast = head ->next; 
      while(fast && fast->next){
        fast = fast->next->next; 
        slow = slow ->next; 
      }
      return slow; 
    }
    ListNode* mergeList(ListNode* l , ListNode* r){
      ListNode dummy(0); 
      ListNode* curr = &dummy; 
      while(l && r){
        if(l->val < r->val){
          curr->next = l; 
          l = l->next; 
        }else{
          curr->next = r; 
          r = r->next; 
        }
        curr = curr->next; 
      }
      curr ->next = l ? l:r; 
      return dummy.next; 
    }
    ListNode* sortList(ListNode* head) {
      if(!head || !head->next) return head; 

      ListNode* mid = getMid(head); 
      ListNode* right = sortList(mid->next); 
      mid ->next = nullptr; 
      ListNode* left = sortList(head); 
      return mergeList(left, right); 
    }
};
void printList(ListNode* head) {
    while(head) {
        cout << head->val;
        if(head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Build unsorted linked list: 4 -> 2 -> 1 -> 3 -> 5
    ListNode* head = new ListNode(4);
    head->next = new ListNode(2);
    head->next->next = new ListNode(1);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    ListNode* sorted = sol.sortList(head);

    cout << "Sorted list:   ";
    printList(sorted);

    return 0;
}
