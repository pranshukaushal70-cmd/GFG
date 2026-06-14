class Solution {
public:
    int lengthOfLoop(Node *head) {
        Node* slow = head;
        Node* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) {
                int count = 1;
                Node* temp = slow->next;
                while (temp != slow) {
                    count++;
                    temp = temp->next;
                }
                return count;
            }
        }
        return 0; 
    }
};
