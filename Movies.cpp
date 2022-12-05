#include "Movies.h"

Movies::Movies(){
  director = new char[80];
  rating = new char[80];
  duration = 0;
  id = 2;
}

Movies::Movies(char* pTitle, int pYear, char* pDirector, char* pRating, int pDuration) : Media(pTitle, pYear){

  director = new char[80];
  rating = new char[80];
  id = 2;

  strcpy(director,pDirector);
  strcpy(rating,pRating);
  duration = pDuration;
}

char* Movies::getDirector(){
  return director;
}

char* Movies:: getRating(){
  return rating;
}

int Movies::getDuration(){
  return duration;
}
