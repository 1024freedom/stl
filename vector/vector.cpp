#include"./vector.h"
template<typename T>
Vector<T>::Vector():elements(nullptr),capacity(0),size(0){

}
Vector<T>::~Vector(){
    delete[] elements;
}
Vector<T>::Vector(const Vector& other):capacity(other.capacity),size(other.size){
    elements=new T[capacity];
    std::copy(other.elements,other.elements+size,elements);
}