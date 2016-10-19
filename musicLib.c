#ifndef MUSIC_LIB_C
#define MUSIC_LIB_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.c"
#include "musicLib.h"

void insertFront( songNode* table[], char newName[], char newArtist[] ) {
  songNode* findLL = findLetterList(table,newArtist[0]);
  findLL = insert_front_list( findLL, newName, newArtist );
}

void insertOrder( songNode* table[], char newName[], char newArtist[] ) {
  songNode* findLL = findLetterList(table,newArtist[0]);
  findLL = insert_order_list( findLL, newName, newArtist);
}

void printList( songNode* table[] ) {
  int i = 0;
  for (i=0; i<26; i++) {
    print_list(table[i]);
  }
}

songNode* searchSong( songNode* table[], char name[] ) {
  int i;
  for (i=0; i<26; i++) {
    songNode* result = search_song_list(table[i],name);
    if (result != NULL) { return result; }
  }
  return NULL;
}

songNode* searchArtist( songNode* table[], char artist[] ) {
  return search_artist_list( findLetterList(table,artist[0]),artist);
}

void deleteSong( songNode* table[], char name[]) {
  int i;
  for (i=0; i<26; i++) {
    songNode* result = search_song_list(table[i], name);
    if (result != NULL) {
      delete_song_list( table[i], name );
      return;
    }
  }
  return ;
}

songNode** deleteList( songNode* table[] ) {
  int i;
  for (i=0; i<26; i++) {
    delete_list(table[i]);
  }
  table = NULL;
  return table;
}

void printArtist( songNode* table[], char artist[] ) {
  print_artist_list( findLetterList(table,artist[0]),artist);
}

void printAlpha( songNode* table[], char x) {
  print_alpha_list( findLetterList(table,x), x);
}

songNode* findLetterList( songNode* table[], char a ) {
  return table[(int)tolower(a) - 97];
}

/*
int main() {
  return 0;
}
*/

#endif
