#ifndef T_PALAVRA
#define T_PALAVRA 

typedef struct tipoPalavra tipoPalavra;

//typedef void (*criar) (int);

tipoPalavra* criarPalavra();


void setRecurrence(tipoPalavra* p, int recorrencia);
int getRecurrence(tipoPalavra*p);

void setTupla(tipoPalavra*p, void* *tupla);
void* getTupla(tipoPalavra* p);



void setPalavra(tipoPalavra*p, char* palavra);
char* getPalavra(tipoPalavra* p);









#endif