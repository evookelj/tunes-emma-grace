#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"

typedef struct song_node songNode;

songNode* insert_front( songNode* list, char newName[256], char newArtist[256] ) {
  songNode* new = malloc(sizeof(songNode));
  strcpy(new->name,newName);
  strcpy(new->artist,newArtist);
  new->next = list;
  return new;
}

songNode* insert_end( songNode* list, char newName[256], char newArtist[256] ) {
  songNode* new = malloc(sizeof(songNode));
  strcpy(new->name,newName);
  strcpy(new->artist,newArtist);
  songNode* curr = list;
  while(curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new;
  return list;
}

void print_list(songNode* list) {
  songNode* p = list;
  while (p != NULL) {
    printf("Song: %s, Artist: %s\n",p->name,p->artist);
    p=p->next;
  }
  printf("\n");
}

songNode* searchSong(songNode* list, char name[]) {
  songNode* p = list;
  while (p != NULL) {
    if (!(strcmp(p->name,name))) { return p; }
    p=p->next;
  }
  return NULL;
}

songNode* searchArtist(songNode* list, char artist[]) {
  songNode* p = list;
  while (p != NULL) {
    if (!(strcmp(p->artist,artist))) { return p; }
    p=p->next;
  }
  return NULL;
}

void deleteSong( songNode* list, char name[] ) {
  songNode* p = list;
  while (p->next != NULL) {
    if (!(strcmp(p->next->name,name))) {
      songNode* del = p->next;
      p->next = (p->next)->next;
      free(del);
      return;
    }
    p=p->next;
  }
}

//THIS IS NOT WORKING YET AND IDK WHY
//free(<songNode) is only freeing the song part of the struct
songNode* deleteList( songNode* list ) {
  songNode* p = list;
  songNode* curr;
  while(p != NULL) {
    //printf("\nLIST IS NOT NULL");
    curr = p->next;
    free(p);
    p = curr;
  }
  return list;
}

void printArtist( songNode* list, char artist[] ){
  printf("\nSongs by %s:\n", artist);
  songNode* p = list;
  while (p != NULL) {
    if (!(strcmp(p->artist,artist))) { printf("%s\n", p->name); }
    p=p->next;
  }
}

int main() {

  songNode* list = NULL;
  printf("TESTING ADD AND FIND:\n");
  list = insert_front(list, "New York Cares", "Interpol");
  list = insert_front(list, "Look At Me", "Buddy Holly");
  list = insert_front(list, "Whole Lotta Love", "Led Zeppelin");
  list = insert_front(list, "Mailman, Bring Me No More Blues", "Buddy Holly");
  list = insert_end(list, "Yesterday", "The Beatles");
  list = insert_end(list, "Black Bird", "The Beatles");
  list = insert_end(list, "Let it be", "The Beatles");
  print_list(list);
  printf("Looking for 'Buddy Holly': %s\n", searchArtist(list,"Buddy Holly")->name);
  printf("Looking for 'Whole Lotta Love': %s\n", searchSong(list, "Whole Lotta Love")->artist);
  printf("\nTESTING DELETE of 'Look At Me':\n");
  deleteSong(list,"Look At Me");
  print_list(list);
  /*===================================
  printf("TESTING DELETE LIST:\n");
  deleteList(list);
  print_list(list);
    ====================================*/
  printf("TESTING PRINT ARTIST");
  printArtist(list, "The Beatles");
  return 0;
}
