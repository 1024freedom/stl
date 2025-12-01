#pragma once
#include<iostream>
#include<stdexcept>
#include<algorithm>
#include<sstream>
#include<string>

template<typename T>
class List{
public:
    template<typename L>
    //友元函数重载输出运算符
    friend std::ostream& operator<<(std::ostream& os, const List<L>& pt);
private:
    //定义节点结构
    struct Node{
        T data;// 数据
        Node* next;//指向下一个节点的指针
        Node* prev;//指向前一个节点的指针
        //构造函数
        Node(const T& value,Node* nextNode=nullptr,Node* prevNode=nullptr)
            :data(value),next(nextNode),prev(prevNode){};
    };
    Node* head;//头指针
    Node* tail;//尾指针
    size_t size;//链表大小
public:
    //构造函数
    List();
    //析构函数
    ~List();
    //在链表末尾添加元素
    void push_back(const T& value);
    //在链表开头添加元素
    void push_front(const T& value);   
    //获取链表中节点的数量
    size_t getSize()const;
    //访问链表中的元素
    T& operator[](size_t index);
    //const版本访问链表中的元素
    const T& operator[](size_t index)const;
    //删除链表末尾的元素
    void pop_back();
    //删除链表开头的元素
    void pop_front();
    //获取指定值的节点
    Node* getNode(const T& val);
    //查找指定值的节点
    T* find(const T& val);
    //删除指定值的节点
    void remove(const T& val);
    //判断是否为空
    bool empty();
    //清空链表
    void clear();
    //使用迭代器遍历链表的开始位置
    Node* begin();
    //使用迭代器遍历链表的结束位置(尾后位置)
    Node* end();
    //使用迭代器遍历链表的开始位置const版本
    const Node* begin()const;
    //使用迭代器遍历链表的结束位置const版本
    const Node* end()const;
    //打印链表中的元素
    void printElements()const;
}