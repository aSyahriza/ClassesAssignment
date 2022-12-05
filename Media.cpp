#include "Media.h"

Media::Media(){
  title = new char[80];
  year = 0;
  id = 0;
}

Media::Media(char* pTitle, int pYear){
  title = new char[80];
  strcpy(title,pTitle);
  year = pYear;
  id = 0;
}

Media::~Media(){
  cout << "This media, titled '" << title << "'(" << year << ") has been deleted." << endl;
}

char* Media::getTitle(){
  return title;
}

int Media::getYear(){
  return year;
}
