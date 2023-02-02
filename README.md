# Plano de desevolvimento

Index Remissivo.

## Organizaçao do projeto

A ideia é fazer todo o projeto usando a programaçao orientada a objetos, ou o mais proximo disso possivel.

Por isso, para cada tipo desevolvido, é necessario criar as funcoes de get e set.

Exemplo:

    struct typePerson{
        char * name;
        int age;
        double height;
    }

    char * getName(typePerson * instance){ return instance->name; }
    void setName(typePerson * instance, char * name){ 
        strcpy(instance->name, name); 
    }

    int getAge(typePerson * instance){ return instance->age; }
    void setAge(typePerson * instance, int age){ 
         instance->age = age; 
    }

    int getHeight(typePerson * instance){ return instance->height; }
    void setHeight(typePerson * instance, double Height){
        instance->height = height;
    }

Todas as estrutruras de dados devem estar em pastas.

Exemplo, a estrutura typePerson, tem a pasta typePerson, que dentro tem typePerson.c e typePerson.h

## Estruturas a desenvolver

### Tipo documento

Uma estrutura para armazenar o numero da pagina, a posiçao (bytes) inicial e final de um documento, além da quantidades de palavras do documento.

### Tipo livro

Uma estrutura para armazenar uma coleçao de documentos.

### Tipo palavra

Uma estrututura para armazenar uma palavra, a recorrencia total e uma lista de tuplas com sua recorrencia para cada documento em que essa palavra aparece, além do endereço do documento.

### Tuple

Uma estrutura de dados que armazena apenas dois elementos.

Para pegar o primeito elemento de uma tuple tem que ter a funçao fist().

E para pegar o segundo elemento tem que ter a funçao secund().

### Tipo palavras

Uma estrura para amazenar uma colecao de palavras.

### hash genericos

Todos os tipos de hash genericos, usando o memcpy.

## Funçoes a desevolver

``def isLetter(letter)``, funçao que retorna verdeiro se a letra é um caractere valido e falso caso contrário.

``def cleaningWord(word)``, funçao que limpa uma string tirando todos os caracteres invalidos do inicio e do fim da string.

``def tf(palavra, doc)``, funcao que recebe a recorrecia de uma palavra e divide pela quantidade de palavras do documento.

``def idf(qntWords, docs)``, funcao que recebe a quantidade de documentos que a palavra ocorre e divide pelo total de documentos e feito o log no resulto.

``def tfidf(palavra, doc,qntWords, docs)``, funcao que multiplica tf() * idf()

``def _isStopWord(word)``, retorna verdadeiro se uma palavra é uma stop word, falso caso contrário# indexRemissivo

| Syntax      | Description |
| ----------- | ----------- |
| Header      | Title       |
| Paragraph   | Text        |
