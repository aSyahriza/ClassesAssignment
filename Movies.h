#ifndef MOVIES_H
#define MOVIES_H

#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;



class Movies : public Media {
  public:
    Movies();
    Movies(char* pTitle, int pYear, char* pDirector, char* pRating, int pDuration);
    char* getDirector();
    char* getRating();
    int getDuration();
protected:
    char* director;
    char* rating;
    int duration;
};

#endif