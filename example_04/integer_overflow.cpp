#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void allocate_and_copy(int size, char* user_data) {
    if (size > 1024) {
        printf("Tamanho muito grande, recusa a alocação.\n");
        return;
    }
    
    char* buffer = (char*)malloc(size); // Aloca a memória com o tamanho fornecido
    if (buffer) {
        // A verificação de tamanho falha se 'size' for um valor negativo
        memcpy(buffer, user_data, size);
        printf("Dados copiados com sucesso.\n");
        free(buffer);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        return 1;
    }
    
    int data_length = atoi(argv[1]);
    
    // Suponha que o user_data tenha um tamanho muito grande
    char user_data[2000];
    memset(user_data, 'A', 2000);
    
    allocate_and_copy(data_length, user_data);
    
    return 0;
}