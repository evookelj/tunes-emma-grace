struct song_node{
  char name[256];
  char artist[256];
  struct song_node* next;
};

//print list (DONE)
void print_list(struct song_node *list);

//returns pointer to new front of list w given attributes (DONE)
struct song_node* insert_front( struct song_node* list, char name[], char artist[] );

//returns pointer to first occurence of song
struct song_node* searchSong( struct song_node* list, char name[] );

//returns pointer to first occurence of artist
struct song_node* searchArtist( struct song_node* list, char artist[] );

//return pointer to a random song
struct song_node* randomSong( struct song_node* list );

//return pointer to start of free'd list (DONE)
struct song_node* freeList( struct song_node* list);

//insert notes in order??

//remove single node from list??
