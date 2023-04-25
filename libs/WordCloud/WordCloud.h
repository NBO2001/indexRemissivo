#ifndef __WORDCLOUD_H
#define __WORDCLOUD_H

typedef struct WordCloud WordCloud;




void insertWordInQueue(WordCloud* wordCloud, char* word, double pontuation);

WordCloud* wordCloudCreate();

void fileCreate(WordCloud* wordCloud, int maxWords, char* fileNameOutput);

#endif