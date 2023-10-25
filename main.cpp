#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "String.h"
#define MAX_DIGIT 50
void generate_big_number(char *num, int digit) {
    // 生成指定位数的大数
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
    
    int* result = (int*)malloc((max_len + 1) * sizeof(int)); // 结果数组，多留一位用于存储进位
    memset(result, 0, (max_len + 1) * sizeof(int));
    int carry = 0;  // 进位值
    
    for (int i = 0; i < max_len; i++) {
        int digit1 = (i < len1) ? (num1[len1 - 1 - i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[len2 - 1 - i] - '0') : 0;
        
        int temp_sum = digit1 + digit2 + carry;
        result[max_len - i] = temp_sum % 10;  // 当前位的结果
        carry = temp_sum / 10;  // 计算进位
    }
    
    result[0] = carry;  // 最高位的进位
    
    // 将结果转化为字符串
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
    
    // 生成两个随机的大数
    int digit1 = rand() % MAX_DIGIT + 1;
    int digit2 = rand() % MAX_DIGIT + 1;
    generate_big_number(num1, digit1);
    generate_big_number(num2, digit2);
    
    // 打印生成的大数
    printf("大数 num1: %s\n", num1);
    printf("大数 num2: %s\n", num2);
    
    // 计算两个大数的相加结果
    char* sum = add_big_numbers(num1, num2);
    
    // 打印相加结果
    printf("相加结果: %s\n", sum);
    
    free(sum);
    
    return 0;
}
