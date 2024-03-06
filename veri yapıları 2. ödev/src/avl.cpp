#include "iostream"
#include "avl.hpp"
#include "yigit.hpp"

using namespace std;


Dugum::Dugum(int deger)
{
	sol = NULL;
	data = deger;
	sag = NULL;
	yukseklik =0;
}


Dugum* AVL::EklemeYap(Dugum *aktifDugum, int data)
{
	if(aktifDugum == NULL) 
	{
		aktifDugum = new Dugum(data);
	
	}
	else if(data < aktifDugum->data)
	{
		aktifDugum->sol = EklemeYap(aktifDugum->sol,data);
	
		if(yukseklik_olc(aktifDugum->sol) == yukseklik_olc(aktifDugum->sag)+2)
		{
			if(data < aktifDugum->sol->data)
				aktifDugum = solaDondur(aktifDugum);
			else{
				aktifDugum->sol = sagaDondur(aktifDugum->sol);
				aktifDugum = solaDondur(aktifDugum);
			}
		}
	}
	else if(data > aktifDugum->data){

		aktifDugum->sag = EklemeYap(aktifDugum->sag,data);
		if(yukseklik_olc(aktifDugum->sag) == yukseklik_olc(aktifDugum->sol)+2){
			if(data > aktifDugum->sag->data)
				aktifDugum = sagaDondur(aktifDugum);
			else{
				aktifDugum->sag = solaDondur(aktifDugum->sag);
				aktifDugum = sagaDondur(aktifDugum);
			}
		}
	}
	
	aktifDugum->yukseklik = yukseklik_olc(aktifDugum);
	return aktifDugum;
} 

void AVL::Ekle(int data){
	if(!ara(kok,data))
	{
		kok = EklemeYap(kok,data);
	}
}

AVL::AVL()
{
	kok = NULL;
	Stack stack;
}

AVL::~AVL(){
	// Temizle();
}

Dugum* AVL::solaDondur(Dugum *aktifDugum){
	Dugum *gecici = aktifDugum->sol;
	aktifDugum->sol = gecici->sag;
	gecici->sag = aktifDugum;
	
	aktifDugum->yukseklik = yukseklik_olc(aktifDugum);
	gecici->yukseklik = 1+max(yukseklik_olc(gecici->sol),aktifDugum->yukseklik);
	return gecici;
}

Dugum* AVL::sagaDondur(Dugum *aktifDugum){
	Dugum *gecici = aktifDugum->sag;
	aktifDugum->sag = gecici->sol;
	gecici->sol = aktifDugum;
	
	aktifDugum->yukseklik = yukseklik_olc(aktifDugum);
	gecici->yukseklik = 1+max(yukseklik_olc(gecici->sag),aktifDugum->yukseklik);
	
	return gecici;
}

void AVL::postorder(Dugum *aktifDugum){
	if(aktifDugum != NULL){
		postorder(aktifDugum->sol);
		postorder(aktifDugum->sag);
		cout<<aktifDugum->data<<" ";
	}
	
}

void AVL::stackEkle(Dugum* aktifDugum){
	if(aktifDugum != NULL)
	{
		stackEkle(aktifDugum->sol);
		stackEkle(aktifDugum->sag);
		if (aktifDugum->yukseklik == 0)
		{
			stack.push(aktifDugum->data);
		}
	}
}

void AVL::topla(Dugum* aktifDugum){
	if(aktifDugum != NULL)
	{
		topla(aktifDugum->sol);
		topla(aktifDugum->sag);
		if(aktifDugum->yukseklik != 0)
		{
			toplam+=aktifDugum->data;
		}
	}
}

void AVL::asciiHesap(int toplam)
{
    int ascii = toplam % (90 - 65 + 1) + 65;
	cout << char(ascii);
}

void AVL::yazdir(){
	topla(kok);
	asciiHesap(toplam);
}

bool AVL::dugumSil(Dugum *aktifDugum){
	Dugum *silinecek = aktifDugum;
	
	if(aktifDugum->sag == NULL)
	{
		 aktifDugum = aktifDugum->sol;
	}

	else if(aktifDugum->sol == NULL) 
	{
		aktifDugum = aktifDugum->sag;
	}

	else
	{
		silinecek = aktifDugum->sol;
		Dugum *ebeveyn = aktifDugum;
		while(silinecek->sag != NULL)
		{
			ebeveyn = silinecek;
			silinecek = silinecek->sag;
		}
		aktifDugum->data = silinecek->data;
		if(ebeveyn == aktifDugum) aktifDugum->sol = silinecek->sol;
		else ebeveyn->sag = silinecek->sol;
	}
	
	delete silinecek;
	
	return true;
}

int AVL::yukseklik_olc(Dugum *aktifDugum){
	if(aktifDugum == NULL)
	{
		return -1;
	}
	return 1+max(yukseklik_olc(aktifDugum->sol),yukseklik_olc(aktifDugum->sag));
}

int AVL:: yukseklik(){
	return yukseklik_olc(kok);
}


bool AVL::ara(Dugum *aktifDugum,const int data){
	if(aktifDugum == NULL)
	{
		return false;
	} 
	if(aktifDugum->data == data) 
	{
		return true;
	}
	if(data < aktifDugum->data) 
	{
		return ara(aktifDugum->sol,data);
	}
	else 
	{
		return ara(aktifDugum->sag,data);
	}
}


bool  AVL::bosMu(){
	return kok == NULL;
}


void AVL::Temizle(){
	while(!bosMu()) 
	{
		dugumSil(kok);
	}
}

