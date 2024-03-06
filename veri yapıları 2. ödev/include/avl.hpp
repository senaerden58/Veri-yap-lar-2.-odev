/** 
* @file linkedlist.hpp
* @description Avl ağaçları ve özelliklerini barındırır.Kurallara göre dönme,posterder yazım ve diğer gereklı fonksiyonlar vardır.
* @course 1. Öğretim A grubu
* @assignment 2. ödev
* @date 24.12.2024
* @author Sena Erden sena.erden@ogr.sakarya.edu.tr
*/
#ifndef AVL_HPP
#define AVL_HPP
#include  "yigit.hpp"

struct Dugum{
    public:
        int data;
        Dugum *sol;
        Dugum *sag;
        int yukseklik;
        Dugum(int deger);
};

class AVL {
    public:
        Stack stack;
        Dugum *kok;
        void yazdir();
        Dugum* EklemeYap(Dugum *aktifDugum, int item);
        void stackEkle(Dugum* aktifDugum);
        Dugum* solaDondur(Dugum *aktifDugum);
        Dugum* sagaDondur(Dugum *aktifDugum);
        bool dugumSil(Dugum *aktifDugum);
        void postorder(Dugum *aktifDugum);
        int yukseklik_olc(Dugum *aktifDugum);
        int yukseklik();
        bool ara(Dugum *aktifDugum,const int item);
        bool bosMu();
        void Temizle();
        void Ekle(int item);
        bool sayac=false;
        void asciiHesap(int toplam);
        int toplam=0;
        void topla(Dugum* aktifDugum); 
        AVL();
        ~AVL();
};

#endif