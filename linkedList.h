struct song_node{
  char name[256];
  char artist[256];
  struct song_node* next;
};

//print list (DONE)
void print_list(struct song_node *list);

//returns pointer to new front of list w given attributes (DONE)
struct song_node* insert_front( struct song_node* list, char name[], char artist[] );

//struct song_node* insertFront( struct song_node* table[], char newName[], char newArtist[] );

//returns pointer to front of list w ndoe inserted in order (DONE)
struct song_node* insert_order( struct song_node* list, char name[], char artist[] );

//struct song_node* insertOrder( struct song_node* table[], char newName[], char newArtist[] );

//returns pointer to first occurence of song (DONE)
struct song_node* search_song_list( struct song_node* list, char name[] );

//struct song_node* searchSong( struct song_node* table[], char name[] );

//returns pointer to first occurence of artist (DONE)
struct song_node* search_artist_list( struct song_node* list, char artist[] );

//struct song_node* searchArtist( struct song_node* table[], char artist[] );

//return pointer to start of deleted list (DONE)
struct song_node* delete_list( struct song_node* list);

//struct song_node** deleteList( struct song_node* table[] );

//delete given song name (DONE)
//void deleteSong( struct song_node* list, char name[] );

//print playlist in random order
//void printShuffle( struct song_node* list );

//print all songs of artist (DONE)
void print_artist_list( struct song_node* list, char artist[] );

//void printArtist( struct song_node* table[], char artist[] );

//print all entries under certain letter (DONE)
void print_alpha_list( struct song_node* list, char x );

//void printAlpha( struct song_node* table[], char x);

struct song_node* findLetterList( struct song_node* table[], char a );
