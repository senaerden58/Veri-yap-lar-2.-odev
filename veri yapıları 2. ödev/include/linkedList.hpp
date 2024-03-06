/** 
* @file linkedlist.hpp
* @description ağaçları tutan ve ekleme, çıkarma gibi fonksiyonları tutan linkedlisttir.Böylece gezinmeyi kolaylaştırır.
* @course 1. Öğretim A grubu
* @assignment 2. ödev
* @date 24.12.2024
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
*/
#ifndef linkedList_HPP
#define linkedList_HPP
#include "avl.hpp"

class ListNode{
    public:
        AVL data;
        ListNode* sonraki;
        ListNode(AVL data);
        int getNo()const;
        int no;
        static int sira;
};

class LinkedList {
    public:
        ListNode* head;
        int length = 0;
        void Add(AVL* tree);
        void cikar(AVL* tree);  
        void ascii();     
        void stackKontol();
        ListNode* kucukCikar();
        ListNode* buyukCikar();
        LinkedList();
        void stackResetle();

};

#endif