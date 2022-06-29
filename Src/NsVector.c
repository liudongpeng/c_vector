#include <string.h>
#include "NsVector.h"

/**
 * @brief ����һ�����doubel����ֵ��vector������������ÿ��Ԫ�س�ʼֵ��Ϊ0
 *
 * @param  size         ��ʼ������С��������� (size <= 0)������Ĭ�ϵ�����
 * @return vector_d*    ����һ��vector����ָ��
 */
vector_d* CreateDoubleVector(size_t size)
{
    vector_d* v = NULL; // vector����ָ��
    size_t cap = 0;     // ����

    // ȷ��������С
    cap = size <= 0 ? DEFAULT_SIZE : size;

    // ���ٿռ�
    v = (vector_d*)malloc(sizeof(vector_d));
    memset(v, 0, sizeof(vector_d));
    v->cap = cap;

    v->arr = (double*)malloc(cap * sizeof(double));
    memset(v->arr, 0, cap * sizeof(double));

    // ��������ָ��
    return v;
}

/**
 * @brief �ͷ�vector����ռ�õ��ڴ�
 *
 */
void FreeVector(vector_d* v)
{
    if (v->arr != NULL)
    {
        free(v->arr);
    }

    if (v != NULL)
    {
        free(v);
    }
}

/**
 * @brief ��vector����β����������
 *
 * @param v     Ŀ��vector����
 * @param val   Ҫ���������
 */
void DoubelVectorPushBack(vector_d* v, double val)
{
    double* tmp = NULL;
    size_t cap = 0;

    if (v == NULL || v->arr == NULL)
    {
        return;
    }

    // ���������ˣ���Ҫ����
    if (v->size >= v->cap)
    {
        cap = v->cap * 1.5;
        tmp = (double*)malloc(cap * sizeof(double));

        // ��������
        memmove(tmp, v->arr, v->size * sizeof(double));

        // �ͷ�ԭ������Ŀռ�
        free(v->arr);

        // �����ڴ�����
        v->arr = tmp;
    }

    // ׷������
    v->arr[v->size] = val;
    (v->size)++;
}

/**
 * @brief ��ȡ����Ԫ�������������������Ϊ�գ��򷵻�-1
 *
 * @param v         Ŀ��vector����
 * @return size_t   ����Ԫ������
 */
size_t GetVectorSize(vector_d* v)
{
    if (v != NULL)
    {
        return v->size;
    }
    return -1;
}
