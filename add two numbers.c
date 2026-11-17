#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(
    struct ListNode* l1,
    struct ListNode* l2)
{
    struct ListNode dummy;
    dummy.next = NULL;

    struct ListNode* tail = &dummy;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry != 0)
    {
        int sum = carry;

        if (l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }

        if (l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum / 10;

        struct ListNode* newNode =
            malloc(sizeof(struct ListNode));

        newNode->val = sum % 10;
        newNode->next = NULL;

        tail->next = newNode;
        tail = newNode;
    }

    return dummy.next;
}

int main()
{
    struct ListNode a3 = {3, NULL};
    struct ListNode a2 = {4, &a3};
    struct ListNode a1 = {2, &a2};

    struct ListNode b3 = {4, NULL};
    struct ListNode b2 = {6, &b3};
    struct ListNode b1 = {5, &b2};

    struct ListNode* result =
        addTwoNumbers(&a1, &b1);

    while (result != NULL) {
        printf("%d", result->val);
        result = result->next;
    }

    return 0;
}