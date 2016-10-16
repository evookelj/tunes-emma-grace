struct song_node{
  char name[256];
  char artist[256];
  struct song_node* next;
};

//print list (DONE)
void print_list(struct song_node *list);

//returns pointer to new front of list w given attributes (DONE)
struct song_node* insert_front( struct song_node* list, char name[], char artist[] );

//returns pointer to list w given song added at end (DONE)
struct song_node* insert_end( struct song_node* list, char name[], char artist[] );

//returns pointer to first occurence of song (DONE)
struct song_node* searchSong( struct song_node* list, char name[] );

//returns pointer to first occurence of artist (DONE)
struct song_node* searchArtist( struct song_node* list, char artist[] );

//return pointer to start of deleted list (DOESN'T WORK)
struct song_node* deleteList( struct song_node* list);

//delete given song name (DONE)
void deleteSong( struct song_node* list, char name[] );

//print playlist in random order
void printShuffle( struct song_node* list );

//print all songs of artist (DONE)
void printArtist( struct song_node* list, char artist[] );

//print all entries under certain letter (DONE)
void printAlpha( struct song_node* list, char x );
