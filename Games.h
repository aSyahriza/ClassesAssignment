#ifndef Games_H
#define Games_H

#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;



class Games : public Media {
  public:
    Games();
    Games(char* pTitle, int pYear, char* pPublisher, char* pRating);
    char* getPublisher();
    char* getRating();
  protected:
    char* publisher;
    char* rating;
};

#endif