// Da pra mudar depois a maioria das ideias (Talvez mude, principalmente a parte de pesos)
// Atualmente a ideia: Vertices APENAS de filmes (Diretores, atores, generos serao apenas pesos)
// API de TMDb e Gemini (Google AI Studio) serao as usadas possivelmente - Todas as chaves no Trello (Temporariamente)
// Links curl: 
// Site oficial: https://curl.se/libcurl/
// Explicacao: https://curl.se/libcurl/c/curl_easy_setopt.html 
// Exemplos: https://curl.se/libcurl/c/example.html
// pacman -S mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-curl mingw-w64-ucrt-x86_64-cjson (Caso nao tenha as biblioteca)
// .\Grafos.exe

// Bibliotecas

#include <stdio.h>
#include <curl/curl.h> // Para usar as APIs (Essa biblioteca possibilita o Https e etc)
#include <cjson/cJSON.h> // Usar JSON, literalmente so pra isso, ler as respostas da API do TMDb 

// Estruturas

typedef struct Aresta {
    int ID_Destino; // ID do filme que a aresta conecta, se ela sai do A e tem ID do B, no B ela tem ID do A
    int semelhanca; // De 1 a 10, igual ao Mapeamento 
    struct Aresta *prox; // proxima aresta do filme em que ela ta, se ela sai do A pro B, seria a proxima aresta do A
} Aresta;

typedef struct Vfilme{ // Vertice de filme
  int ID; // Literalmente o ID do filme do TMDb
  char nome[150]; // Nome do filme
  char imagem[100]; // Capa do filme, o TMDb passa a URL
  Aresta *adjListas; // Lista de arestas desse filme
  struct Vfilme *prox; 
} Vfilme;

typedef struct Grafo {
    int n_filmes; // Quantidade total de filmes (Carregados)
    Vfilme *primeiro_filme; // Primeiro da lista, se perder esse aqui ferrou
} Grafo;

// Funcoes

// Nada ainda

// Main

void main(){
    Grafo grafo; // Iniciando o grafo
    grafo.n_filmes = 0; // Tem 0 filmes agora
    grafo.primeiro_filme = NULL; // Oficialmente zerado

    CURL *curl = curl_easy_init();
    if(curl) {
        CURLcode result;
        curl_easy_setopt(curl, CURLOPT_URL, "https://example.com/foo.bin");
    
        /* DELETE the given path */
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
    
        result = curl_easy_perform(curl);
    
        curl_easy_cleanup(curl);
    }
}
