#ifndef MUSIC_LIB_H
#define MUSIC_LIB_H
#include "linkedList.h"

//inserts new song node into music library (DONE)
void insert( songNode* table[], char newName[], char newArtist[] );

//prints music library (DONE)
void printList( songNode* table[] );

//print first occurance of artist if found(DONE)
void searchArtist( songNode* table[], char artist[] );

//displays Artist if found (DONE)
void searchSong( songNode* table[], char name[] );

//frees list(DONE)
void deleteList( songNode* table[] ); 

//frees song(DONE)
void deleteSong( songNode* table[], char name[]);

//prints out all songs of artist (DONE)
void printArtist( songNode* table[], char artist[] );

//prints out all songs/artists under char x (DONE)
void printAlpha( songNode* table[], char x);

//returns correct list associated with char a in table(DONE)
songNode* findLetterList( songNode* table[], char a );

//print playlist in random order(DONE)
void shuffleLib( songNode* table[] );

#endif
