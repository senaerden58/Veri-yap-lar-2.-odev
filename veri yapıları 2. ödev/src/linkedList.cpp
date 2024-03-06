#include "linkedList.hpp"
#include "avl.hpp"
#include "iostream"
#include "cstdlib"

using namespace std;

int ListNode::sira = 0;

int ListNode::getNo()const{
    return no;
}

ListNode::ListNode(AVL tree){
    data = tree;
    sonraki = nullptr;
    sira++;
    no = sira;
    cout << no;
}

LinkedList::LinkedList(){
    head= nullptr;
    length = 0;
}

void LinkedList::Add(AVL* tree){
    if(head == nullptr)
    {
        head = new ListNode(*tree);
    }
    else
    {
        ListNode* current = head;
        while (current->sonraki != nullptr)
        {
            current = current->sonraki;
        }
        current->sonraki = new ListNode(*tree);
    }
    length++;
    
}

void LinkedList::cikar(AVL* tree){
    ListNode* current = head;
    ListNode* prev = nullptr;

    while (current != nullptr) {
        if (&current->data == tree) {
            if (prev == nullptr) 
            {
                head = current->sonraki;
            } 
            else 
            {
                prev->sonraki = current->sonraki;
            }
            delete current;
            length--;
            return; 
        }
        prev = current;
        current = current->sonraki;
    }
}

void LinkedList::ascii(){
    ListNode* current = head;
    while (current != nullptr)
    {
        current->data.toplam = 0;
        current->data.yazdir();
        current = current->sonraki;
    }
}

ListNode* LinkedList::kucukCikar(){
    ListNode * current = head;
    ListNode* kucuk = current;

    while (current != nullptr){
        if(current->data.stack.topOfStack->veri < kucuk->data.stack.topOfStack->veri)
        {
            kucuk  = current;
        }
        else if (current->data.stack.topOfStack->veri == kucuk->data.stack.topOfStack->veri) 
        {
            if(kucuk->getNo() > current->getNo())
            {
                kucuk = current;
            }
            else
            {
                kucuk = kucuk;
            }
        }
        current = current->sonraki;
    }
    kucuk->data.stack.pop();
    return kucuk;
}

ListNode* LinkedList::buyukCikar(){
    ListNode * current = head;
    ListNode* buyuk = current;

    while (current != nullptr)
    {
        if(current->data.stack.topOfStack->veri > buyuk->data.stack.topOfStack->veri)
        {
            buyuk  = current;
        }
        else if (current->data.stack.topOfStack->veri == buyuk->data.stack.topOfStack->veri) 
        {
            if(buyuk->getNo() > current->getNo())
            {
                buyuk = current;
            }
            else
            {
                buyuk = buyuk;
            }
        }
        current = current->sonraki;
    }
    buyuk->data.stack.pop();
    return buyuk;
}

void LinkedList::stackResetle()
{
    ListNode* current = head;
    while (current != nullptr)
    {
        current->data.stack.sifirla();
        current = current->sonraki;
    }
    
}

void LinkedList::stackKontol()
{
    bool buyuk = false;
    ListNode* current = head;
    ListNode* node;
    ascii();

    while (length > 1)
    {

        if(!buyuk)
        {
            node = kucukCikar();
            buyuk = true;
            if(node->data.stack.isEmpty)
            {
                cikar(&node->data);
                system("cls");
                stackResetle();
                buyuk = false;
                ascii();
                current = head;
            }
            else
            {
                if(current->sonraki != nullptr)
                {
                current = current->sonraki;
                }
                current = head;
            }
        }
            
        else if(buyuk){
            node = buyukCikar();
            buyuk = false;
            if(node->data.stack.isEmpty)
            {
                cikar(&node->data);
                stackResetle();
                system("cls");
                ascii();
                current = head;
            }
            else
            {
                if(current->sonraki != nullptr)
                {
                    current = current->sonraki;
                }
                current = head;
            } 
        }
    }
	system("cls");
    cout << "==================================="<<endl;
	cout<<  "|                                 |"<<endl;  
    cout << "|        " << "AVL NO: "<<current->getNo()<<"              |"<<endl;
	cout << "|        "<<"AVL KARAKTERI:  ";
	ascii();
	cout<<"        |              "<<endl;
	cout<<  "|                                 |"<<endl;  
	cout << "==================================="<<endl;
}