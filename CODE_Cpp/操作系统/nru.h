#ifndef _NRU_H
#define _NRU_H

#include <bash.h>

p_str* nru_initpsHd(const int size); //返回一个基于size个p_str节点的循环链表
void nru_freepsHd(p_str* hd); //释放p_str循环链表
int nru_search(const int pagenum, p_str* const hd); //搜索是否命中
void nru_showps(p_str* const hd); //输出内存页
void nru_pushPage(const int pagenum, p_str** hd); //替换一个外存页进内存 并将原页写回外存
int nru_simulate(const int* const orders, const int size); //对一组页数进行模拟nru算法 返回命中率次数

#endif