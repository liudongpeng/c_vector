#ifndef _NS_VECTOR_H_
#define _NS_VECTOR_H_

#include <stdlib.h>

// ��������
enum data_type
{
    VAL_DOUBLE = 0,
    VAL_INT,
    VAL_CHAR
};

// vector������Ĭ�ϴ�С
#define DEFAULT_SIZE 1024UL

// �Զ����vector��������
typedef struct ns_vector_t
{
    double* arr;
    size_t size; // Ԫ������
    size_t cap;  // ����������
} vector_d;

/**
 * @brief ����һ�����doubel����ֵ��vector������������ÿ��Ԫ�س�ʼֵ��Ϊ0
 *
 * @param  size         ��ʼ������С��������� (size <= 0)������Ĭ�ϵ�����
 * @return vector_d*    ����һ��vector����ָ��
 */
vector_d* CreateDoubleVector(size_t size);

/**
 * @brief ��vector����β����������
 *
 * @param v     Ŀ��vector����
 * @param val   Ҫ���������
 */
void DoubelVectorPushBack(vector_d* v, double val);

/**
 * @brief �ͷ�vector����ռ�õ��ڴ�
 *
 */
void FreeVector(vector_d* v);

/**
 * @brief ��ȡ����Ԫ�������������������Ϊ�գ��򷵻�-1
 *
 * @param v         Ŀ��vector����
 * @return size_t   ����Ԫ������
 */
size_t GetVectorSize(vector_d* v);

#endif // _NS_VECTOR_H_
