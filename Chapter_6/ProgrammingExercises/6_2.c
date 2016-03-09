/*
 *  如果字符串“substr”出现在字符串“str”中，则删除“str”中的“substr”,
 *  如果出现多次，则删除第一次出现的子串，返回1。如果未出现，返回0。
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FALSE   0
#define TRUE    1
#define STRING_SIZE 50
int del_substr(char *str, char const *substr);

int main(int argc, const char * argv[]) {
    char str[STRING_SIZE];
    char substr[STRING_SIZE];
    gets(str);
    if (*gets(substr) == '\0') {
        puts("The input substring is empty.");
    }
    if (del_substr(str, substr)) {
        printf("I got it! The rest of string is %s\n", str);
    } else
        puts("Sorry, I can't find it.");
    return EXIT_SUCCESS;
}

/*
 *  检查初始字符串“str”是否以初始字符串“substr”开头，如果是，
 *  返回“str”中除去“substr”后的第一个字符的地址。
 *  否则，返回NULL。
 */
char *locateTail(char const *str, char const *substr)
{
    while (*substr != '\0') {
        if (*str++ != *substr++) {
            return NULL;
        }
    }
    return (char*)str;
}

int del_substr(char *str, char const *substr)
{
    char *tail = NULL;
    /*
     *  寻找初始字符串“str”中第一次出现字符串“substr”的字符的地址str。
     */
    while (*str != '\0') {
        tail = locateTail(str, substr);
        if (tail != NULL) {
            break;
        }
        str++;
    }
    /*
     *  此时到达了“str”的末尾，说明未找到“substr”。
     */
    if (*str == '\0') {
        return FALSE;
    }
    /*
     *  找到了“substr”。利用“substr”的第一个字符在“str”中的地址str，
     *  和“str”中除去“substr”后的第一个字符的地址tail，通过覆盖完成删除操作。
     */
    while ((*str++ = *tail++) != '\0')
        ;
    return TRUE;
}
