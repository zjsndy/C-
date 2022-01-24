#ifndef _BASH_H
#define _BASH_H

#define PAGESIZE  1   //K  页面大小
#define MAXMEM    20  //页 内存容量
#define NONEMEM   4   //页 内存中不可访问的页数0~n-1页
#define OUTSIZE   40  //K  外存容量
#define ORDERSIZE 10  //条 每K存放指令数

#define ORDERTEST 1000000 //次 指令测试次数

// 页表
typedef struct p_str {
    int n_pagenum;         //页号
    int n_count;           //访问页面次数或访问时间等
    struct p_str* n_next;  //下一指针
} p_str;

p_str* initps(); //返回一个页表节点
void freeps(p_str* ops); //释放一个页表节点
int changeAddr(const int order); //将指令数转化为页数
int* initOrders(const int size); //返回一组模拟页数 
void showOrders(const int* const orders, const int size); //输出指令集

#endif