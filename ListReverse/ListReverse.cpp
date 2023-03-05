#include<vector>
using namespace std;


struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* ReverseList(ListNode* head) {
        if (head == nullptr) return nullptr;
        if (head->next == nullptr) return head;

        ListNode* prev = nullptr;
        ListNode* temp = nullptr;
        ListNode* current = head;

        while (current != nullptr) {
            temp = current->next;
            current->next = prev;
            prev = current;
            current = temp;
        }
        return prev;
    }
};