#ifndef LINKED_LIST_C
#define LINKED_LIST_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linkedList.h"

songNode* insert_front_list(songNode* list, char newName[], char newArtist[] ) {
  songNode* new = malloc(sizeof(songNode));
  strcpy(new->name,newName);
  strcpy(new->artist,newArtist);
  new->next = list;
  return new;
}

songNode* insert_order_list( songNode* list, char newName[], char newArtist[] ) {
  songNode* new = malloc(sizeof(songNode));
  strcpy(new->name,newName);
  strcpy(new->artist,newArtist);
  songNode* curr = list;
  new->next = NULL;

  if(curr->next == NULL) {
    if(strcmp(newArtist, curr->artist) < 0) {
      new->next = curr;
      return new;
    }
    curr->next = new;
    return list;
  }

  while(curr->next != NULL) {
    if(strcmp(newArtist, curr->next->artist) < 0) {
    new->next = curr->next;
    curr->next = new;
    return list;
    }
    curr = curr->next;
  }
  curr->next = new;
  return list;
}

void print_list(songNode* list) {
  songNode* p = list;
  if (list == NULL) {
    return;
  }
  while (p != NULL) {
    printf("Song: %s, Artist: %s\n",p->name,p->artist);
    p=p->next;
  }
}

songNode* search_song_list(songNode* list, char name[]) {
  songNode* p = list;
  while (p != NULL) {
    if (!(strcmp(p->name,name))) { return p; }
    p=p->next;
  }
  return NULL;
}

songNode* search_artist_list(songNode* list, char artist[]) {
  songNode* p = list;
  while (p != NULL) {
    if (!(strcmp(p->artist,artist))) { return p; }
    p=p->next;
  }
  return NULL;
}

void delete_song_list( songNode* list, char name[] ) {
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

songNode* delete_list( songNode* list ) {
  songNode* p = list;
  songNode* curr;
  while(p != NULL) {
    //printf("\nLIST IS NOT NULL");
    curr = p->next;
    free(p);
    p = curr;
  }
  return p;
}


void print_artist_list( songNode* list, char artist[] ){
  printf("\nSongs by %s:\n", artist);
  songNode* p = list;
  int i=0;
  while (p != NULL) {
    if (!(strcmp(p->artist,artist))) {
      printf("%s\n",p->name);
      return ;
    }
    p=p->next;
    i++;
  }
  printf("No songs found\n");
}

void print_alpha_list( struct song_node* list, char x ) {
  printf("\n%c songs:\n", x);
  songNode* p = list;
  while (p != NULL) {
    if ((p->name)[0] == x) { printf("%s\n", p->name); }
    p=p->next;
  }
}
/*
int main() {
  return 0;
}
*/
#endif
