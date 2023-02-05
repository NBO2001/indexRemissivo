# Relatório Trabalho Parcial AED2

## Integrantes

* Bruno Maciel
* Girlana Souza
* Marcello Cipriano
* Natanael Oliveira

## 1.Introdução

Um Índice Remissivo é uma lista de termos ou expressões presentes em uma obra escrita juntamente com suas respectivas páginas de referência. É uma ferramenta útil para ajudar o leitor a encontrar informações específicas dentro de um documento grande. O índice remissivo será mais eficiente quando conseguir direcionar o leitor para as ocorrências mais significativas de uma palavra no texto.

A presença de *stop words* é uma questão importante a ser considerada durante a implementação do trabalho. *Stop words* são termos comuns, como preposições, artigos, advérbios, números, pronomes e pontuação, que geralmente não são considerados relevantes para um documento.

O conceito de TF-IDF é uma medida estatística que avalia a importância de uma palavra em um documento em relação a uma coleção de documentos. A sigla significa "Frequência do Termo - Inversa da Frequência no Documento" e combina a frequência de um termo (TF) no documento com sua rareza (IDF) na coleção de documentos. O objetivo é identificar as palavras mais informativas e exclusivas do documento, permitindo assim uma melhor compreensão e análise do conteúdo.

No contexto de um único documento, o TF-IDF é calculado como o produto da frequência do termo (TF) e a frequência inversa do documento (IDF). A frequência de um termo em um documento (TF) é o número de vezes que o termo aparece no documento, enquanto a frequência inversa do documento (IDF) é calculada como o logaritmo do número total de documentos dividido pelo número de documentos que contêm o termo. No caso, uma *stop word* não possui nível de relevância, dessa forma, sua frequência é desconsiderada na implementação desse trabalho.

Este trabalho tem como objetivo criar um programa que gerará um índice remissivo de um livro em formato de texto. Isso será realizado utilizando conceitos de Tipos Abstratos de Dados (TAD) e técnicas de armazenamento como dicionários estáticos e dinâmicos. O resultado final será um conjunto de cinco páginas de cada palavra do livro, ordenado pelo número de relevância. Para garantir a eficiência e performance, é importante escolher uma estrutura de dados adequada e aplicar técnicas eficientes de armazenamento e busca de informações.

## 2.Projeto da implementação (Métodos)

Uma das primeiras e mais importantes tarefas relacionadas com a ideia de construção de um índice remissivo de uma obra literária utilizando uma ferramenta computacional é, sobretudo, a escolha ou identificação dos tipos de estruturas de dados que permitiriam a manipulação mais eficiente dos dados relacionados com tal aplicação.

Sabe-se que uma obra literária contém um texto fixo de palavras escritas em determinado idioma, portanto não sujeitos a frequentes alterações e acréscimos. Até mesmo em outros tipos bibliográficos, como por exemplo, nos livros didáticos, cujas alterações ou atualizações acontecem com uma maior frequência, estas não costumam produzir acréscimos significativos de conteúdo em comparação à obra como um todo.

Nessas condições, é possível perceber que a utilização do conceito de dicionário para um projeto de índice remissivo é muito adequada, na medida em que esse gênero de estrutura de dados, mesmo as que possuem a característica de um maior dinamismo no tocante à atualização das informações, tem por escopo trabalhar a manipulação de dados mais fixos, ou melhor dizendo, mais definitivos, como no caso do presente projeto; permitindo, assim, que a estrutura concentre suas aptidões ou dê maior ênfase à eficiência dos processos de acesso, busca e manipulação interna das informações, conforme a necessidade da aplicação que a utiliza.

Sabe-se que a estrutura do dicionário traz em si apenas um conceito genérico, do qual se extrai certos padrões e características, acima rapidamente abordados, que direcionam a sua aptidão para uma dada aplicação, na esteira do escopo de um TAD, por exemplo. Porém, na sua base de construção propriamente dita, faz-se necessário escolher um tipo específico de estrutura de dados que trabalhe bem com a ideia de dicionário nos moldes mais adequados às funções previstas para o modelo e adapatado ao objeto específico de sua utilização.

Uma das mais clássicas abordagens para construção de dicionário é a que utiliza as tabelas de espalhamento ou dispersão, as conhecidas tabelas *hash*, que tem por principal característica otimizar os processos de seleção e busca de informações, em níveis superiores até aos dos mais eficientes algoritmos para essa atividade específica, como os de busca binária, por exemplo, os quais ainda exigem o contexto da ordenação dos dados. [Maurer et al., 1975]

