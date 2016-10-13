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

int main() {
  songNode* list = NULL;
  char song[256] = "New York Cares";
  char artist[256] = "Interpol";
  list = insert_front(list, song, artist);
  print_list(list);
  return 0;
}
