#ifndef MUSIC_LIB_C
#define MUSIC_LIB_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "musicLib.h"
#include "linkedList.h"

void insert( songNode* table[], char newName[], char newArtist[] ) {
  char let = newArtist[0];
  songNode* findLL = findLetterList(table,let);
  if (findLL == NULL) {
    //printf("INSERTING IN FRONT\n");
    findLL = insert_front_list( findLL, newName, newArtist );
  }
  else {
    findLL = insert_order_list( findLL, newName, newArtist );
  }
  table[(int)tolower(let) - 97] = findLL;
}

void printList( songNode* table[] ) {
  int i = 0;
  for (i=0; i<26; i++) {
    printf("%c:\n",toupper(i + 97));
    print_list(table[i]);
  }
}

songNode* searchSong( songNode* table[], char name[] ) {
  int i;
  songNode *result;
  for (i=0; i<26; i++) {
    result = search_song_list(table[i],name);
    if (result != NULL) { return result; }
  }
  return NULL;
}

songNode* searchArtist( songNode* table[], char artist[] ) {
  return search_artist_list(findLetterList(table,artist[0]),artist);
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

void deleteList( songNode* table[] ) {
  int i;
  for (i=0; i<26; i++) {
    delete_list(table[i]);
  }
}

void printArtist( songNode* table[], char artist[] ) {
  print_artist_list( findLetterList(table,artist[0]),artist);
}

void printAlpha( songNode* table[], char x) {
  print_alpha_list( findLetterList(table,x), x);
}

songNode* findLetterList( songNode* table[], char a ) {
  songNode *list = table[(int)tolower(a) - 97];
  return list;
}
/*
int main() {
  return 0;
}
*/
#endif
