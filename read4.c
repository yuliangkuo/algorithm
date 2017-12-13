#include <stdio.h>
#include <string.h>

/*
 The API: int read4(char *buf) reads 4 characters at a time from a file.
 The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
 By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.

 Note: The read function may be called multiple times.
*/

int read4(char *buf)
{
	int len = strlen(buf);
	
	if (len >= 4) 
		return 4;
	else 
		return len;
}


int min(int a, int b)
{
    if (a > b) return b;
    return a;
}

/**
 * @param buf Destination buffer
 * @param n   Maximum number of characters to read
 * @return    The number of characters read
 * */
int read(char *buf, int n) {
    int len = 0;  // len is the total number of characters we read 
    int m = 0;
    while (len < n) {  // len should be always <=n 
        m = read4(buf+len); 
        printf("m %d\n", m);
        len += min(m, n-len);   
        if (m < 4) break;
    }
    return len;
}

int main(void)
{
	char *buf = "12345678901234567890";
	int result = 0;
	
	int n1 = 3, n2 = 5, n3 = 10, n4 = 22, n5 = 20;

    result = read(buf, n1);
	printf("n1: %d\n", result);
    result = read(buf, n2);
	printf("n2: %d\n", result);
    result = read(buf, n3);
	printf("n3: %d\n", result);
    result = read(buf, n4);
	printf("n4: %d\n", result);

    result = read(buf, n5);
	printf("n4: %d\n", result);
}
