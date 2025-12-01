#include"./list.h"
template<typename T>
List::List():head(nullptr),tail(nullptr),size(0){

}
template<typename T>
List::~List(){
    clear();
}
template<typename T>
void List<T>::push_back(const T& value){
    //创建新的节点
    Node* newNode=new Node(value,nullptr,tail);//值，下，前
    if(tail){
        //如果链表非空，将尾部节点的next指针指向新节点（连接）
        tail->next=newNode;
    }else{
        //如果链表为空，新节点同时也是头节点
        head=newNode;
    }
    tail=newNode;
    ++size;
}
template<typename T>
void List<T>::push_front(const T& value){
    Node* newNode=new Node(value,head,nullptr);//值，下，前
    if(head){
        //如果链表非空，将头节点的prev指针指向新节点
        head->prev=newNode;
    }else{
        //如果链表为空，新节点同时也是尾节点
        tail=newNode;
    }
    head=newNode;
    ++size;
}
template<typename T>
size_t List<T>::getSize()const{
    return size;
}
template<typename T>
T& List<T>::operator[](size_t index){
    Node* current=head;
    for(size_t i=0;i<index;++i){
        if(!current){
            //越界抛出异常
            throw std::out_of_range("Index out of range");
        }
        current=current->next;
    }
    return current->data;
}
template<typename T>
const T& List<T>::operator[](size_t index)const{
    Node* current=head;
    for(size_t i=0;i<index;++i){
        if(!current){
            //越界抛出异常
            throw std::out_of_range("Index out of range");
        }
        current=current->next;
    }
    return current->data;
}
template<typename T>
void List<T>::pop_back(){
    if(size>0){
        Node* newTail=tail->prev;
        delete tail;
        tail=newTail;
        if(tail){
            tail->next=nullptr;
        }else{
            head=nullptr;
        }
        --size;
    }
}
template<typename T>
void List<T>::getNode(const T& val){
    Node* current=head;
    while(current){
        if(current->data==val){
            return current;
        }
        current=current->next;
    }
}
template<typename T>
T* List<T>::find(const T& val){
    Node* node=getNode(val);
    if(node){
        return &(node->data);
    }
    return nullptr;
}
template<typename T>
void List<T>::remove(const T& val){
    Node* node=getNode(val);
    //既不是头节点也不是尾节点
    if(node){
        node->prev->next=node->next;
        node->next->prev=node->prev;
        delete node;
        --size;
    }else if(node==head&&node==tail){
        //如果是头节点也尾节点，同时删除
        delete node;
        head=nullptr;
        tail=nullptr;
        --size;
    }else if(node==head){
        head=node->next;
        head->prev=nullptr;
        delete node;
        --size;
    }else if(node==tail){
        tail=node->prev;
        tail->next=nullptr;
        delete node;
        --size;
    }
}
template<typename T>
bool List<T>::empty(){
    return size==0;
}
template<typename T>
void List<T>::clear(){
    while(!empty()){
        pop_back();
    }
}
template<typename T>
Node* List<T>::begin(){
    return head;
}
template<typename T>
Node* List<T>::end(){
    return nullptr;
}
template<typename T>
const Node* List<T>::begin()const{
    return head;
}
template<typename T>
const Node* List<T>::end()const{
    return nullptr;
}
template<typename T>
void List<T>::printElements()const{
    for(Node* current=head;current!=nullptr;current=current->next){
        std::cout<<current->data>>" ";
    }
    std::cout<<std::endl;
}