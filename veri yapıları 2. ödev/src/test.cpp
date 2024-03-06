#include "fstream"
#include "yigit.hpp"
#include "iostream"
#include <cstdlib>
#include "linkedList.hpp"
#include "avl.hpp"


using namespace std;


int main(){
    LinkedList linkedList;
    AVL* tree =new AVL(); 
    char ch;
    string sayi;
    fstream input_file("Veri.txt",fstream::in);

    while (input_file.get(ch)) {
       
        if (ch == '\n'){
            tree->Ekle(stoi(sayi));
            sayi.clear();
            linkedList.Add(tree);
            delete tree;
            tree = new AVL();
        }
        else if (ch == ' '){
            tree->Ekle(stoi(sayi));
            
            sayi.clear();

        }
        else if(ch != ' ')
        {
            sayi += ch;
        }
   
    }

    tree->Ekle(stoi(sayi));
    linkedList.Add(tree);
    input_file.close();  
    
    ListNode* current = linkedList.head;
    while (current != nullptr)
    {
        current->data.stackEkle(current->data.kok);
        current = current->sonraki;
    }

    current = linkedList.head;
    linkedList.stackKontol();
    

    delete tree;
    return 0;
}