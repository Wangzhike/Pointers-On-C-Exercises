/*
 *  将一个字符串中的字符反向排列，
 *  操作过程中不能使用局部数组来临时存储参数字符串。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 50
void reverse_string(char *string);

int main(int argc, const char * argv[]) {
    char string[STRING_SIZE];
    gets(string);
    printf("The original string is %s\n", string);
    reverse_string(string);
    printf("The reversed string is %s\n", string);
    return EXIT_SUCCESS;
}

/*
 *  交换前后两个字符的值。
 */
void swapChar(char *predecessor, char *successor)
{
    char ch = *predecessor;
    *predecessor = *successor;
    *successor = ch;
}

void reverse_string(char *string)
{
    char *end = string;
    for (; *end != '\0'; end++)
        ;
    /*
     *  当“string”不为空时，end此时指向“string”的结束字符，
     *  需要将end向前移动一位，使其指向结束字符前的字符。
     */
    if (end != string)
        end--;
    while (string < end) {
        swapChar(string++, end--);
    }
}
