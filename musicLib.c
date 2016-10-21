#ifndef MUSIC_LIB_C
#define MUSIC_LIB_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
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
    if (table[i] != NULL) { 
      printf("%c:\n",toupper(i + 97));
      print_list(table[i]);
    }
  }
}

void searchSong( songNode* table[], char name[] ) {
  int i;
  songNode *result;
  for (i=0; i<26; i++) {
    //printf("i: %d\n", i);
    result = search_song_list(table[i],name);
    if (result != NULL) {
      printf("Artist of %s: %s\n",name,result->artist);
      return ;
    }
  }
  //printf("EXIT FOR LOOP\n");
  printf("song not found\n");
}

void searchArtist( songNode* table[], char artist[] ) {
  songNode* result =  search_artist_list(findLetterList(table,artist[0]),artist);
  if (result != NULL) { 
    printf("First occurence of %s: %s",artist, result->name); 
    return ;
  }
  printf("artist not found\n");
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

void shuffleLib( songNode* table[] ) {
  srand(time(NULL));
  int count = 0;
  int i;
  //get count of all songs
  for (i=0; i<26; i++) {
    songNode* curr = table[i];
    while (curr != NULL) {
      count++;
      curr = curr->next;
    }
  }

  //add items of table to tunez
  songNode* tunez[count];
  int count2 = 0;
  for (i=0; i<26;i++) {
    songNode* curr = table[i];
    while (curr != NULL) {
      tunez[count2] = curr;
      count2++;
      curr = curr->next;
    }
  }

  //randomize tunez via swap
  for (i=0; i<count; i++) {
    int r = rand() % count;
    songNode* curr = tunez[i];
    tunez[i] = tunez[r];
    tunez[r] = curr;
  }

  printf("SHUFFLED PLAYLIST:\n");
  for (i=0; i<count; i++) {
    printf("Song: %s, Artist: %s\n",tunez[i]->name,tunez[i]->artist);
  }
}

#endif
