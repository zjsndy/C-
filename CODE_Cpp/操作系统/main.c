#include <bash.h>
#include <fifo.h>
#include <opt.h>
#include <lru.h>
#include <nru.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int testOrders_opt[] = { 70, 0, 10, 20, 0, 30, 0, 40, 20, 30, 0, 30, 20, 10, 20, 0, 10, 70, 0, 10 };
int testOrders_fifo[] = { 30, 20, 10, 0, 30, 20, 40, 30, 20, 10, 0, 40 };
int testOrders_lru[] = { 10, 80, 10, 70, 80, 20, 70, 20, 10, 80, 30, 80, 20, 10, 30, 10, 70, 10, 30, 70 };
int testOrders_nru[] = { 10, 30, 40, 20, 50, 60, 30, 40, 70 };

void test() {
    printf("OPT  HIT RATE: %lf\n", (double)opt_simulate(testOrders_opt, 20) / 20);
    printf("FIFO HIT RATE: %lf\n", (double)fifo_simulate(testOrders_fifo, 12) / 12);
    printf("LRU  HIT RATE: %lf\n", (double)lru_simulate(testOrders_lru, 20) / 20);
    printf("NRU  HIT RATE: %lf\n", (double)nru_simulate(testOrders_nru, 9) / 9);
}

void showSimulate() {
    int* orders = initOrders(ORDERTEST);
    printf("OPT  HIT RATE: %lf\n", (double)opt_simulate(orders, ORDERTEST) / ORDERTEST);
    printf("FIFO HIT RATE: %lf\n", (double)fifo_simulate(orders, ORDERTEST) / ORDERTEST);
    printf("LRU  HIT RATE: %lf\n", (double)lru_simulate(orders, ORDERTEST) / ORDERTEST);
    printf("NRU  HIT RATE: %lf\n", (double)nru_simulate(orders, ORDERTEST) / ORDERTEST);
    free(orders);
}

int main() {
    srand(time(NULL));
    int i = 1;
    while (1) {
        printf("%d:\n", i++);
        showSimulate();
        putchar(10);
    }
    return 0;
}



