#ifndef LINKED_LIST_H
#define LINKED_LIST_H

struct song_node{
  char name[256];
  char artist[256];
  struct song_node* next;
};

typedef struct song_node songNode;

//print list (DONE)
void print_list(songNode *list);

//returns pointer to new front of list w given attributes (DONE)
songNode *insert_front( songNode* list, char name[], char artist[] );

//returns pointer to front of list w ndoe inserted in order (DONE)
songNode* insert_order( struct songNode* list, char name[], char artist[] );

//returns pointer to first occurence of song (DONE)
songNode* search_song_list( songNode* list, char name[] );

//returns pointer to first occurence of artist (DONE)
songNode* search_artist_list( songNode* list, char artist[] );

//return pointer to start of deleted list (DONE)
songNode* delete_list( songNode* list);

//delete given song name (DONE)
void delete_song_list( songNode* list, char name[] );

//print all songs of artist (DONE)
void print_artist_list( songNode* list, char artist[] );

//print all entries under certain letter (DONE)
void print_alpha_list( songNode* list, char x );


#endif
