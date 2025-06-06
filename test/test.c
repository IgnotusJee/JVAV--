#include <stdio.h>
#include "../lib/libjvav.h"

int n;

int main() {
    n = getInt();
    
    int i;
    
    // while 循环输出 n 的阶乘
    int factorial;
    factorial = 1;
    i = 1;
    while (i <= n) {
        factorial = factorial * i;
        i++;
    }
    
    printInt(factorial);
    
    return 0;
}
