#include <stdio.h>
#include "../lib/libjvav.h"

int n;

int main() {
    n = getInt();
    
    // for循环输出 1 ~ n
    int i;
    for (i = 1; i <= n; i++) {
        printInt(i);
        print(" ");
    }
    
    return 0;
}