Além disso, importante frisar que a tabela *hash* tem também alta indicação para processos em que o universo dos dados a serem manipulados seja relativamente conhecido pelo próprio usuário da aplicação, especialmente quanto a uma estimativa de quantidade de informações sob manuseio, o que poderia facilitar a customização da estrutura de dados, sendo esta uma das principais características dessas tabelas de dispersão. [Botelho, 2004]

Observa-se, portanto, que a ideia de utilização das tabelas de espalhamento claramente se enquadra no modelo de dicionário para a aplicação ora em comento, que se propõe a processar um conjunto limitado e conhecido de dados, facilmente estimáveis, como uma quantidade de palavras em um livro.

Nessa esteira, o projeto se iniciou com a ideia de construir inicialmente dois tipos de dicionários: um, de característica mais estática, isto é, de conteúdo fixo e de uso genérico, para a guarda de um índice das mencionadas *stop words*; e um outro, dinâmico, com maioir facilidade para a inserção de diferentes conteúdos e eventuais alterações, que seria utilizado na guarda e organização dos dados que seriam manipulados pelo índice remissivo propriamente dito.

Para tanto, e como modelo de organização do projeto, foram desenvolvidos alguns Tipos Abstratos de Dados, com suas estruturas específicas e funções direcionadas à manipulação dos dados relacionados com seu escopo, dentre os quais:

### 2.1.*typeTableHash*

#### 2.1.1 Definição

Este é o TAD de base, onde se implementa a estrutura de dados que será usada para administrar o uso das espécies de dicionários que serão úteis na aplicação computacional de que trata o presente trabalho. Neste tipo, tem-se a modelagem de uma tabela *hash* com parâmetros flexíveis a permitir a criação de uma tabela de dispersão com diferentes características, desde modelos mais estáticos, de tamanho fixos, a alternativas de crescimento dinâmico (*rehashing*) e com variação do fator de carga, a possibilitar eficiência de busca sempre superior a de um algoritmo
de busca binária, sem a necessidade de ordenação completa.

#### 2.1.2 Fator de carga

Fator de carga é a expectativa de desempenho no pior caso de busca da tabela *hash*. Dependendo a funcao de espalhamento, o tamanho das listas encadeadas podem se menores ou maiores que esse fator de carga.

#### 2.1.3 Quando executar *rehashing*

Em nossa implementacao há duas metricas importante, metrica de dispersao na tabela e de maior lista encadeda no conjunto.

* Metrica de dispersao na tabela:

    ![Equancao](imgs/equacao1.png "Equacao 1")

    Essa metrica mede o nível de agrupamento, onde Xi indica o número de colisões por entrada ou o tamanho da lista formada a partir de uma entrada da tabela. Dessa forma, o nível de agrupamento da *hash* é dado pelo somatório do quadrado do tamanho de cada entrada, dividido pelo número de elementos da tabela ou de chaves mapeadas, menos o fator de carga aplicado. Caso o índice supere 1.0 (um), demonstra que o espalhamento não está eficiente e indica a necessidade de um eventual *rehashing*.

* Maior lista encadeada:

    Esta avaliacao monitora o tamanho da maior lista encadeada, quando esse ultrapassa o fator de carga indica a necessidade de um eventual *rehashing*.

#### 2.1.4 *Rehashing*

A funcao de *rehashing* aumenta o tamanho da tabela usando a seguinte equancao; l = i + 0.4 \* i + 0.1 \* n.

Em que *l* é o novo tamanho, *i* é o total de chaves atual e *n* o tamanho atual da tabela.

### 2.2.*typeStaticDictionary*

Tipo Abstrato básico, de camada intermediária, que modela genericamente a implementação de uma estrutura de Dicionário com característica mais estática, contendo somente funções que permitem o carregamento (inserção dos elementos) e a consulta, portanto sem previsão para remoções. No contexto do presente trabalho, é o plano de fundo do *typeStopWords* e suas respectivas funções de manipulação de dados.

### 2.3.*typeStopWords*

Tipo responsável pela criação do coadjuvante dicionário de *stop words*, com a implementação de uma função de pesquisa dessa espécie de dicionário de caráter mais estático, a fim de facilitar a identificação das palavras que não precisam ser consideradas na confecção do índice remissivo.

