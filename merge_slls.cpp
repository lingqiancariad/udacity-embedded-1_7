#include <iostream>

struct ListNode {
    int val;
    ListNode *next = nullptr;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Helper function to print the list (for testing purposes)
void printList(ListNode* node, bool b_debug) {
    if (b_debug) {
        std::cout << "[Debug] l2: ";
    }
    while (node != nullptr) {
        std::cout << node->val;
        if (node->next == nullptr) {
            std::cout << "\n";
            break;
        }
        std::cout << " -> ";
        node = node->next;
    }
}

/* @author: LiMe
*  @date: 17.03.2026
*  
*  The logic is during each while loop to insert a node from l1 into l2. 
*  In the end l2 will be returned by this function.
*  After each node has been successfully inserted into l2, the current l2 SLL will be printed seperately. 
*  Precondition is l2 needs to be sorted ascendingly in the first place.
*  l1 does not need to be sorted at all.
*/
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* current_node_l1 = l1;                             // start with the first node of l1
    while(current_node_l1 != nullptr) {
        ListNode* next_node_l1 = current_node_l1->next;         // save the next l1 node before the allocation round. 
        ListNode* current_node_l2 = l2;                         // start with the first node of l2
        while(current_node_l2 != nullptr) {
            if (current_node_l1->val < current_node_l2->val) {
                current_node_l1->next = current_node_l2;
                std::cout << "[Debug] Parent current l2 node with value: " << current_node_l1->val << ". Current l2 node with value: " << current_node_l2->val << std::endl;
                l2 = current_node_l1;                           // assign l1 to head of l2
                printList(l2, true);
                break;                                          // current l1 node allocated. Break and continue with the next l1 node.
            } else if (current_node_l1->val > current_node_l2->val && current_node_l2->next == nullptr) {
                current_node_l2->next = current_node_l1;        // insert current l1 node after the last l2 node
                current_node_l1->next = nullptr;
                std::cout << "[Debug] Current l2 node with value: " << current_node_l2->val << ". Next l2 node with value: " << current_node_l2->next->val << std::endl;
                printList(l2, true);
                break;                                          // current l1 node allocated. Break and continue with the next l1 node.
            } else if (current_node_l1->val >= current_node_l2->val && current_node_l2->next != nullptr && current_node_l1->val <= current_node_l2->next->val) {
                current_node_l1->next = current_node_l2->next;  // insert current l1 node between current l2 node and the next l2 node 
                current_node_l2->next = current_node_l1;
                std::cout << "[Debug] Current l2 node with value: " << current_node_l2->val << ". Next l2 node with value: " << current_node_l2->next->val << std::endl;
                printList(l2, true);
                break;                                          // current l1 node allocated. Break and continue with the next l1 node.
            } else { 
                                                                // if current l1 node is bigger than current l2 node and the next l2 node.-> No action for this round.
                std::cout << "[Debug] Current l1 node with value: " << current_node_l1->val <<" is bigger than l2 node next with value: " << current_node_l2->next->val <<". And will NOT be placed in l2.\n";
            }
            current_node_l2 = current_node_l2->next;            // evaluate next l2 node
        } 
        current_node_l1 = next_node_l1;                         // assign the orignal next l1 node to the current l1 node for the next round.
    }
    return l2;
}

int main() {
    // Example usage:
    // List 1: 1 -> 3 -> 5
    ListNode* l1 = new ListNode(30);
    l1->next = new ListNode(25);
    l1->next->next = new ListNode(8);
    l1->next->next->next = new ListNode(40);

    // List 2: 2 -> 4 -> 6
    ListNode* l2 = new ListNode(10);
    l2->next = new ListNode(11);
    l2->next->next = new ListNode(12);
    l2->next->next->next = new ListNode(13);

    ListNode* mergedList = mergeTwoLists(l1, l2);

    // Expected outcome : 1 -> 2 -> 3 -> 4 -> 5 -> 6
    printList(mergedList, false);

    return 0;
}