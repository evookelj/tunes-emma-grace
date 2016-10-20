#ifndef MUSIC_LIB_H
#define MUSIC_LIB_H
#include "linkedList.h"

void insert( songNode* table[], char newName[], char newArtist[] );

void printList( songNode* table[] );

songNode* searchSong( songNode* table[], char name[] );

songNode* searchArtist( songNode* table[], char artist[] );

void deleteList( songNode* table[] ); 

void deleteSong( songNode* table[], char name[]);

void printArtist( songNode* table[], char artist[] );

void printAlpha( songNode* table[], char x);

songNode* findLetterList( songNode* table[], char a );

//print playlist in random order
void printShuffle( struct song_node* list );

#endif
