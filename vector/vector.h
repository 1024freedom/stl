#ifndef VECTOR_H
#define VECTOR_H
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<stdexcept>

template<typename T>

class Vector {
private:
    T* elements;// 指向动态数组的指针
    size_t capacity;// 数组的容量
    size_t size;// 当前元素的数量
public:
    Vector();
    ~Vector();
    //拷贝构造函数
    Vector(const Vector& other);
    //拷贝赋值操作符
    Vector& operator=(const Vector& other);
    //添加元素到数组末尾
    void push_back(const T& value);
    //获取数组中元素个数
    size_t getSize()const;
    //获取数组容量
    size_t getCapacity()const;
    //访问数组中的元素
    T& operator[](size_t index);
    //访问数组元素的常量版本
    const T& operator[](size_t index) const;
    //在指定位置插入元素
    void insert(size_t index, const T& value);
    //删除数组末尾元素
    void pop_back();
    //清空数组
    void clear();
    //使用迭代器遍历数组的开始位置
    T* begin();
    //使用迭代器遍历数组的结束位置
    T* end();
    //使用迭代器遍历数组的开始位置常量版本
    const T* begin() const;
    //使用迭代器遍历数组的结束位置常量版本
    const T* end() const;
    //打印数组中的元素
    void printElements() const;
private:
    //扩展数组容量
    void resize(size_t newCapacity);

};
#endif // VECTOR_H
    