### 2.4.*typeDynamicDictionary*

Também é um tipo básico de camada intermediária que implementa genericamente uma estrutura de Dicionário, porém com atributos e funções de um grau maior de flexibilidade quanto à manipulação dos dados, pois admite operações, não só de inserção e consulta, mas também de remoção eventual. Será útil para caracterizar a modelagem do Índice Remissivo propriamente dito.

### 2.5.*typeIndex*

Contém o TAD de mais alto nível da aplicação, ao qual se vinculam todos os demais tipos abstratos intermediários, bem como um cojunto de funções auxiliares de manipulação de strings e outras utilidades, para tornar operável o sistema de montagem (processo de leitura e guarda de dados) e consulta do Índice Remissivo reclamado no projeto. Nele também estão previstos os processos de confecção dos arquivos contendo as avaliações de seu desempenho.

### 2.6.*tipoPalavra*

Tipo Abstrato de importância central contendo a previsão da estrutura de guarda dos dados principais (palavras e seus atributos) que serão manipulados pelos dicionários e usados na modelagem do índice remissivo, bem como no processamento das avaliações estatísticas e comparativas. Contém também as funções de organização e ordenação das palavras conforme a relevância de suas ocorrências nas páginas.

### 2.7.*typeDocument*

Documento, na esteira do presente trabalho, é cada página das obras literárias.
O TAD em referência tem caráter auxiliar do tipoPalavra, pois objetiva primordialmente apoiar a manipulação dos dados com uma administração estratificada por documento, organizando o processo de leitura e guarda das palavras a partir de uma pauta da página com indicadores de seu início e fim, além de um contador de palavras, útil para o cálculo do fator de relevância da palavra em cada documento.

### 2.8.*typeLinkedList*

Também é um tipo auxiliar, usado com fins organizativos para especializar as funções de montagem e manuseio dos dados guardados nas estruturas de listas que vão compor as entradas da tabela principal de guarda e busca dos dados contidos nos dicionários.

### 2.9.Fluxo da Aplicação

![Fluxo da aplicao](imgs/fluxo.png "Fluxo")

## 3.Discussões e Resultados

Após a implementação do Índice Remissivo, conforme o modelo acima descrito, foi utilizada uma base de dados de teste fornecida pelo professor Cesar Melo, contendo os textos completos, em formato digital, de três obras literárias:

* As Aventuras de Huckleberry Finn (1);
* O Guarani (2); e
* Paralelismo em visao natural e artificial (3)

A aplicação foi capaz de construir um índice remissivo para cada obra, com indicativo de todas as palavras contidas nos textos, não classificadas como *stop words*. Todas as palavras apresentadas pelo índice foram associadas às respectivas páginas em que ocorre, porém limitadas ao número máximo de 5 (cinco) páginas por palavra, selecionadas segundo a ordem de relevância do termo no contexto de cada página em comparação com as demais onde a palavra ocorre.

Um dos principais objetivos do trabalho era permitir que fosse feita uma avaliação da eficiência e performance das estruturas de dados usadas na construção dos dicionários e do índice remissivo propriamente dito, motivo pelo qual foram incorporados ao projeto da implementação, algumas estruturas e funções estatísticas para medição desses citados indicadores, a partir das quais foram extraídos os dados compreendidos nas tabelas abaixo, referentes ao conteúdo de cada um dos três livros acima mencionados, bem como ao modelo de dicionário genérico aplicado para guarda da relação de *stop words*.

Foram feitas cinto tipos de análise de performance do dicionário e do uso da técnica de espalhamento próprias de tabela *hash* para cada uma das cinco obras e para o índice de *stop words*. Cada uma dessas cinco análises, envolvia a customização da técnica de dispersão usada na modelagem da tabela *hash* aplicada, para permitir a comparação entre os modelos a fim de identificar qual o que demonstraria maior aplicabilidade a certa atividade dependendo de suas características.

Foi, portanto, estudada a performance dos dicionários, usando os seguintes cenarios;

- Tabela *hash* sem execultar *re-hashing* e com o tamanho 2.

- Tabela *hash* usando para execultar *re-hashing* a metrica de avalicacao de dispersão. E com o tamanho inicial 2.

- Tabela *hash* usando para execultar *re-hashing* a metrica de avalicacao de dispersão e levando em consideracao a maior lista encadeada. E com o tamanho inicial 2.

