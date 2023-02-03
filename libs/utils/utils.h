#ifndef UTILS_H
#define UTILS_H
#include "../../libs/analyticalData/analyticalData.h"

typedef struct fileG{
    char * title;
    char * outputName;
    short createNewFile;
    analyticalData data;
}fileG;

#define fileAnalyticalData(...) \
 _fileAnalyticalData((fileG){.createNewFile=1,.outputName="analise.md",.title="ANALISE DATA",__VA_ARGS__})

char isLetter(unsigned char letter);
int lenStr(unsigned char *string);
void cleaningWord(unsigned char * word);
double tf(int wordOccurrences, int docWord);
double idf(int docsWords, int docs);
double tfidf(int palavra, int doc, int qntWords, int docs);
void lowerCase(unsigned char string[]);
void _fileAnalyticalData(fileG in);
void removeSpecialCharacters(unsigned char * string);

#endif