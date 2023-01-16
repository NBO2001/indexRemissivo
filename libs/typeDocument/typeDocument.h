#ifndef TYPEDOCUMENT_H
#define TYPEDOCUMENT_H

typedef struct typeDocument typeDocument;

typeDocument * tpDocument();

void setNumPage(typeDocument * document, int page);
int getNumPage(typeDocument * document);

void setStartP(typeDocument * document, long int value);
long int getStartP(typeDocument * document);

void setEndP(typeDocument * document, long int value);
long int getEndP(typeDocument * document);

void setLenWords(typeDocument * document, long int value);
long int getLenWords(typeDocument * document);



#endif