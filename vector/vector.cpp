#include<./vector.h>
template<typename T>
Vector<T>::Vector():elements(nullptr),capacity(0),size(0){

}
template<typename T>
Vector<T>::~Vector(){
    delete[] elements;
}
template<typename T>
Vector<T>::Vector(const Vector<T>& other):capacity(other.capacity),size(other.size){
    elements=new T[capacity];  
    std::copy(other.elements,other.elements+size,elements);
}
template<typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other){
    if(this!=&other){
        delete[] elements;
        capacity=other.capacity;
        size=other.size;
        elements=new T[capacity];
        std::copy(other.elements,other.elements+size,elements);
    }
    return *this;
}
template<typename T>   
void Vector<T>::push_back(const T& value){
    if(size==capacity){
        //如果数组已满，扩展容量
        reserve(capacity==0?1:2*capacity);
    }
    elements[size++]=value;

}
template<typename T>
size_t Vector<T>::getSize()const{
    return size;
}  
template<typename T>
size_t Vector<T>::getCapacity()const{
    return capacity;
}
template<typename T>
T& Vector<T>::operator[](size_t index){
    //检查索引是否越界
    if(index>=size){
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}
template<typename T>
const T& operator[](size_t index) const{
    //检查索引是否越界
    if(index>=size){
        throw std::out_of_range("Index out of range");
    }
    return elements[index];
}
template<typename T>
void Vector<T>::insert(size_t index,const T& value){
    if(index>size){
        throw std::out_of_range("Index out of range");
    }
    if(size==capacity){
        reserve(capacity==0?1:capacity*2);
    }
    for(size_t i=size;i>index;i--){
        elements[i]=elements[i-1];
    }
    elements[index]=value;
    ++size;
}
template<typename T>
void Vector<T>::pop_back(){
    if(size>0){
        --size;
    }
}
template<typename T>
void Vector<T>::clear(){
    size=0;
}
template<typename T>
T* Vector<T>::begin(){
    return elements;
}
template<typename T>
T* Vector<T>::end(){
    return elements+size;
}
template<typename T>
const T* Vector<T>::begin() const{
    return elements;
}
template<typename T>
const T* Vector<T>::end() const{    
    return elements+size;
}
template<typename T>
void Vector<T>::printElements() const{
    for(size_t i=0;i<size;++i){
        std::cout<<elements[i]<<" ";
    }
    std::cout<<std::endl;
}
template<typename T>
void Vector<T>::reserve(size_t newCapacity){
    if(newCapacity>capacity){
        T* newElements=new T[newCapacity];
        std::copy(elements,elements+size,newElements);
        delete[] elements;
        elements=newElements;
        capacity=newCapacity;
    }
}