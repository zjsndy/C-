#ifndef _FIFO_H
#define _FIFO_H

#include <bash.h>

p_str* fifo_initpsHd(const int size); //返回一个基于size个p_str节点的循环链表
void fifo_freepsHd(p_str* hd); //释放p_str循环链表
int fifo_search(const int pagenum, p_str* const hd); //搜索是否命中
void fifo_showps(p_str* const hd); //输出内存页
void fifo_pushPage(const int pagenum, p_str** hd); //替换一个外存页进内存 并将原页写回外存
int fifo_simulate(const int* const orders, const int size); //对一组页数进行模拟fifo算法 返回命中率次数

#endif