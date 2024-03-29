#include "Image.h"
#include "Pixel.h"
#include<iostream>
#include<vector>
#include<stdlib.h>
#include <fstream>
#include<string>
#include<math.h>
#include<iostream>
using namespace std;
void Image::set_w(int a){
	w=a;
}
void Image::set_h(int a){
	h=a;
}
//change
Image::Image()
{
	h = 0;w = 0;
}
Image::Image(int a, int b){
	w=a;
	h=b;
	//cout<<"hi"<<endl;
	p=new Pixel*[h];
	int i,j;
	for(i=0;i<h;i++)
	{
		p[i] = new Pixel [w];
	}

	for(i=0;i<h;i++)
	{
		for(j=0;j<b;j++)
		{
			p[i][j] = Pixel(i,j);
		}
	}
//cout<<"made image"<<endl;

}
Image::~Image(){
	int i=0;
	for(i=0;i<h;i++)
	{
		delete [] p[i];
	}
}
Image::Image(const Image& i){
	w=i.get_w();
	h=i.get_h();
	p= i.get_p();
}
void Image::populate_pixels(ifstream& f){
	int i=0,j=0;
	for(i=0;i<(*this).h;i++)
	{
		for(j=0;j<(*this).w;j++)
		{
			int x,y,z;
			f>>x>>y>>z;
			p[i][j].set_colour(x,y,z);
		}
	}
}
void Image::apply_filter(float a, float b){
	int i=0,j=0;
	for(i=0;i<(*this).h;i++)
	{
		for(j=0;j<(*this).w;j++)
		{
			p[i][j].change_colour(a,b);
		}
	}
}
void Image::apply_filter(Colour * cf, float alpha){
	int i=0,j=0;
	for(i=0;i<(*this).h;i++)
	{
		for(j=0;j<(*this).w;j++)
		{
			p[i][j].change_colour(cf,alpha);
		}
	}
}
ostream & operator << (ostream &os, Image const &im){
	int i=0,j=0,k=0;
	for(i=0;i<im.get_h();i++){
		for(j=0;j<im.get_w();j++){
			os<<(im.get_p())[i][j];
			k++;
			if(k==7){
				os<<endl;
				k=0;
			}
		}
	}
	return os;
}
//Soumya's Code
std :: istream & operator>> (istream &is,Image const &l)
{
    int r,g,b;
    for(int j=0;j<l.get_h();j++)
    {
        for(int i=0;i<l.get_w();i++)
        {
            is >> r >> g >> b;
            Colour c(r,g,b);
            (l).get_p()[j][i].set_colour(c);
            }
    }
    return is;
}
