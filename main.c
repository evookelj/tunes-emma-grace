#ifndef MAIN_C
#define MAIN_C

#include <stdio.h>
#include <stdlib.h>
#include "musicLib.h"
#include "linkedList.h"

int main() {

  songNode *table[26];
  int i;
  for(i = 0; i < 26; i++) {
    table[i] = NULL;
  }

  printf("TESTING ADD AND FIND:\n");
  insert(table, "New york cares", "Interpol");
  insert(table, "Look At Me", "Buddy Holly");
  insert(table, "Mailman, Bring Me No More Blues", "Buddy Holly");
  insert(table, "Yesterday", "The Beatles");
  insert(table, "Black Bird", "The Beatles");
  insert(table, "Let it be", "The Beatles");
  printList(table);
  printf("Looking for 'Buddy Holly': %s\n", searchArtist(table, "Buddy Holly")->name);
  printArtist(table,"Buddy Holly");
  /*
  printArtist(table,"Simon and Garfunkel");
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
