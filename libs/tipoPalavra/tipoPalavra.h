#ifndef T_PALAVRA
#define T_PALAVRA 

typedef struct tipoPalavra tipoPalavra;
typedef struct typePage typePage;

tipoPalavra* criarPalavra();

void setPage(tipoPalavra*p, void* documentPage, unsigned int * totDocs);


void* getDocument(tipoPalavra* p, int index);

unsigned long int getRecorreces(tipoPalavra* p, int index);

void setPontuation(tipoPalavra* p, int index, double pontuation);
double getPontuation(tipoPalavra* p, int index);

int getLenPages(tipoPalavra* p);

void setPalavra(tipoPalavra*p, char* palavra);
char* getPalavra(tipoPalavra* p);

unsigned int * getDocTot(tipoPalavra* p, int index);

void sortingPages(tipoPalavra* p);

unsigned int sizeTypePage();

#endif