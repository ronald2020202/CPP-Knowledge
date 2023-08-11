#include <iostream>
#include <ios>
#include <limits>
#include <cstring>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <set>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
};

ListNode* construct(vector<int>& v) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for (int num : v) {
        ListNode* node = new ListNode;
        node->val = num;
        node->next = nullptr;

        if (head == nullptr) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head;
}

void display(ListNode* head) {
    ListNode* cur = head;
    while (cur != nullptr) {
        cout << cur->val << endl;
        cur = cur->next;
    }
}

int count(ListNode* head) {
    int counter = 0;
    ListNode* cur = head;
    while (cur != nullptr) {
        counter++;
        cur = cur->next;
    }
    return counter;
}

ListNode* find(ListNode* head, int n) {
    ListNode* cur = head;
    while (cur != nullptr) {
        if (cur->val == n)
        {
            return cur;
        }
        cur = cur->next;
    }
    return nullptr;
}

int countval(ListNode* head, int n) {
    int counter = 0;
    ListNode* cur = head;

    while (cur != nullptr)
    {
        if (cur->val == n)
        {
            counter++;
        }
        cur = cur->next;
    }
    return counter;
}

int getmax(ListNode* head) {
    ListNode* cur = head;
    int max = INT_MIN;

    while (cur != nullptr) {
        if (cur->val > max)
        {
            max = cur->val;
        }
        cur = cur->next;
    }
    return max;
}

int getmin(ListNode* head) {
    ListNode* cur = head;
    int min = INT_MAX;

    while (cur != nullptr) {
        if (cur->val < min)
        {
            min = cur->val;
        }
        cur = cur->next;
    }
    return min;
}

int main() {
    vector<int> v{1, 1, 3, 4, 5};
    ListNode* head = construct(v);
    display(head);
    ListNode* n = find(head, 3);
    if (n != nullptr)
    {
        cout << n->val << endl;
    }
    else
    {
        cout << "nullptr" << endl;
    }
    cout << find(head, 0) << endl;

    cout << getmax(head) << endl;
    cout << getmin(head) << endl;

    return 0;
}

