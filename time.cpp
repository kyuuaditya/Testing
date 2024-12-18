#include <iostream>
#include <time.h>
int main(void) {
    clock_t starttime = clock();
    for (int i = 0; i < 10000000; i++) {
    }
    std::cout << (double)(clock() - starttime) / CLOCKS_PER_SEC;
}