#ifndef Music_H
#define Music_H

#include <iostream>
#include <cstring>
#include "Media.h"
using namespace std;



class Music : public Media {
  public:
    Music();
    Music(char* pTitle, int pYear, char* pArtist, char* pPublisher, int pDuration);
    char* getArtist();
    char* getPublisher();
    int getDuration();
  protected:
    char* artist;
    char* publisher;
    int duration;
};

#endif