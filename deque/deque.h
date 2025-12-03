#include <iostream>
#include <stdexcept>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
template<typename T>
class Deque{
private:
    T* elements;
    size_t capacity;//数组总容量
    size_t frontIndex;//队头索引
    size_t backIndex;//队尾索引
    size_t size;//当前元素数量
public:
    Deque();
    ~Deque();
    void push_front(const T& value);
    void push_back(const T& value);
    void pop_front();
    void pop_back();
    T& operator[](int index);
    size_t getSize() const;
    void clear();
    void printElements() const;
private:
    void resize();
};