#include "stdio.h"
#include "assert.h"
#include "stdlib.h"
#include "lista.h"
#include "ddinamico.h"
#include "string.h"
#define SEED    0x392

struct ddinamico{

  // dados
  int tamanho;
  int nro_elementos;
  int fc;
  TListaSE* *entradas;
  unsigned int keyLen;

  // estatistica
  int nro_remocao;
  int nro_busca;
  int nro_insercao;
  long int nro_cmps_por_rmc;
  long int nro_cmps_por_bsc;
};

unsigned int MurmurHash2 ( const void * key, int len, unsigned int seed )
{
    // Fonte: https://sites.google.com/site/murmurhash/
	// 'm' and 'r' are mixing constants generated offline.
	// They're not really 'magic', they just happen to work well.

	const unsigned int m = 0x5bd1e995;
	const int r = 24;

	// Initialize the hash to a 'random' value

	unsigned int h = seed ^ len;

	// Mix 4 bytes at a time into the hash

	const unsigned char * data = (const unsigned char *)key;

	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m; 
		k ^= k >> r; 
		k *= m; 
		
		h *= m; 
		h ^= k;

		data += 4;
		len -= 4;
	}
	
	// Handle the last few bytes of the input array

	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};

	// Do a few final mixes of the hash to ensure the last few
	// bytes are well-incorporated.

	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;

	return h;
} 


static unsigned int hashing(TDDinamico* dd, void* key){
  return (MurmurHash2(key,dd->keyLen,SEED) % dd->tamanho);
}

static unsigned int primo_proximo(int num){
  short encontrou = 0;
  while(!encontrou){
    int i=2;
    while( (i<num) && ( (num%i) != 0) ){
      i++;
    }
    if (i==num){
      encontrou=1;
    }else{
      num+=1;
    }
  }
  return num;
}

typedef struct entrada{
  void* chave;
  void* info;
}TEntradaDD;

TEntradaDD* criar_entrada_DD(void* chave, void*info){
    TEntradaDD* e = malloc(sizeof(TEntradaDD));
    e->chave = chave;
    e->info = info;

    return e;
}

int compararEntradaDD(void* e1, void* e2, unsigned int tamElements){
  
  return memcmp(e1,e2,tamElements);
}

TDDinamico* criar_DD(int fator_carga, int tamanho, unsigned int keyLen){
    TDDinamico* dd = malloc(sizeof(TDDinamico));
    dd->fc = fator_carga;

    dd->tamanho = primo_proximo(tamanho);
    dd->nro_elementos = 0;
    dd->entradas = malloc(sizeof(TListaSE*)*dd->tamanho);

    for(int i=0;i<dd->tamanho;i++){
      dd->entradas[i] = criarLSE(NULL,compararEntradaDD, keyLen);
    }
    dd->nro_busca = dd->nro_remocao = dd->nro_insercao = 0;
    dd->nro_cmps_por_bsc = dd->nro_cmps_por_rmc = 0;
    dd->keyLen = keyLen;

    return dd;

}

void inserir_DD(TDDinamico *dd, void* chave, void* info){
    unsigned int k = hashing(dd, chave);
    TListaSE* l = dd->entradas[k];
    inserirInicioLSE(l, criar_entrada_DD(chave,info));
    dd->nro_elementos++;
    dd->nro_insercao++;
    
    // unica coisa qeu inclui no codigo repassado pelo professor
    // condicao que solicita avaliacao se eh caso de rehashing
    // chamada quando o tamanho da entrada tiver superado o fator de carga
    if ( tamanhoLSE(l) > dd->fc ) {
      faz_rehashing(dd);
    }    
}

void* buscar_DD(TDDinamico *dd, int chave){

  int k = hashing(dd, chave);
  TListaSE* l = dd->entradas[k];
  TEntradaDD* e =  buscarConteudoLSE(l, &chave );

  dd->nro_busca++;
  dd->nro_cmps_por_bsc += tamanhoLSE(l);

  return ( e ? e->info : NULL );

}

void* remover_DD(TDDinamico *dd, int chave){
  int k = hashing(dd, chave);
  TListaSE* l = dd->entradas[k];

  TEntradaDD* e =  removerConteudoLSE(l, &chave );

  dd->nro_remocao++;
  dd->nro_cmps_por_rmc += tamanhoLSE(l);

  void* info = NULL;
  if (e != NULL){
    info = e->info;
    free(e);
  }

  return info;
}

void destruirDD(TDDinamico *dd){
  for(int i=0; i<dd->tamanho;i++){
    destruirLSE(&(dd->entradas[i]));
  }
  free(dd->entradas);
  free(dd);
}

TDDinamico* re_hashingDD(TDDinamico *atual){
    TDDinamico *novo;
    
    // avaliar se eh suficiente o aumento da tabela para o proximo_primo ou um multiplicador
    // baseado no nivel de agrupamento da tabela (usado no calculo para decidir rehashing)
    novo = criar_DD(atual->fc, atual->tamanho+1, atual->keyLen);
    for(int i=0;i<atual->tamanho;i++){
      TListaSE *lse = atual->entradas[i];

      TEntradaDD *e = removerInicioLSE(lse);
      while(e!=NULL){
        inserir_DD(novo, e->chave, e->info);
        free(e);
        e = removerInicioLSE(lse);
      }
    }
    destruirDD(atual);
    return novo;
}

TDDinamico* faz_rehashing(TDDinamico *dd){

  int s_x=0, n = 0;
  for(int x, i=0;i<dd->tamanho;i++){
    TListaSE* lse = dd->entradas[i];
     x = tamanhoLSE(lse);
     s_x += x*x;
     n += x;
  }
  double C = (double)s_x/(double)n - dd->fc;
  if (C > 1.0){
    return re_hashingDD(dd);
  }else{
    return dd;
  }
}