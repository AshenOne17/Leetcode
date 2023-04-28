/*
* You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. 
  Add the two numbers and return the sum as a linked list.

  You may assume the two numbers do not contain any leading zero, except the number 0 itself.

  Example 1:

  1) 2 -> 4 -> 3
     5 -> 6 -> 4

  2) 7 -> 0 -> 8

  Input: l1 = [2,4,3], l2 = [5,6,4]
  Output: [7,0,8]
  Explanation: 342 + 465 = 807.

  Example 2:

  Input: l1 = [0], l2 = [0]
  Output: [0]
  Example 3:

  Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
  Output: [8,9,9,9,0,0,0,1]

  Constraints:

  The number of nodes in each linked list is in the range [1, 100].

  0 <= Node.val <= 9

  It is guaranteed that the list represents a number that does not have leading zeros.
*/


// Definition for singly-linked list.

struct ListNode
{
    int val;

    ListNode* next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution
{
public:

    Solution() = default;

    void insertNode(ListNode** node, int newdata);

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};

void Solution::insertNode(ListNode** node, int newdata)
{
    ListNode* result = new ListNode(newdata);

    if (*node == nullptr)
    {
        *node = result;
    }
    else
    {
        ListNode* temp = *node;

        while (temp->next != nullptr)
        {
            temp = temp->next;
        }

        temp->next = result;
    }
}

ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode* result = nullptr;

    int temp = 0, digit;

    while (l1 != nullptr && l2 != nullptr)
    {
        digit = l1->val + l2->val + temp;

        if (digit > 9)
        {
            temp = digit / 10;
            digit %= 10;
        }
        else
        {
            temp = 0;
        }

        insertNode(&result, digit);

        l1 = l1->next;

        l2 = l2->next;
    }

    while (l1 != nullptr)
    {
        digit = l1->val + temp;

        if (digit > 9)
        {
            temp = digit / 10;
            digit %= 10;
        }
        else
        {
            temp = 0;
        }

        insertNode(&result, digit);

        l1 = l1->next;
    }
    while (l2 != nullptr)
    {
        digit = l2->val + temp;

        if (digit > 9)
        {
            temp = digit / 10;
            digit %= 10;
        }
        else
        {
            temp = 0;
        }

        insertNode(&result, digit);

        l2 = l2->next;
    }

    if (temp != 0)
        insertNode(&result, temp);

    return result;
}

// Code for testing
// Should produce result Solution: [7, 0, 8]

/*
int main ()
{
    Solution test_solution;

    ListNode* l1 = new ListNode(2);

    test_solution.insertNode(&l1->next, 4);
    test_solution.insertNode(&l1->next, 3);

    ListNode* l2 = new ListNode(5);

    test_solution.insertNode(&l2->next, 6);
    test_solution.insertNode(&l2->next, 4);

    ListNode* result = test_solution.addTwoNumbers(l1, l2);

    std::cout << "Solution: [ ";

    while (result != nullptr)
    {
        std::cout << result->val << ", ";

        result = result->next;
    }

    std::cout << "]\n";

    return 0;
}
*/