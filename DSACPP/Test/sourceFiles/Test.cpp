#include "../headFiles/Test.h"
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>

#define MAXLEN 50

//void LCSLength(char* x, char* y, int m, int n, int c[][MAXLEN]) {
//    int i, j;
//
//    for (i = 0; i <= m; i++)
//        c[i][0] = 0;
//    for (j = 1; j <= n; j++)
//        c[0][j] = 0;
//    for (i = 1; i <= m; i++)
//    {
//        for (j = 1; j <= n; j++)
//        {
//            if (x[i - 1] == y[j - 1])
//            {                          //����ȥ���˶�b�����ʹ�ã�������û��
//                c[i][j] = c[i - 1][j - 1] + 1;
//            }
//            else if (c[i - 1][j] >= c[i][j - 1])
//            {
//                c[i][j] = c[i - 1][j];
//            }
//            else
//            {
//                c[i][j] = c[i][j - 1];
//
//            }
//        }
//    }
//}
//
//void PrintLCS0(int c[][MAXLEN], char *x, int i, int j)
//{         //�ǵݹ��PrintLCS
//    static char s[MAXLEN];
//    int k=c[i][j];
//    s[k]='\0';
//    while(k>0)
//    {
//        if (c[i][j] == c[i - 1][j])
//        {
//            i--;
//        }
//        else if (c[i][j] == c[i][j - 1])
//        {
//            j--;
//        }
//        else
//        {
//            s[--k]=x[i-1];
//            i--;j--;
//        }
//    }
//    printf("%s",s);
//}
//
//void PrintLCS(int c[][MAXLEN], char* x, int i, int j) 
//{
//    if (i == 0 || j == 0)
//    {
//        return;
//    }
//    if (c[i][j] == c[i - 1][j]) 
//    {
//        PrintLCS(c, x, i - 1, j);
//    }
//    else if (c[i][j] == c[i][j - 1])
//    {
//        PrintLCS(c, x, i, j - 1);
//    }
//    else
//    {
//        PrintLCS(c, x, i - 1, j - 1);
//        printf("%c ", x[i - 1]);
//    }
//}

int main() 
{
   // char x[MAXLEN] = { "ABCBDAB" };
    //char y[MAXLEN] = { "BDCABA" };
    //char x[MAXLEN] = {"ACCGGTCGAGTGCGCGGAAGCCGGCCGAA"}; //�㷨������222ҳ��DNA�ļ������ƥ��
    //char y[MAXLEN] = {"GTCGTTCGGAATGCCGTTGCTCTGTAAA"};

    //int  c[MAXLEN][MAXLEN];     //����ʹ��һ��c��

    //int m, n;

    //m = strlen(x);
    //n = strlen(y);

    //LCSLength(x, y, m, n, c);
    //PrintLCS(c, x, m, n);

    std::cout << std::max(1, 1) << std::endl;

    return 0;
}