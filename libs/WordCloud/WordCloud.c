#include "WordCloud.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue Queue;

typedef struct Node Node;

typedef struct ElementWord ElementWord;

struct ElementWord{

    char* word;
    double pontuation;

};

struct Queue {
    Node* fist;
    Node* end;
};

struct Node{
    ElementWord* element;
    Node* prox;
};

struct WordCloud{
    char* fileName;
    Queue* queue;

};

WordCloud* wordCloudCreate(){

    WordCloud* wordCloud = malloc(sizeof(WordCloud));
    Queue* queue = malloc(sizeof(Queue));

    queue->fist = NULL;
    queue->end = NULL;

    wordCloud->queue = queue;

    return wordCloud;
    
}

Queue* insetEnd(Queue* queue, ElementWord* elementWord){

    Node* newNode = malloc(sizeof(Node));
    
    newNode->element = elementWord;
    newNode->prox = NULL;

    if(queue->end == NULL){

        queue->fist = newNode;
        queue->end = newNode;
        return queue;
    }
    
    queue->end->prox = newNode;
    queue->end = newNode;

    return queue;

}

void* pop(WordCloud* wordCloud){

    if(wordCloud->queue->fist){

        Node* tmp = wordCloud->queue->fist;
        wordCloud->queue->fist = tmp->prox;

        void* elementWord = tmp->element;
          
        free(tmp);

        return elementWord;
    
    }

    return NULL;

}

void insertWordInQueue(WordCloud* wordCloud, char* word, double pontuation){

    ElementWord* elem = malloc(sizeof(ElementWord));

    elem->pontuation = pontuation;
    int tam = strlen(word);

    
    elem->word = malloc(sizeof(char)*(tam+3));

    if(elem->word != NULL){
        strcpy(elem->word,word);

        wordCloud->queue = insetEnd(wordCloud->queue, elem);    
    }

}

void fileCreate(WordCloud* wordCloud, int maxWords, char* fileNameOutput){

    FILE * fp = fp = fopen(fileNameOutput,"w");

    fprintf(fp,"<!DOCTYPE html>\n<html lang='en'>\n<head>\n");
    fprintf(fp,"<meta charset='UTF-8'>\n<meta http-equiv='X-UA-Compatible' content='IE=edge'>\n");
    fprintf(fp, "<meta name='viewport' content='width=device-width, initial-scale=1.0'>\n");
    fprintf(fp, "<title>AED2 - WORDCLOUD</title>\n");
    fprintf(fp, "<style>\n");
    fprintf(fp, " html, body {\nheight: 100vh;width: 100vw;\n");
    fprintf(fp, "margin: 0;padding: 0; display: flex;\n");
    fprintf(fp, "align-items: center;justify-content: center; \n}");
    fprintf(fp, "ul.cloud {\nlist-style: none;\npadding-left: 0;\ndisplay: flex;\nflex-wrap: wrap;\nalign-items: center;\n");
    fprintf(fp,"justify-content: center;\nline-height: 2.75rem;\nwidth: 700px;\n}\n");

    fprintf(fp, "ul.cloud a {\n--size: 4;\n--color: #a33;\ncolor: var(--color);\n");
    fprintf(fp, "font-size: calc(var(--size) * 0.25rem + 0.5rem);\ndisplay: block;\npadding: 0.125rem 0.25rem;\n");
    fprintf(fp, "position: relative;\ntext-decoration: none;\n}\n");
    

    fprintf(fp, "ul.cloud a[data-weight='1'] { --size: 1; }\nul.cloud a[data-weight='2'] { --size: 2; }\n");
    fprintf(fp, "ul.cloud a[data-weight='3'] { --size: 3; }\nul.cloud a[data-weight='4'] { --size: 4; }\n");
    fprintf(fp, "ul.cloud a[data-weight='5'] { --size: 6; }\nul.cloud a[data-weight='6'] { --size: 8; }\n");
    fprintf(fp, "ul.cloud a[data-weight='7'] { --size: 10; }\nul.cloud a[data-weight='8'] { --size: 13; }\n");
    fprintf(fp, "ul.cloud a[data-weight='9'] { --size: 16; }");

    fprintf(fp, "ul[data-show-value] a::after {\ncontent: ' (' attr(data-weight) ')';\nfont-size: 1rem;\n}");

    fprintf(fp, "ul.cloud li:nth-child(2n+1) a { --color: #181; }\nul.cloud li:nth-child(3n+1) a { --color: #33a; }\n");
    fprintf(fp, "ul.cloud li:nth-child(4n+1) a { --color: #c38; }\nul.cloud a:focus {\noutline: 1px dashed;\n}");

    fprintf(fp, "ul.cloud a::before {\ncontent: '';\nposition: absolute;\ntop: 0;");
    fprintf(fp, "left: 50%%;\nwidth: 0;\nheight: 100%%;\nbackground: var(--color);\ntransform: translate(-50%%, 0);\n");
    fprintf(fp, "opacity: 0.15;\ntransition: width 0.25s;\n}\n");
    fprintf(fp, "ul.cloud a:focus::before,ul.cloud a:hover::before {\nwidth: 100%%;\n}\n");
    fprintf(fp, "@media (prefers-reduced-motion) {\nul.cloud * {\ntransition: none !important;\n}\n}\n");


    fprintf(fp, "</style>\n");
    fprintf(fp, "</head>\n");

    fprintf(fp, "<body>\n<ul class='cloud' role='navigation' aria-label='Webdev word cloud'>\n");

    ElementWord* elem;
    int tam = 0;
    int i = 0;
    while( (elem = pop(wordCloud)) && i < maxWords){
        tam = ((int)(elem->pontuation * 1000))%9;
        fprintf(fp, "<li><a href='#' data-weight='%d'>%s</a></li>\n", tam, elem->word);
        i++;
    
    }

    fprintf(fp, "</ul>\n</body>\n</html>");

    fclose(fp);
}