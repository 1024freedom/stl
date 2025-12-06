#pragma once
#include<iostream>
#include<algorithm>
#include<utility>   
enum class Color{RED,BLACK};
enum class Direction{LEFT,RIGHT};
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
    void rotate_left(Node* node){//左旋
        Node* right=node->right;
        if(node->parent!=nullptr){
            if(node->parent->left==node){
                node->parent->left=right;
            }else{
                node->parent->right=right;
            }
        }
        right->left=node;
        node->right=right->left;
        right->left->parent=node;
        right->parent=node->parent;
        node->parent=right;
    }
    void rotate_right(Node* node){//右旋
        Node* left=node->left;
        if(node->parent!=nullptr){
            if(node->parent->left==node){
                node->parent->left=left;
            }else{
                node->parent->right=left;
            }
        }
        left->right=node;
        node->left=left->right;
        left->right->parent=node;
        left->parent=node->parent;
        node->parent=left;
    }
    void fix_violation(Node* node){
        if(node->parent==nullptr){
            node->color=Color::BLACK;
            return;
        }

        Node* uncle;
        Node* parent=node->parent;
        Node* grandparent=parent->parent;
        Direction parent_dir=parent==grandparent->left?Direction::LEFT:Direction::RIGHT;
        Direction node_dir=node==parent->left?Direction::LEFT:Direction::RIGHT;
        if(node==parent->left){
            uncle=grandparent->right;
        }else{
            uncle=grandparent->left;
        }
        

        if(uncle->color==Color::RED){

            parent->color=Color::BLACK;
            uncle->color=Color::BLACK;
            grandparent->color=Color::RED;
            fix_violation(grandparent);
            return;

        }else{

            if(node_dir==Direction::LEFT&&parent_dir==Direction::LEFT){
                rotate_left(parent);
                std::swap(parent->color,grandparent->color);
                if(grandparent->color==Color::RED){
                    fix_violation(grandparent);
                }
            }else if(node_dir==Direction::RIGHT&&parent_dir==Direction::RIGHT){
                rotate_right(parent);
                std::swap(parent->color,grandparent->color);
                if(grandparent->color==Color::RED){
                    fix_violation(grandparent);
                }
            }else if(node_dir==Direction::LEFT&&parent_dir==Direction::RIGHT){
                rotate_left(parent);
            }else if(node_dir==Direction::RIGHT&&parent_dir==Direction::LEFT){
                rotate_right(parent);
            }
            
        }
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