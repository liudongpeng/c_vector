#ifndef _NS_VECTOR_H_
#define _NS_VECTOR_H_

#include <stdlib.h>

// 数据类型
enum data_type
{
    VAL_DOUBLE = 0,
    VAL_INT,
    VAL_CHAR
};

// vector容器的默认大小
#define DEFAULT_SIZE 1024UL

// 自定义的vector容器类型
typedef struct ns_vector_t
{
    double* arr;
    size_t size; // 元素数量
    size_t cap;  // 容器的容量
} vector_d;

/**
 * @brief 创建一个存放doubel类型值的vector容器，容器中每个元素初始值都为0
 *
 * @param  size         初始容量大小，若传入的 (size <= 0)，则用默认的容量
 * @return vector_d*    返回一个vector容器指针
 */
vector_d* CreateDoubleVector(size_t size);

/**
 * @brief 从vector容器尾部插入数据
 *
 * @param v     目标vector容器
 * @param val   要插入的数据
 */
void DoubelVectorPushBack(vector_d* v, double val);

/**
 * @brief 释放vector容器占用的内存
 *
 */
void FreeVector(vector_d* v);

/**
 * @brief 获取容器元素数量，若传入的容器为空，则返回-1
 *
 * @param v         目标vector容器
 * @return size_t   容器元素数量
 */
size_t GetVectorSize(vector_d* v);

#endif // _NS_VECTOR_H_
