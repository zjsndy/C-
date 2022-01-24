#ifndef _LRU_H
#define _LRU_H

#include <bash.h>

p_str* lru_initpsHd(const int size); //返回一个基于size个p_str节点的链表
void lru_freepsHd(p_str* hd); //释放p_str链表
int lru_search(const int pagenum, p_str* const hd, const int i); //搜索是否命中
void lru_showps(p_str* const hd); //输出内存页
void lru_pushPage(const int pagenum, p_str** hd, const int i); //替换一个外存页进内存 并将原页写回外存
int lru_simulate(const int* const orders, const int size); //对一组页数进行模拟lru算法 返回命中率次数

#endif
