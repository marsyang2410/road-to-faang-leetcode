#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// * Definition for singly-linked list.
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* createNode(int new_data) {
    // Function to create a new node with given data
    struct ListNode* new_node = (struct ListNode*)malloc(sizeof(struct ListNode));
    new_node->val = new_data;
    new_node->next = NULL;
    return new_node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int carry = 0;
    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->val = 0;
    dummy->next = NULL;
    struct ListNode* current = dummy;

    while (l1 != NULL || l2 != NULL || carry)
    {
        int digit_sum = carry;

        if(l1){
            digit_sum += l1->val;
            l1 = l1->next;
        }
        if(l2){
            digit_sum += l2->val;
            l2 = l2->next;
        }

        carry = digit_sum / 10;
        printf("%d\n", digit_sum % 10);
        
        
        current->next = malloc(sizeof(struct ListNode));
        current->next->val = digit_sum %10;
        current->next->next = NULL;
        current =  current->next;
    }

    struct ListNode* result = dummy->next;
    free(dummy);
    return result;
}

void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d", head->val);
        if (head->next != NULL) printf(" -> ");
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Example: 342 + 465 = 807
    // l1: 1 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9 -> 9
    struct ListNode* l1 = createNode(1);
    struct ListNode* temp = l1;
    for (int i = 0; i < 9; i++) {
        temp->next = createNode(9);
        temp = temp->next;
    }

    // l2: 9
    struct ListNode* l2 = createNode(9);

    struct ListNode* result = addTwoNumbers(l1, l2);
    printf("Result: ");
    printList(result);
    return 0;
}