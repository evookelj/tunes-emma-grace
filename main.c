#ifndef MAIN_C
#define MAIN_C

#include <stdio.h>
#include <stdlib.h>
#include "musicLib.h"
#include "linkedList.h"

int main() {
  songNode* *table = calloc(26,sizeof(songNode*));
  songNode* list = NULL;
  printf("TESTING ADD AND FIND:\n");

  //add is not adding correctly
  table = insertFront(table, "new york cares", "interpol");
  print_list(findLetterList(table,'i'));

  //THIS is causing seg fault
  //printList(table);

  /*
  insertOrder(table, "Look At Me", "Buddy Holly");
  insertOrder(table, "Mailman, Bring Me No More Blues", "Buddy Holly");
  printList(table);
  table =insertOrder(table, "Yesterday", "The Beatles");
  table = insertOrder(table, "Black Bird", "The Beatles");
  table = insertOrder(table, "Let it be", "The Beatles");
  printList(table);

  printf("Looking for 'Buddy Holly': %s\n", searchArtist(table,"Buddy Holly")->name);
  printf("Looking for 'Whole Lotta Love': %s\n", searchSong(table, "Whole Lotta Love")->artist);
  printf("\nTESTING DELETE of 'Black Bird':\n");
  deleteSong(table,"Black Bird");
  printList(table);
  deleteList(table);
  */

  /*===================================                                           printf("TESTING PRINT ARTIST");
  printArtist(list, "The Beatles");
  printf("TESTING PRINT ALPHA");
  printAlpha(list, 'L');
  printf("TESTING DELETE LIST:\n");
  list = deleteList(list);
  print_list(list);                                                               ====================================*/

return 0;
}

#endif
