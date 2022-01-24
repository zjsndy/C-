#include <opt.h>
#include <stdlib.h>
#include <stdio.h>

p_str* opt_initpsHd(const int size) {
    p_str* head = initps(), * tail = head, * nps;
    for (int i = 1; i < size; i++) {
        nps = initps();
        tail->n_next = nps;
        tail = nps;
    }
    return head;
}

void opt_freepsHd(p_str* hd) {
    if (!hd) return;
    while (hd) {
        p_str* k = hd;
        hd = k->n_next;
        freeps(k);
    }
    return;
}

int opt_search(const int pagenum, p_str* const hd) {
    for (p_str* p = hd; p; p = p->n_next)
        if (p->n_pagenum == pagenum) return 1;
    return 0;
}

void opt_showps(p_str* const hd) {
    printf("ps[");
    for (p_str* p = hd; p; p = p->n_next)
        printf(" %d", p->n_pagenum);
    printf("]\n");
}

void opt_pushPage(const int pagenum, p_str** hd, const int* const orders, const int mask, const int size) {
    p_str* p;
    for (p = *hd; p && p->n_pagenum != -1; p = p->n_next);
    if (p) {
        p->n_pagenum = pagenum;
        return;
    }

    int j = mask, tmp, mem = (*hd)->n_pagenum;
    int* jud = (int*)malloc(sizeof(int) * OUTSIZE);
    for (int i = 0; i < OUTSIZE; i++)
        jud[i] = 0;
    while (++j != size) {
        jud[changeAddr(orders[j])] = 1;
        tmp = 0;
        for (p = *hd; p; p = p->n_next) {
            if (!jud[p->n_pagenum]) {
                tmp++;
                if (tmp == 2) break;
                mem = p->n_pagenum;
            }
        }
        if (tmp == 1) break;
    }
    for (p = *hd; p->n_pagenum != mem; p = p->n_next);
    p->n_pagenum = pagenum;

    free(jud);
}

int opt_simulate(const int* const orders, const int size) {
    int hit = 0;
    p_str* hd = opt_initpsHd(MAXMEM - NONEMEM);
    for (int i = 0; i < size; i++) {
        int pagenum = changeAddr(orders[i]);
        if (opt_search(pagenum, hd))
            hit++;
        else
            opt_pushPage(pagenum, &hd, orders, i, size);
    }
    return hit;
}