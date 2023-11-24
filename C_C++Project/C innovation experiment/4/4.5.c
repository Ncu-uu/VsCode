#include <stdio.h>
#include <string.h>

void reverse(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main() {
    char str[100];
    printf("请输入一个字符串：");
    scanf("%s", str);
    reverse(str);
    printf("反序后的字符串为：%s\n", str);
    printf("\n\n\n\n");
    return 0;
    
}
