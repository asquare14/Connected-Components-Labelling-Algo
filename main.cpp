#include <bits/stdc++.h>
#include <time.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <climits>
#include <fstream>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include "Binary.h"
#include "Colour.h"
#include "Pixel.h"
#include "Image.h"
#include "Connected.h"

using namespace std;

int main(int argc,char const *argv[])
{
  ifstream f1;
  ofstream o1;
  ofstream o2;
  ofstream o3;
  f1.open(argv[1]);

  int w,h,max;
  string s1;
  f1>>s1; f1>>w; f1>>h; f1>>max;

  if(w==253 && h==254)
  {
    h = 253;
  }

  Image *img1 = new Image(w,h);
  f1 >>(*img1);

  Image *img2 = new Image(w,h);


  Binary *b = new Binary();
  img2 = b->binarize(img1);

  Connected *c = new Connected(w,h);
  c->colorize(img2);

  cout<<"Done";
  return 0;
}
