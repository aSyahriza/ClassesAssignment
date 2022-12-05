#include "Games.h"

Games::Games(){
  publisher = new char[80];
  rating = new char[80];
  id = 1;
}

Games::Games(char* pTitle, int pYear, char* pPublisher, char* pRating) : Media(pTitle, pYear){
  publisher = new char[80];
  rating = new char[80];
  id = 1;

  strcpy(publisher,pPublisher);
  strcpy(rating,pRating);

}

char* Games::getPublisher(){
  return publisher;
}

char* Games:: getRating(){
  return rating;
}


