#ifndef TYPESTOPWORD_H
#define TYPESTOPWORD_H

typedef struct typeStopWord typeStopWord;

typeStopWord * newTypeStopWord(char * fileName);
short isStopWord(typeStopWord * stopWords, char * word);
void analiseDataStopWord(typeStopWord * stopWords);

#endif