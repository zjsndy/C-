#ifndef _LRU_H
#define _LRU_H

#include <bash.h>

p_str* lru_initpsHd(const int size); //����һ������size��p_str�ڵ������
void lru_freepsHd(p_str* hd); //�ͷ�p_str����
int lru_search(const int pagenum, p_str* const hd, const int i); //�����Ƿ�����
void lru_showps(p_str* const hd); //����ڴ�ҳ
void lru_pushPage(const int pagenum, p_str** hd, const int i); //�滻һ�����ҳ���ڴ� ����ԭҳд�����
int lru_simulate(const int* const orders, const int size); //��һ��ҳ������ģ��lru�㷨 ���������ʴ���

#endif
