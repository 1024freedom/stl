#pragma once
#include<iostream>
enum class Color{RED,BLACK};
struct Node{
    Node* parent;//父节点
    Node* left;//左子节点
    Node* right;//右子节点
    Color color;//红或者黑
    int value;//数据
};
class Set{
    Node* root=nullptr;
    Node* find(int value){
        Node* current=root;
        while(current!=nullptr){
            if(value<current->value){
                current=current->left;
                continue;
            }
            if(value>current->value){
                current=current->right;
                continue;
            }
            break;
        }
        return current;
    }
    void fix_violation(Node* node){

    }
    bool insert(int value){
        Node* node=new Node;
        node->value=value;
        node->parent=nullptr;
        node->left=nullptr;
        node->right=nullptr;
        node->color=Color::RED;

        Node** parent=&root;//parent指向要插入位置的父节点的指针
        while(*parent!=nullptr){
            if(value<(*parent)->value){
                parent=&(*parent)->left;
                continue;
            }
            if(value>(*parent)->value){
                parent=&(*parent)->right;
                continue;
            }
            return false;
        }
        if(parent==nullptr){
            root=node;
        }else{
            *parent=node;
        }
        fix_violation(node);
        return true;
    }
};