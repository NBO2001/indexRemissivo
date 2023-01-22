typedef struct ddinamico TDDinamico;
TDDinamico* criar_DD(int fator_carga, int tamanho, unsigned int keyLen);
void inserir_DD(TDDinamico *dd, int chave, void* info);
void* buscar_DD(TDDinamico *dd, int chave);
void* remover_DD(TDDinamico *dd, int chave);
void destruirDD(TDDinamico *dd);
