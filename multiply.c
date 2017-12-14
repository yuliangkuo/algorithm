#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*
 * 43. Multiply Strings
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2.

 * Note:

 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contains only digits 0-9.
 * Both num1 and num2 does not contain any leading zero.
 * You must not use any built-in BigInteger library or convert the inputs to integer directly.
 */

/*
 Total is

         i --->    1   2   3   size m
         j --->        9   9   size n
         --------------------
                       2   7
                   1   8
                0  9
                   2   7
                1  8
             0  9
    -------------------------------
    res[idx] 0  1  2   3   4   size m+n
*/

char* multiply(char* num1, char* num2) {
    int i, j;
    int m = strlen(num1);
    int n = strlen(num2);
    int *res = malloc( sizeof(int) * (m+n) );
    char *buf = malloc( sizeof(char) * (m+n+1) );

    for (i=0; i<m+n; i++)  {// important to init to zero
        res[i] = 0;
        buf[i] = '\0;';
    }    
    buf[m+n] = '\0';

    for (i=m-1; i>=0; i--) {
         for (j=n-1; j>=0; j--) {
             int p1 = (int)(num1[i] - '0');
             int p2 = (int)(num2[j] - '0');

             res[i+j+1] += (p1 * p2) % 10;
             res[i+j] += (p1 * p2) / 10;
         }
    }

    for (i=m+n-1; i >= 1 ; i--) {
        int mm = res[i];
        res[i-1] += mm / 10;
        res[i] = mm % 10;
    }

    for (i=0; i<m+n; i++) {
        buf[i] = (char)(res[i] + '0');
    }
    
    if (buf[0] == '0') 
        if(buf[1] == '0')
            return buf + m + n -1;
        else
            return buf + 1;

    return buf;
}
