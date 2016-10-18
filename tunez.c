#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tunez.h"

typedef struct song_node songNode;

songNode* insert_front_list(songNode* list, char newName[], char newArtist[] ) {
  songNode* new = malloc(sizeof(songNode));
  strcpy(new->name,newName);
  strcpy(new->artist,newArtist);
  new->next = list;
  return new;
}

void insertFront( songNode* table[], char newName[], char newArtist[] ) {
  songNode* findLL = findLetterList(table,newArtist[0]);
  findLL = insert_front_list( findLL, newName, newArtist );
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

void insertOrder( songNode* table[], char newName[], char newArtist[] ) {
  songNode* findLL = findLetterList(table,newArtist[0]);
  findLL = insert_order_list( findLL, newName, newArtist);
}

void print_list(songNode* list) {
  songNode* p = list;
  while (p != NULL) {
    printf("Song: %s, Artist: %s\n",p->name,p->artist);
    p=p->next;
  }
}

void printList( songNode* table[] ) {
  int i = 0;
  for (i=0; i<26; i++) {
    print_list(table[i]);
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

songNode* searchSong( songNode* table[], char name[] ) {
   int i;
   for (i=0; i<26; i++) {
     songNode* result = search_song_list(table[i],name);
     if (result != NULL) { return result; }
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

songNode* searchArtist( songNode* table[], char artist[] ) {
  return search_artist_list( findLetterList(table,artist[0]),artist);
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

songNode** deleteList( songNode* table[] ) {
   int i;
   for (i=0; i<26; i++) {
     delete_list(table[i]);
   }
   table = NULL;
   return table;
}

void print_artist_list( songNode* list, char artist[] ){
  printf("\nSongs by %s:\n", artist);
  songNode* p = list;
  while (p != NULL) {
    if (!(strcmp(p->artist,artist))) { printf("%s\n", p->name); }
    p=p->next;
  }
}

void printArtist( songNode* table[], char artist[] ) {
  print_artist_list( findLetterList(table,artist[0]),artist);
 }

void print_alpha_list( struct song_node* list, char x ) {
  printf("\n%c songs:\n", x);
  songNode* p = list;
  while (p != NULL) {
    if ((p->name)[0] == x) { printf("%s\n", p->name); }
    p=p->next;
  }
}

 void printAlpha( songNode* table[], char x) {
   print_alpha_list( findLetterList(table,x), x);
 } 

songNode* findLetterList( songNode* table[], char a ) {
  return table[(int)tolower(a) - 97];
}

int main() {
  songNode* *table = calloc(26,sizeof(songNode*));
  songNode* list = NULL;
  printf("TESTING ADD AND FIND:\n");
  insertFront(table, "New York Cares", "Interpol");
  print_list(findLetterList(table,'i'));
  printList(table);
  /*
  insertOrder(table, "Look At Me", "Buddy Holly");
  insertOrder(table, "Whole Lotta Love", "Led Zeppelin");
  insertOrder(table, "Mailman, Bring Me No More Blues", "Buddy Holly");
  table = insertOrder(table, "Yesterday", "The Beatles");
  table = insertOrder(table, "Black Bird", "The Beatles");
  table = insertOrder(table, "Let it be", "The Beatles");
  printList(table);
  printf("Looking for 'Buddy Holly': %s\n", searchArtist(table,"Buddy Holly")->name);
  printf("Looking for 'Whole Lotta Love': %s\n", searchSong(table, "Whole Lotta Love")->artist);
  printf("\nTESTING DELETE of 'Black Bird':\n");
  deleteSong(table,"Black Bird");
  printList(table);
  */
  deleteList(table);

  /*===================================
  printf("TESTING PRINT ARTIST");
  printArtist(list, "The Beatles");
  printf("TESTING PRINT ALPHA");
  printAlpha(list, 'L');

  printf("TESTING DELETE LIST:\n");
  list = deleteList(list);
  print_list(list);
    ====================================*/

  return 0;
}
