#ifndef MUSIC_LIB_H
#define MUSIC_LIB_H
#include "linkedList.h"

//inserts new song node into music library
void insert( songNode* table[], char newName[], char newArtist[] );

//prints music library
void printList( songNode* table[] );

songNode* searchArtist( songNode* table[], char artist[] );

//return pointer to song with name if it exists(if not, it returns NULL)
songNode* searchSong( songNode* table[], char name[] );

void deleteList( songNode* table[] ); 

void deleteSong( songNode* table[], char name[]);

//prints out all songs of artist
void printArtist( songNode* table[], char artist[] );

void printAlpha( songNode* table[], char x);

songNode* findLetterList( songNode* table[], char a );

//print playlist in random order
void printShuffle( struct song_node* list );

#endif
