#ifndef UTILS_H
#define UTILS_H

char isLetter(unsigned char letter);
int lenStr(char string[]);
void cleaningWord(unsigned char * word);
double tf(int wordOccurrences, int docWord);
double idf(int docsWords, int docs);
double tfidf(int palavra, int doc, int qntWords, int docs);
const char * lowerCase(unsigned char string[]);


#endif