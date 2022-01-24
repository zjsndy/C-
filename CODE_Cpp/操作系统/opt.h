#ifndef _OPT_H
#define _OPT_H

#include <bash.h>

p_str* opt_initpsHd(const int size); //返回一个基于size个p_str节点的链表
void opt_freepsHd(p_str* hd); //释放p_str链表
int opt_search(const int pagenum, p_str* const hd); //搜索是否命中
void opt_showps(p_str* const hd); //输出内存页
void opt_pushPage(const int pagenum, p_str** hd, const int* const orders, const int mask, const int size); //替换一个外存页进内存 并将原页写回外存
int opt_simulate(const int* const orders, const int size); //对一组页数进行模拟opt算法 返回命中率次数

#endif