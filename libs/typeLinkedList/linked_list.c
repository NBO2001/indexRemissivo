#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linked_list.h"

typedef struct typeNode typeNode;

struct typeNode{

	void* data;
	struct typeNode * next;
	struct typeNode * previus;

};

struct typeList{

	typeNode * first;
	unsigned int ocupation;
	unsigned long int sizeElement;
	compator cmp;

	// Statistical parameters
    unsigned int totalComparation;
	unsigned int totalBuscas;

};



// Create new linked list
typeList * newLinkedList(compator cmp, unsigned long int sizeElement){

	typeList * list = malloc(sizeof(typeList));
	list->first = NULL;
	list->cmp = cmp;
	list->ocupation = 0;
	list->sizeElement = sizeElement;

	list->totalComparation = 0;
	list->totalBuscas = 0;
	return list;

}

// Create new node
typeNode * new_node(typeList * list,void * data){

	typeNode * node;

	node = (typeNode *) malloc(sizeof(typeNode));

	node->data = malloc(list->sizeElement);
	
	node->next = NULL;
	node->previus = NULL;
	
	memcpy(node->data, data, list->sizeElement);
	return node;

}

// Insert at the beginning of the list
void insert_start(typeList * list, void * data){

	typeNode * new_nd = new_node(list,data);
	typeNode * aux;

	aux = list->first;

	if(aux){

		aux->previus = new_nd;
		new_nd->next = aux;

	}
	list->ocupation++;
	list->first = new_nd;

}

void* remove_start(typeList * list){

	typeNode * aux;

	aux = list->first;

	if(!aux){ return NULL; }
	
	void* data = malloc(list->sizeElement);
	
	list->first = aux->next;

	if(list->first) list->first->previus = NULL;
	
	memcpy(data, aux->data, list->sizeElement);

	free(aux);

	list->ocupation--;

	return data;

}


void * seach_in_list(typeList * list, void* key){
	
	typeNode * aux;
	list->totalBuscas++;
	aux = list->first;
	
	while( aux && list->cmp(aux->data,key) != 0){
		list->totalComparation++;
		aux = aux->next;
	}
	

	if(aux){
		return aux->data;
	}else{
		return NULL;
	}



}

void* remove_with_key(typeList * list, void* key){

	typeNode* aux;
	void* data = malloc(list->sizeElement);

	aux = list->first;

	while( aux && list->cmp(aux->data,key) != 0){
		list->totalComparation++;
		aux = aux->next;
	}


	if(aux){
		if(aux->previus){

			aux->previus->next = aux->next;

			if(aux->next){
				aux->next->previus = aux->previus; 
			}
			
		
		}else{
			
			list->first = aux->next;
			list->first->previus = NULL;

		}
		memcpy(data, aux->data, list->sizeElement);
		free(aux);
		list->ocupation--;
		return data;
	}else{
		return data;
	}

}

void insert_end(typeList * list, void * data){

	typeNode * aux;
	
	typeNode * new_nd = new_node(list,data);

	aux = list->first;

	while (aux && aux->next)
	{
		aux = aux->next;
	}
	if(aux){

		new_nd->previus = aux;
		aux->next = new_nd;
	
	}else{
		list->first = new_nd;
	}
	list->ocupation++;

}

void * last_element(typeList * list){

	typeNode * aux;
	
	aux = list->first;

	while(aux && aux->next){
		aux = aux->next;
	}

	if(aux){
		return &(aux->data);
	}else{
		return NULL;
	}

}

unsigned int getTamList(typeList * list){ return list->ocupation; }

void deleteList(typeList * list){ free(list); }

double getTotalComparations(typeList * list){ return (double) list->totalComparation/list->totalBuscas; }