#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "String.h"
#define MAX_DIGIT 50
void generate_big_number(char *num, int digit) {
    // ����ָ��λ���Ĵ���
    srand(time(0));
    for (int i = 0; i < digit; i++) {
        num[i] = rand() % 10 + '0';
    }
    num[digit] = '\0';
}
char* add_big_numbers(const char *num1, const char *num2) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int max_len = (len1 > len2) ? len1 : len2;
    
    int* result = (int*)malloc((max_len + 1) * sizeof(int)); // ������飬����һλ���ڴ洢��λ
    memset(result, 0, (max_len + 1) * sizeof(int));
    int carry = 0;  // ��λֵ
    
    for (int i = 0; i < max_len; i++) {
        int digit1 = (i < len1) ? (num1[len1 - 1 - i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[len2 - 1 - i] - '0') : 0;
        
        int temp_sum = digit1 + digit2 + carry;
        result[max_len - i] = temp_sum % 10;  // ��ǰλ�Ľ��
        carry = temp_sum / 10;  // �����λ
    }
    
    result[0] = carry;  // ���λ�Ľ�λ
    
    // �����ת��Ϊ�ַ���
    char* result_str = (char*)malloc((max_len + 2) * sizeof(char));
    int index = 0;
    if (carry != 0) {
        result_str[index++] = carry + '0';
    }
    for (int i = 1; i <= max_len; i++) {
        result_str[index++] = result[i] + '0';
    }
    result_str[index] = '\0';
    
    free(result);
    return result_str;
}
int main() {
    char num1[MAX_DIGIT + 1];
    char num2[MAX_DIGIT + 1];
    
    // ������������Ĵ���
    int digit1 = rand() % MAX_DIGIT + 1;
    int digit2 = rand() % MAX_DIGIT + 1;
    generate_big_number(num1, digit1);
    generate_big_number(num2, digit2);
    
    // ��ӡ���ɵĴ���
    printf("���� num1: %s\n", num1);
    printf("���� num2: %s\n", num2);
    
    // ����������������ӽ��
    char* sum = add_big_numbers(num1, num2);
    
    // ��ӡ��ӽ��
    printf("��ӽ��: %s\n", sum);
    
    free(sum);
    
    return 0;
}