- Tabela *hash* usando para execultar *re-hashing* a metrica de avalicacao de dispersão e levando em consideracao a maior lista encadeada. E com o tamanho inicial 2 e fator de carga fixo em 5.

- Tabela *hash* usando para execultar *re-hashing* a metrica de avalicacao de dispersão e levando em consideracao a maior lista encadeada. E com o tamanho inicial 2 e fator de carga fixo em 4.

Nessa segunda abordagem, a tabela cresceria dinamicamente conforme as inserções, mas à razão de um fator de carga calculado para representar um valor inteiro menor que o log2 N (log de N na base 2), onde N seria o número de elementos inseridos. Com isso, a ideia era manter o tamanho da tabela em uma dimensão menor que o número de chaves mapeadas para *hash* obviamente, porém mantendo a propriedade de garantir um número médio de colisões, que significariam número de comparações, sempre, ou na maioria dos casos, abaixo do esperado para uma busca binária, que, por sua vez, já é considerada um modelo de busca bem eficiente.

Foi, no entanto, aplicado, nesse segundo modelo de montagem das tabelas de dispersão, dois critérios diferentes para o redimensionamento da tabela ou *rehashing*. Em um caso, a reconstrução da tabela aconteceria bastando que uma das entradas da tabela passasse a ter uma lista de elementos (indicativo de colisões) com tamanho que superasse o fator de carga; e no outro caso, para tal redimensionamento, necessitaria também que o índice (C) que avalia o nível de agrupamento da tabela superasse, após uma dada inserção, o valor de 1.0 (um).

Esse mencionado índice que mede o nível de agrupamento é calculado pela fórmula: C = [ ∑ (Xi)2 / N ] - FC, onde Xi indica o número de colisões por entrada ou o tamanho da lista formada a partir de uma entrada da tabela. Dessa forma, o nível de agrupamento da *hash* é dado pelo somatório do quadrado do tamanho de cada entrada, dividido pelo número de elementos da tabela ou de chaves mapeadas, menos o fator de carga aplicado. Caso o índice supere 1.0 (um), demonstra que o espalhamento não está eficiente e indica a necessidade de um eventual *rehashing*.

Dadas essas explicações, podemos resumir as análises e resultados contidos nos quadros abaixo em avaliações de três tipos específicos de tabelas de dispersão:

* TIPO I - com dimensão fixa e superior ao quantitativo estimado de chaves a serem mapeadas;
* TIPO II - com tamanho menor que o número de chaves, porém redimensionável a partir da superação do fator de carga;
* TIPO III - com tamanho menor que o número de chaves, porém redimensionável a partir da avaliação do nível de agrupamento;

------------------------

### **QUADROS DE ESTATÍSTICA:**

----------------------

### **TypeStopWord Dictionary:**

* **TIPO I** - Dicionário com um tamanho inicial de 400 (quatrocentos).


* **TIPO II** - Dicionário com um tamanho inicial de 2 (dois) e critério de avaliação do *rehashing* usando a métrica que avalia a qualidade da tabela *hash* construída, a partir do tamanho de uma entrada (lista) maior que o fator de carga.






* **TIPO I** - Dicionário com um tamanho inicial de 14.000 (quatorze mil).


### **Análise de Espalhamento**


* **TIPO II** - Dicionário com um tamanho inicial de 2 (dois) e critério de avaliação do *rehashing* usando a métrica que avalia a qualidade da tabela *hash* construída, a partir do tamanho de uma entrada (lista) maior que o fator de carga.


* **TIPO III** - Dicionário com um tamanho inicial de 2 (dois) e critério de avaliação do *rehashing* usando a métrica que avalia a qualidade da tabela *hash* construída, a partir do nível de agrupamento de chaves nas entradas.





* **TIPO I** - Dicionário com um tamanho inicial de 14.000 (quatorze mil).




* **TIPO II** - Dicionário com um tamanho inicial de 2 (dois) e critério de avaliação do *rehashing* usando a métrica que avalia a qualidade da tabela *hash* construída, a partir do tamanho de uma entrada (lista) maior que o fator de carga.

* **TIPO III** - Dicionário com um tamanho inicial de 2 (dois) e critério de avaliação do *rehashing* usando a métrica que avalia a qualidade da tabela *hash* construída, a partir do nível de agrupamento de chaves nas entradas.


* **TIPO I** - Dicionário com um tamanho inicial de 14.000 (quatorze mil).


