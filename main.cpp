/*
* 
* Author: Allam Syahriza  
* Date: 12/04/2022
* This programs creates a vector of media, which can be either a movie, album, or video game.
* The user can add media to this vector, including metadata for said media.
* The user can search through the vector by title or year 
* The user can delete media through a similar method
* 
*/


#include <iostream>
#include <cstring>
#include <vector>
#include "Movies.h"
#include "Games.h"
#include "Music.h"
using namespace std;

void add(vector<Media*>&vect);
void delet(vector<Media*> &vect);
void search(vector<Media*> &vect);




int main() {

  
  bool loop = true;
  // Creates vector which holds all media
  vector<Media*> vect;

  while(loop){
    
    char userInput[20];
    cout << "\n" << endl;
    cout << "What would you like to do? (ADD, DELETE, SEARCH, QUIT)" << endl;
    cin.get(userInput,20);
    cin.get();

    
    
    
    if(strcmp(userInput,"ADD")==0){ 
      add(vect);  
      
    }
    else if(strcmp(userInput,"DELETE")==0){
      delet(vect);
      
    }
    else if(strcmp(userInput,"SEARCH")==0){
      
      search(vect);
      
      
    }
    else if(strcmp(userInput,"QUIT")==0){
      // Ends loop and ends program
      loop = false;
    }
  }
  cout << "Program ended." << endl;
  return 0;
}


void add(vector<Media*> &vect){  // Add function, adds media to vector
  char addUserInput[80];
  char* mediaTitle = new char[80];
  int mediaYear;


  // Asks the user for data which all media types contain
  
  cout << "What type of media would you like to add? (GAMES, MUSIC, MOVIES)" << endl;
  cin.get(addUserInput,80);
  cin.get();

  cout << "Enter title of media:" << endl;
  cin.get(mediaTitle,80);
  cin.get();

  cout << "Enter year of media:" << endl;
  cin >> mediaYear;
  cin.ignore();

  // Asks user for data specific to the type of media they entered in
  if(strcmp(addUserInput,"GAMES")==0){
    char* gamePublisher = new char[80];
    char* gameRating = new char[20];

    cout << "Enter the publisher of the game: " << endl;
    cin.get(gamePublisher,80);
    cin.get();

    cout << "Enter the rating of the game: " << endl;
    cin.get(gameRating,20);
    cin.get();

    // Adds game to vector
    vect.push_back(new Games(mediaTitle,mediaYear, gamePublisher, gameRating));

    cout << "Game Added!" << endl;
  }
  else if(strcmp(addUserInput,"MUSIC")==0){
    char* musicArtist = new char[80];
    char* musicPublisher = new char[80];
    int musicDuration;

    cout << "Enter the artist of the album: " << endl;
    cin.get(musicArtist,80);
    cin.get();

    cout << "Enter the publisher of the album: " << endl;
    cin.get(musicPublisher,80);
    cin.get();

    cout << "Enter the duration for the album (in minutes): " << endl;
    cin >> musicDuration;
    cin.ignore();

    // Adds music to vector
    vect.push_back(new Music(mediaTitle,mediaYear, musicArtist, musicPublisher, musicDuration));

    cout << "Music Added!" << endl;
  }
    
  else if(strcmp(addUserInput,"MOVIES")==0){
    char* movieDirector = new char[80];
    char* movieRating = new char[20];
    int movieDuration;

    cout << "Enter the director of the movie: " << endl;
    cin.get(movieDirector,80);
    cin.get();

    cout << "Enter the rating of the movie: " << endl;
    cin.get(movieRating,20);
    cin.get();

    cout << "Enter the duration for the movie (in minutes): " << endl;
    cin >> movieDuration;
    cin.ignore();

    // Adds movie to vector
    vect.push_back(new Movies(mediaTitle,mediaYear, movieDirector, movieRating, movieDuration));
    cout << "Movie Added!" << endl;
  } 
} 




