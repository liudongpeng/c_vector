#include <string.h>
#include "NsVector.h"

/**
 * @brief 创建一个存放doubel类型值的vector容器，容器中每个元素初始值都为0
 *
 * @param  size         初始容量大小，若传入的 (size <= 0)，则用默认的容量
 * @return vector_d*    返回一个vector容器指针
 */
vector_d* CreateDoubleVector(size_t size)
{
    vector_d* v = NULL; // vector容器指针
    size_t cap = 0;     // 容量

    // 确定容器大小
    cap = size <= 0 ? DEFAULT_SIZE : size;

    // 开辟空间
    v = (vector_d*)malloc(sizeof(vector_d));
    memset(v, 0, sizeof(vector_d));
    v->cap = cap;

    v->arr = (double*)malloc(cap * sizeof(double));
    memset(v->arr, 0, cap * sizeof(double));

    // 返回容器指针
    return v;
}

/**
 * @brief 释放vector容器占用的内存
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
 * @brief 从vector容器尾部插入数据
 *
 * @param v     目标vector容器
 * @param val   要插入的数据
 */
void DoubelVectorPushBack(vector_d* v, double val)
{
    double* tmp = NULL;
    size_t cap = 0;

    if (v == NULL || v->arr == NULL)
    {
        return;
    }

    // 容量不够了，需要扩容
    if (v->size >= v->cap)
    {
        cap = v->cap * 1.5;
        tmp = (double*)malloc(cap * sizeof(double));

        // 拷贝数据
        memmove(tmp, v->arr, v->size * sizeof(double));

        // 释放原先申请的空间
        free(v->arr);

        // 更换内存区域
        v->arr = tmp;
    }

    // 追加数据
    v->arr[v->size] = val;
    (v->size)++;
}

/**
 * @brief 获取容器元素数量，若传入的容器为空，则返回-1
 *
 * @param v         目标vector容器
 * @return size_t   容器元素数量
 */
size_t GetVectorSize(vector_d* v)
{
    if (v != NULL)
    {
        return v->size;
    }
    return -1;
}
