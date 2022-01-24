#ifndef _FIFO_H
#define _FIFO_H

#include <bash.h>

p_str* fifo_initpsHd(const int size); //����һ������size��p_str�ڵ��ѭ������
void fifo_freepsHd(p_str* hd); //�ͷ�p_strѭ������
int fifo_search(const int pagenum, p_str* const hd); //�����Ƿ�����
void fifo_showps(p_str* const hd); //����ڴ�ҳ
void fifo_pushPage(const int pagenum, p_str** hd); //�滻һ�����ҳ���ڴ� ����ԭҳд�����
int fifo_simulate(const int* const orders, const int size); //��һ��ҳ������ģ��fifo�㷨 ���������ʴ���

#endif