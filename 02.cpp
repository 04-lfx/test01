#include <stdio.h>
#include <stdlib.h>
struct Node {
    int value;
    struct Node* next;
};
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    return newNode;
}
int josephus(int n, int x) {
    struct Node* head = createNode(1);
    struct Node* current = head;
    
    // 创建循环链表
    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    current->next = head;
    
    // 开始报数
    while (current->next != current) {
        // 报数x
        for (int i = 0; i < x - 1; i++) {
            current = current->next;
        }
        
        // 移除报数为x的节点
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    
    return current->value;
}
int main() {
    int n = 50;  // 人数
    int x = 3;   // 报数x
    
    int winner = josephus(n, x);
    printf("胜利者是第%d号人\n", winner);
    
    return 0;
}
