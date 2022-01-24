#include <fifo.h>
#include <stdlib.h>
#include <stdio.h>

p_str* fifo_initpsHd(const int size) {
    p_str* head = initps(), * tail = head, * nps;
    for (int i = 1; i < size; i++) {
        nps = initps();
        tail->n_next = nps;
        tail = nps;
    }
    tail->n_next = head;
    return head;
}

void fifo_freepsHd(p_str* hd) {
    if (!hd) return;
    while (hd) {
        p_str* k = hd;
        hd = k->n_next;
        freeps(k);
    }
    return;
}

int fifo_search(const int pagenum, p_str* const hd) {
    p_str* p = hd;
    if (p->n_pagenum == pagenum) return 1;
    p = p->n_next;
    while (p != hd) {
        if (p->n_pagenum == pagenum) return 1;
        p = p->n_next;
    }
    return 0;
}

void fifo_showps(p_str* const hd) {
    p_str* p = hd;
    printf("ps[%d", hd->n_pagenum);
    for (p = p->n_next; p != hd; p = p->n_next)
        printf(" %d", p->n_pagenum);
    printf("]\n");
}

void fifo_pushPage(const int pagenum, p_str** hd) {
    (*hd)->n_pagenum = pagenum;
    *hd = (*hd)->n_next;
}

int fifo_simulate(const int* const orders, const int size) {
    int hit = 0;
    p_str* hd = fifo_initpsHd(MAXMEM - NONEMEM);

    for (int i = 0; i < size; i++) {
        int pagenum = changeAddr(orders[i]);
        if (fifo_search(pagenum, hd))
            hit++;
        else
            fifo_pushPage(pagenum, &hd);
    }
    return hit;
}