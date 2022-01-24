#ifndef _NRU_H
#define _NRU_H

#include <bash.h>

p_str* nru_initpsHd(const int size); //����һ������size��p_str�ڵ��ѭ������
void nru_freepsHd(p_str* hd); //�ͷ�p_strѭ������
int nru_search(const int pagenum, p_str* const hd); //�����Ƿ�����
void nru_showps(p_str* const hd); //����ڴ�ҳ
void nru_pushPage(const int pagenum, p_str** hd); //�滻һ�����ҳ���ڴ� ����ԭҳд�����
int nru_simulate(const int* const orders, const int size); //��һ��ҳ������ģ��nru�㷨 ���������ʴ���

#endif