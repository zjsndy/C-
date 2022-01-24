#include <bash.h>
#include <stdlib.h>
#include <stdio.h>

p_str* initps() {
    p_str* nps = (p_str*)malloc(sizeof(p_str));
    nps->n_pagenum = -1;
    nps->n_count = -1;
    nps->n_next = NULL;

    return nps;
}

void freeps(p_str* ops) {
    if (!ops)
        return;
    free(ops);
    return;
}

int changeAddr(const int order) {
    return order / ORDERSIZE;
}

int* initOrders(const int size) {
    int* orders = (int*)malloc(sizeof(int) * size);

    for (int i = 0; i < size; i++)
        orders[i] = rand() % (OUTSIZE * ORDERSIZE);

    return orders;
}

void showOrders(const int* const orders, const int size) {
    printf("Orders[");
    for (int i = 0; i < size; i++) {
        if (i) printf(" ");
        printf("%d", orders[i]);
    }
    printf("]\n");
    printf("Pagenums[");
    for (int i = 0; i < size; i++) {
        if (i) printf(" ");
        printf("%d", changeAddr(orders[i]));
    }
    printf("]\n");
}
