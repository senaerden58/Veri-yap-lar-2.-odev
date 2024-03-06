#include "yigit.hpp"
#include <iostream>
using namespace std;

StackNode::StackNode(const int veri,StackNode *sonraki=NULL){
	this->veri = veri;
	this->sonraki = sonraki;
}
	
Stack::Stack()
{
	topOfStack=NULL;
	stackNo += 1;
	StackNode* head;
	StackNode* last;
	length = 0;
	sira = 0;
	isEmpty = true;
}

bool Stack::bosMu()const
{
 	return sira == 0;
}

void Stack::push(const int veri)
{
	if(isEmpty)
	{
		isEmpty = false;
	}
	
	StackNode* temp = new StackNode(veri);

	if(head ==NULL)
	{
		head = temp;
	}

	temp ->sonraki  =  topOfStack;
	topOfStack = temp;
	last = topOfStack;
	length++;
	sira++;
	
}

void Stack::pop()
{	
	if(isEmpty) 
	{
		cout<< "Stack bos";
	}

	topOfStack = topOfStack->sonraki;
	length--;

	if(topOfStack == NULL){
		isEmpty = true;
	} 
}

void Stack::StackSil()
{
	StackNode* current = topOfStack;
	while (current != NULL)
	{
		StackNode* tmp = current;
		current = current->sonraki;	
		delete tmp;
	}
	topOfStack = NULL;
}

int Stack::top()const
{
	return topOfStack->veri;
}

void Stack::bosalt()
{
	while(!isEmpty) StackSil();
}

void Stack::sifirla()
{
	topOfStack = last;
	length = sira;
}

void Stack::yazdir(){
	StackNode* current = topOfStack;

	for (int i = 0; i < length; i++)
	{	
		if(current != nullptr) 
		{
			cout << current->veri <<endl;
		}
		else 
		{ 
			break;
		}
		current = current->sonraki;
	}
	
}

Stack::~Stack()
{
	StackSil();
}