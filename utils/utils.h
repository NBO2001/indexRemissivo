#ifndef UTILS_H
#define UTILS_H


char isLetter(char letter);
int lenStr(char string[]);
char * cleaningWord(char * word);
double tf(int wordOccurrences, int docWord);
double idf(int docsWords, int docs);
double tfidf(int palavra, int doc, int qntWords, int docs);

#endif