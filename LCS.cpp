#include <stdio.h>
#include <string.h>

// LCS ���̿� LCS ���ڿ��� ã�� �Լ�
void LCS(char *s1, char *s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int LCS_table[len1+1][len2+1];

    // LCS ���̺� �ʱ�ȭ
    for(int i = 0; i <= len1; i++) {
        for(int j = 0; j <= len2; j++) {
            if(i == 0 || j == 0) {
                LCS_table[i][j] = 0;
            } else if(s1[i-1] == s2[j-1]) {
                LCS_table[i][j] = LCS_table[i-1][j-1] + 1;
            } else {
                LCS_table[i][j] = LCS_table[i-1][j] > LCS_table[i][j-1] ? LCS_table[i-1][j] : LCS_table[i][j-1];
            }
        }
    }

    // LCS ����
    int LCS_length = LCS_table[len1][len2];
    printf("LCS ����: %d\n", LCS_length);

    // LCS ����
    char LCS_str[LCS_length + 1];
    LCS_str[LCS_length] = '\0'; // �������� �� ���� �߰�

    int i = len1, j = len2;
    while(i > 0 && j > 0) {
        if(s1[i-1] == s2[j-1]) {
            LCS_str[--LCS_length] = s1[i-1];
            i--;
            j--;
        } else if(LCS_table[i][j-1] >= LCS_table[i-1][j]) {
            j--;
        } else {
            i--;
        }
    }

    printf("LCS: %s\n", LCS_str);
}

int main() {
    char s1[] = "ABCBDAB";
    char s2[] = "BDCAB";

    LCS(s1, s2);

    return 0;
}



