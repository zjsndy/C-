#ifndef _OPT_H
#define _OPT_H

#include <bash.h>

p_str* opt_initpsHd(const int size); //����һ������size��p_str�ڵ������
void opt_freepsHd(p_str* hd); //�ͷ�p_str����
int opt_search(const int pagenum, p_str* const hd); //�����Ƿ�����
void opt_showps(p_str* const hd); //����ڴ�ҳ
void opt_pushPage(const int pagenum, p_str** hd, const int* const orders, const int mask, const int size); //�滻һ�����ҳ���ڴ� ����ԭҳд�����
int opt_simulate(const int* const orders, const int size); //��һ��ҳ������ģ��opt�㷨 ���������ʴ���

#endif