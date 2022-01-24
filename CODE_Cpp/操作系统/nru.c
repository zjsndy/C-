#include <nru.h>
#include <stdlib.h>
#include <stdio.h>

p_str* nru_initpsHd(const int size) {
    p_str* head = initps(), * tail = head, * nps;
    for (int i = 1; i < size; i++) {
        nps = initps();
        tail->n_next = nps;
        tail = nps;
    }
    tail->n_next = head;
    return head;
}

void nru_freepsHd(p_str* hd) {
    if (!hd) return;
    while (hd) {
        p_str* k = hd;
        hd = k->n_next;
        freeps(k);
    }
    return;
}

int nru_search(const int pagenum, p_str* const hd) {
    p_str* p = hd;
    if (p->n_pagenum == pagenum) {
        p->n_count = 1;
        return 1;
    }
    p = p->n_next;
    while (p != hd) {
        if (p->n_pagenum == pagenum) {
            p->n_count = 1;
            return 1;
        }
        p = p->n_next;
    }
    return 0;
}

void nru_showps(p_str* const hd) {
    p_str* p = hd;
    printf("ps[(%d, %d)", hd->n_pagenum, hd->n_count);
    for (p = p->n_next; p != hd; p = p->n_next)
        printf(" (%d, %d)", p->n_pagenum, p->n_count);
    printf("]\n");
}

void nru_pushPage(const int pagenum, p_str** hd) {
    if ((*hd)->n_pagenum != -1) {
        while ((*hd)->n_count) {
            (*hd)->n_count = 0;
            *hd = (*hd)->n_next;
        }
    }
    (*hd)->n_pagenum = pagenum;
    (*hd)->n_count = 1;
    *hd = (*hd)->n_next;
}

int nru_simulate(const int* const orders, const int size) {
    int hit = 0;
    p_str* hd = nru_initpsHd(MAXMEM - NONEMEM);
    for (int i = 0; i < size; i++) {
        int pagenum = changeAddr(orders[i]);
        if (nru_search(pagenum, hd))
            hit++;
        else
            nru_pushPage(pagenum, &hd);
    }
    return hit;