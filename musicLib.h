#ifndef MUSIC_LIB_H
#define MUSIC_LIB_H
#include "linkedList.h"

//inserts new song node into music library (DONE)
void insert( songNode* table[], char newName[], char newArtist[] );

//prints music library (DONE)
void printList( songNode* table[] );

//(DONE)
void searchArtist( songNode* table[], char artist[] );

//Displays Artist if found (DONE)
void searchSong( songNode* table[], char name[] );

void deleteList( songNode* table[] ); 

void deleteSong( songNode* table[], char name[]);

//prints out all songs of artist (DONE)
void printArtist( songNode* table[], char artist[] );

//prints out all songs/artists under char x (DONE)
void printAlpha( songNode* table[], char x);

//(DONE)
songNode* findLetterList( songNode* table[], char a );

//print playlist in random order
void printShuffle( struct song_node* list );

#endif
