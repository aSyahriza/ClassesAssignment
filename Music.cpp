#include "Music.h"

Music::Music(){
  artist = new char[80];
  publisher = new char[80];
  duration = 0;
  id = 3;
}

Music::Music(char* pTitle, int pYear, char* pArtist, char* pPublisher, int pDuration) : Media(pTitle, pYear){
 
  artist = new char[80];
  publisher = new char[80];
  id = 3;

  strcpy(artist,pArtist);
  strcpy(publisher,pPublisher);
  duration = pDuration;
}

char* Music::getArtist(){
  return artist;
}

char* Music:: getPublisher(){
  return publisher;
}

int Music::getDuration(){
  return duration;
}
