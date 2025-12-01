#include"list.h"
template<typename T>
List<T>::List():head(nullptr),tail(nullptr),size(0){

}
template<typename T>
List<T>::~List(){
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
void List<T>::pop_front(){
    if(size>0){
        Node* newHead=head->next;
        delete head;
        head=newHead;
        if(head){
            head->prev=nullptr;
        }else{
            tail=nullptr;
        }
        --size;
    }
}
// 当编译器在处理模板时，如果遇到一个依赖于模板参数（如 T）的嵌套名称（如 List<T>::Node），
// 它默认认为这个名称是一个“变量”或“值”，而不是一个“类型”
// 需要加上 typename 关键字来强制告诉编译器：“请把这个名称当做一个类型来处理”。
template<typename T>
typename List<T>::Node* List<T>::getNode(const T& val){
    Node* current=head;
    while(current){
        if(current->data==val){
            return current;
        }
        current=current->next;
    }
    return nullptr;
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
    if(node==head&&node==tail){
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
    }else{
        node->prev->next=node->next;
        node->next->prev=node->prev;
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
typename List<T>::Node* List<T>::begin(){
    return head;
}
template<typename T>
typename List<T>::Node* List<T>::end(){
    return nullptr;
}
template<typename T>
const typename List<T>::Node* List<T>::begin()const{
    return head;
}
template<typename T>
const typename List<T>::Node* List<T>::end()const{
    return nullptr;
}
template<typename T>
void List<T>::printElements()const{
    for(Node* current=head;current!=nullptr;current=current->next){
        std::cout<<current->data<<" ";
    }
    std::cout<<std::endl;
}

//测试
int main(){
    //创建一个List对象
    List<int> myList;
    int N;
    std::cin>>N;
    //读走回车
    getchar();
    std::string line;
    //接受命令
    for(int i=0;i<N;++i){
        std::getline(std::cin,line);
        // 创建字符串输入流，用于解析命令和参数
        std::istringstream iss(line);
        std::string command;
        // 从输入流中提取第一个单词作为命令
        iss>>command;
        int value;
        if(command=="push_back"){
            iss>>value;
            myList.push_back(value);
        }else if(command=="push_front"){
            iss>>value;
            myList.push_front(value);
        }else if(command=="pop_back"){
            myList.pop_back();
        }else if(command=="print"){
            myList.printElements();
        }else if(command=="pop_front"){
            myList.pop_front();
        }else if(command=="remove"){
            iss>>value;
            myList.remove(value);
        }else if(command=="clear"){
            myList.clear();
        }else if(command=="empty"){
            std::cout<<(myList.empty()?"true":"false")<<std::endl;
        }else if(command=="getall"){
            std::cout<<myList<<std::endl;
        }else if(command=="find"){
            iss>>value;
            int* result=myList.find(value);
            if(result){
                std::cout<<*result<<std::endl;
            }else{
                std::cout<<"Not found"<<std::endl;
            }
        }
    }
    return 0;
}