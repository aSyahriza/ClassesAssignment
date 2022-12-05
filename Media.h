#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <cstring>
using namespace std;



class Media {
  public:
    Media();
    Media(char* pTitle, int pYear);
    ~Media();
    char* getTitle();
    int getYear();
    int id;
  protected:
    char* title;
    int year;
};

#endif