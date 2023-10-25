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
    
    // ����ѭ������
    for (int i = 2; i <= n; i++) {
        current->next = createNode(i);
        current = current->next;
    }
    current->next = head;
    
    // ��ʼ����
    while (current->next != current) {
        // ����x
        for (int i = 0; i < x - 1; i++) {
            current = current->next;
        }
        
        // �Ƴ�����Ϊx�Ľڵ�
        struct Node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }
    
    return current->value;
}
int main() {
    int n = 50;  // ����
    int x = 3;   // ����x
    
    int winner = josephus(n, x);
    printf("ʤ�����ǵ�%d����\n", winner);
    
    return 0;
}