* **TIPO II** - Dicionário com um tamanho inicial de 2 (dois) e critério de avaliação do *rehashing* usando a métrica que avalia a qualidade da tabela *hash* construída, a partir do tamanho de uma entrada (lista) maior que o fator de carga.


* **TIPO III** - Dicionário com um tamanho inicial de 2 (dois) e critério de avaliação do *rehashing* usando a métrica que avalia a qualidade da tabela *hash* construída, a partir do nível de agrupamento de chaves nas entradas.




A respeito das citadas modelagens da *hash* avaliadas, os quadros acima demonstram, em primeiro lugar, que o uso de tabelas do TIPO I não é suficiente para garantir um espalhamento adequado das chaves ou elementos do dicionário, pois observa-se que para todos os textos usados nos testes, e também para as *stop words*, a taxa de ocupação da tabela com dimensão superior, apesar do assumido custo de memória, figura sempre na faixa de cerca de 50% (cinquenta por cento), denotando subutilização, e com média de comparações por busca bem próxima de uma tabela do TIPO II, que otimiza o gasto de memória. O único fator de vantagem que pode ser extraído das análises para a tabela do TIPO I, seria a ausência de custo de *rehashing*.

É possível, no entanto, admitir que estas implementações podem se adequar melhor a aplicações que, pela natureza dos dados manipulados, não exijam muito espaço de memória, sendo necessário, porém, a utilização de uma função de *hashing* e técnica de tratamento de colisões, que, em conjunto, ofereçam uma melhor performance de espalhamento.

No tocante às análises feitas com as tabelas do TIPO II e III, que comumente operam com dimensão menor do que o número de chaves mapeadas, nota-se que ambas conseguiram desenvolver um nível de espalhamento das chaves bem siginificativo, com taxas de ocupação do vetor em patamares médios acima de 80% (oitenta por cento) para as do TIPO II, e acima de 90% (noventa por cento) para as do TIPO III, mesmo com uma dimensão inferior a 50% (cinquenta por cento) em relação à quantidade de elementos. Em alguns casos, conseguindo tal performance de dispersão, mesmo com uma dimensão próxima ao impressionante patamar de cerca de apenas 30% (trinta por cento) do número de chaves mapeadas, para casos das tabelas do TIPO III. Tal dado, pode ser explicado certamente pelo grau de eficiência da função de *hashing* usada.

[TALVEZ EXPLICAR SOBRE A MURMUR AQUI]

Por outro lado, traçando um comparativo entre os resultados obtidos com as tabelas do TIPO II e III, foi possível perceber que há uma maior distribuição dos elementos (palavras, no caso dos experimentos) pelas entradas da tabela do TIPO III, isto é, aquela que usa como critério para seu redimensionamento somente o índice que mede o seu nível de agrupamento. Esse tipo de tabela produziu maiores taxas de ocupação do vetor, com realização de um número menor de *rehashings*, porém construiu entradas ligeiramente maiores (com mais elementos) do que a do TIPO II, o que provocou uma média de comparações por busca um pouco maior, porém ainda abaixo do fator de carga.

A tabela do TIPO II, por sua vez, onde o redimensionamento ocorre pela simples superação do fator de carga por qualquer de suas entradas, promove naturalmente um número maior de *rehashings*, trazendo como resultado um menor número de colisões por entrada e, a partir daí, uma melhor performance na média de comparações por busca do que a do TIPO III, porém não otimiza muito bem a memória, pois, em alguns casos dos experimentos, a sua dimensão (tamanho do vetor) chegou a patamares relativamente próximos ao quantitativo total de chaves mapeadas, mas ainda assim com vantagens em relação ao vetor de tamanho fixo e dimensão superior (tabela do TIPO I).

## 4.Conclusão

## Referências

CRIAR e Atualizar um Índice Remissivo. [S. l.], 2 fev. 2023. Disponível em: <https://support.microsoft.com/pt-pt/office/criar-e-atualizar-um-%C3%ADndice-remissivo-cc502c71-a605-41fd-9a02-cda9d14bf073>. Acesso em: 2 fev. 2023.

Botelho, F. C. (2004). Estudo Comparativo do Uso de Hashing Perfeito Mínimo.
Dissertação de Mestrado. Belo Horizonte: Universidade Federal de Minas Gerais

Maurer, W. D., & Lewis, T. G. (1975). Hash table methods. ACM Computing Surveys (CSUR), 7(1), 5-19.