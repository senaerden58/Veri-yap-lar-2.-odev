/** 
* @file yigit.hpp
* @description stack yapısının uzunluğunu, stack düğümünün özelliklerini ve stack yapısının yapması gereken fonksiyonları tutar.
* @course 1. Öğretim A grubu
* @assignment 2. ödev
* @date 24.12.2024
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
*/
#ifndef YIGIT_HPP
#define YIGIT_HPP

class StackNode{
        public:
	int veri;
	StackNode *sonraki;
        StackNode(const int veri,StackNode *sonraki);
};

class Stack{
	public:
        int stackNo;
        int length;
        int sira;
        bool isEmpty;
        StackNode* last;
        StackNode* head;
        StackNode* topOfStack;
        Stack();
        ~Stack();
        bool bosMu()const;
        void push(const int item);
        void pop();
        void yazdir();
        void sifirla();
        int top()const;
        void StackSil();
        void bosalt();
};
#endif