#include <lru.h>
#include <stdlib.h>
#include <stdio.h>

p_str* lru_initpsHd(const int size) {
    p_str* head = initps(), * tail = head, * nps;
    for (int i = 1; i < size; i++) {
        nps = initps();
        tail->n_next = nps;
        tail = nps;
    }
    return head;
}

void lru_freepsHd(p_str* hd) {
    if (!hd) return;
    while (hd) {
        p_str* k = hd;
        hd = k->n_next;
        freeps(k);
    }
    return;
}

int lru_search(const int pagenum, p_str* const hd, const int i) {
    for (p_str* p = hd; p; p = p->n_next) {
        if (p->n_pagenum == pagenum) {
            p->n_count = i;
            return 1;
        }
    }
    return 0;
}

void lru_showps(p_str* const hd) {
    printf("ps[");
    for (p_str* p = hd; p; p = p->n_next)
        printf(" (%d, %d)", p->n_pagenum, p->n_count);
    printf("]\n");
}

void lru_pushPage(const int pagenum, p_str** hd, const int i) {
    p_str* p, * mem = *hd;
    int old = (*hd)->n_count;
    for (p = (*hd)->n_next; p; p = p->n_next) {
        if (old > p->n_count) {
            mem = p;
            old = p->n_count;
        }
    }
    mem->n_pagenum = pagenum;
    mem->n_count = i;
}

int lru_simulate(const int* const orders, const int size) {
    int hit = 0;
    p_str* hd = lru_initpsHd(MAXMEM - NONEMEM);
    for (int i = 0; i < size; i++) {
        int pagenum = changeAddr(orders[i]);
        if (lru_search(pagenum, hd, i))
            hit++;
        else
            lru_pushPage(pagenum, &hd, i);
    }
    return hit;
}
