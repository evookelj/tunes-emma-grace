#ifndef MUSIC_LIB_H
#define MUSIC_LIB_H
#include "linkedList.h"

//struct song_node* insertFront( struct song_node* table[], char newName[], char newArtist[] );

//struct song_node* insertOrder( struct song_node* table[], char newName[], char newArtist[] );

//struct song_node* searchSong( struct song_node* table[], char name[] ); 

//struct song_node* searchArtist( struct song_node* table[], char artist[] ); 

//struct song_node** deleteList( struct song_node* table[] ); 

//print playlist in random order

//void printShuffle( struct song_node* list );

//void printArtist( struct song_node* table[], char artist[] );

struct song_node* findLetterList( struct song_node* table[], char a );

//void printAlpha( struct song_node* table[], char x);

struct song_node* findLetterList(struct song_node* table[], char a );

#endif
