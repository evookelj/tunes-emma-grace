#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"

typedef struct song_node songNode;

songNode* insert_front( songNode* list, char newName[256], char newArtist[256]) {
  songNode* new = malloc(sizeof(songNode));
  strcpy(new->name,newName);
  strcpy(new->artist,newArtist);
  new->next = list;
  return new;
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

int main() {
  songNode* list = NULL;
  printf("TESTING ADD AND FIND:\n");
  list = insert_front(list, "New York Cares", "Interpol");
  list = insert_front(list, "Look At Me", "Buddy Holly");
  list = insert_front(list, "Whole Lotta Love", "Led Zeppelin");
  list = insert_front(list, "Mailman, Bring Me No More Blues", "Buddy Holly");
  print_list(list);
  printf("Looking for 'Buddy Holly': %s\n", searchArtist(list,"Buddy Holly")->name);
  printf("Looking for 'Whole Lotta Love': %s\n", searchSong(list, "Whole Lotta Love")->artist);
  printf("\nTESTING DELETE of 'Look At Me':\n");
  deleteSong(list,"Look At Me");
  print_list(list);
  return 0;
}
