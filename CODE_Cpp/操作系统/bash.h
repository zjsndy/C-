#ifndef _BASH_H
#define _BASH_H

#define PAGESIZE  1   //K  ҳ���С
#define MAXMEM    20  //ҳ �ڴ�����
#define NONEMEM   4   //ҳ �ڴ��в��ɷ��ʵ�ҳ��0~n-1ҳ
#define OUTSIZE   40  //K  �������
#define ORDERSIZE 10  //�� ÿK���ָ����

#define ORDERTEST 1000000 //�� ָ����Դ���

// ҳ��
typedef struct p_str {
    int n_pagenum;         //ҳ��
    int n_count;           //����ҳ����������ʱ���
    struct p_str* n_next;  //��һָ��
} p_str;

p_str* initps(); //����һ��ҳ��ڵ�
void freeps(p_str* ops); //�ͷ�һ��ҳ��ڵ�
int changeAddr(const int order); //��ָ����ת��Ϊҳ��
int* initOrders(const int size); //����һ��ģ��ҳ�� 
void showOrders(const int* const orders, const int size); //���ָ�

#endif