void delet(vector<Media*> &vect){ // Delete function, either by title or year
  vector<Media*>::iterator i;
  bool found = false;
  char userInput[80];
  cout << "Delete by TITLE or YEAR?" << endl;
  cin.get(userInput,80);
  cin.get();

  cout << "Search for media to delete: " << endl;
  
  if(strcmp(userInput,"TITLE") == 0){
    char userSearch[80];
    cin.get(userSearch,80);
    cin.get();
    int erased = 0;
    for(std::vector<Media*>::iterator i=vect.begin(); i!=vect.end(); i++){
      Media* m = *i;
      // Goes through every object in vector to see if their title matches the title specified by user
      if(strcmp(m->getTitle(),userSearch)==0){
        if(found == false){
          cout << "\n" << "Media found!" << endl << endl;
          found = true;
        }
        // Prints out data of media
        cout << "Title: " << m->getTitle() << endl;
        cout << "Year: " << m->getYear() << endl;
        if(m->id == 1){
          cout << "Publisher: " << ((Games*)m)->getPublisher() << endl;
          cout << "Rating: " << ((Games*)m)->getRating() << endl;
        }
        else if(m->id == 2){
          cout << "Director: " << ((Movies*)m)->getDirector() << endl;
          cout << "Rating: " << ((Movies*)m)->getRating() << endl;
          cout << "Duration: " << ((Movies*)m)->getDuration() << endl;
        }
        else if(m->id == 3){
          cout << "Artist: " << ((Music*)m)->getArtist() << endl;
          cout << "Publisher: " << ((Music*)m)->getPublisher() << endl;
          cout << "Duration: " << ((Music*)m)->getDuration() << endl;
        }
        // Asks user to confirm deletion of media
        char confirmDelete[20];
        cout << "Delete this media? (Y or N)" << endl;
        cin.get(confirmDelete,20);
        cin.get();
        if(strcmp(confirmDelete,"Y")==0){
          // Removes object from vector, deletes object
          vect.erase(i);
          delete m;
        }
        else{
          cout << "Media not deleted." << endl;
        }
      }
      cout << "\n";
    }
    if(found == false){
      cout << "No media found!" << endl;
    }
  }

  
  if(strcmp(userInput,"YEAR") == 0){ // Same functionality, with user specifying  year instead of title
    int userSearch;
    cin >> userSearch;
    cin.ignore();
    for(std::vector<Media*>::iterator i=vect.begin(); i!=vect.end(); i++){
      Media* m = *i;
      if(m->getYear() == userSearch){
        if(found == false){
          cout << "\n" << "Media found!" << endl << endl;
          found = true;
        }
        cout << "Title: " << m->getTitle() << endl;
        cout << "Year: " << m->getYear() << endl;
        if(m->id == 1){
          cout << "Publisher: " << ((Games*)m)->getPublisher() << endl;
          cout << "Rating: " << ((Games*)m)->getRating() << endl;
        }
        else if(m->id == 2){
          cout << "Director: " << ((Movies*)m)->getDirector() << endl;
          cout << "Rating: " << ((Movies*)m)->getRating() << endl;
          cout << "Duration: " << ((Movies*)m)->getDuration() << endl;
        }
        else if(m->id == 3){
          cout << "Artist: " << ((Music*)m)->getArtist() << endl;
          cout << "Publisher: " << ((Music*)m)->getPublisher() << endl;
          cout << "Duration: " << ((Music*)m)->getDuration() << endl;
        }
        char confirmDelete[20];
        cout << "Delete this media? (Y or N)" << endl;
        cin.get(confirmDelete,20);
        cin.get();
        if(strcmp(confirmDelete,"Y")==0){
          vect.erase(i);
          delete m;
        }
        else{
          cout << "Media not deleted." << endl;
        }
      }
      cout << "\n"; 
      
    }
    
    if(found == false){
      cout << "No media found!" << endl;
    }
  }
}


void search(vector<Media*> &vect){ // Search function, either by title or year
  vector<Media*>::iterator i;
  bool found = false;
  char userInput[80];
  cout << "Search by TITLE or YEAR?" << endl;
  cin.get(userInput,80);
  cin.get();

  cout << "Search for media: " << endl;
  
  if(strcmp(userInput,"TITLE") == 0){
    char userSearch[80];
    cin.get(userSearch,80);
    cin.get();
    // Goes through every element in vector, seeing if the medias title matches the users specified title
    for(std::vector<Media*>::iterator i=vect.begin(); i!=vect.end(); i++){
      Media* m = *i;
      if(strcmp(m->getTitle(),userSearch)==0){
        if(found == false){
          cout << "\n" << "Media found! " << endl << endl;
          found = true;
        }
        // Prints data of media
        cout << "Title: " << m->getTitle() << endl;
        cout << "Year: " << m->getYear() << endl;
        if(m->id == 1){
          cout << "Publisher: " << ((Games*)m)->getPublisher() << endl;
          cout << "Rating: " << ((Games*)m)->getRating() << endl;
        }
        else if(m->id == 2){
          cout << "Director: " << ((Movies*)m)->getDirector() << endl;
          cout << "Rating: " << ((Movies*)m)->getRating() << endl;
          cout << "Duration: " << ((Movies*)m)->getDuration() << endl;
        }
        else if(m->id == 3){
          cout << "Artist: " << ((Music*)m)->getArtist() << endl;
          cout << "Publisher: " << ((Music*)m)->getPublisher() << endl;
          cout << "Duration: " << ((Music*)m)->getDuration() << endl;
        }
      }
      cout << "\n";
    }
    if(found == false){
      cout << "No media found!" << endl;
    }
  }

  
  if(strcmp(userInput,"YEAR") == 0){ // Same functionality, with user specifying  year instead of title
    int userSearch;
    cin >> userSearch;
    cin.ignore();
    for(std::vector<Media*>::iterator i=vect.begin(); i!=vect.end(); i++){
      Media* m = *i;
      if(m->getYear() == userSearch){
        if(found == false){
          cout << "\n" << "Media found! " << endl << endl;
          found = true;
        }
        cout << "Title: " << m->getTitle() << endl;
        cout << "Year: " << m->getYear() << endl;
        if(m->id == 1){
          cout << "Publisher: " << ((Games*)m)->getPublisher() << endl;
          cout << "Rating: " << ((Games*)m)->getRating() << endl;
        }
        else if(m->id == 2){
          cout << "Director: " << ((Movies*)m)->getDirector() << endl;
          cout << "Rating: " << ((Movies*)m)->getRating() << endl;
          cout << "Duration: " << ((Movies*)m)->getDuration() << endl;
        }
        else if(m->id == 3){
          cout << "Artist: " << ((Music*)m)->getArtist() << endl;
          cout << "Publisher: " << ((Music*)m)->getPublisher() << endl;
          cout << "Duration: " << ((Music*)m)->getDuration() << endl;
        }
      }
      cout << "\n";
    }
    if(found == false){
      cout << "No media found!" << endl;
    }
  }
}