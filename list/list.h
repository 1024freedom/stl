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
}