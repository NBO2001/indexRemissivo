#include "typeDocument.h"
#include <stdlib.h>

struct typeDocument{

    int numPage;
    long int startP;
    long int endP;
    long int lenWords;

};


typeDocument * tpDocument(){ return (typeDocument *) malloc(sizeof(typeDocument)); }

void setNumPage(typeDocument * document, int page){ document->numPage = page; }
int getNumPage(typeDocument * document){ return document->numPage; }

void setStartP(typeDocument * document, long int value){ document->startP = value; }
long int getStartP(typeDocument * document){ return document->startP; }

void setEndP(typeDocument * document, long int value){ document->endP = value; }
long int getEndP(typeDocument * document){ return document->endP; }

void setLenWords(typeDocument * document, long int value){ document->lenWords = value; }
long int getLenWords(typeDocument * document){ return document->lenWords; }
