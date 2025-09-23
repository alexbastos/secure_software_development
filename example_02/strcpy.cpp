#include <stdio.h>
#include <string.h>

/*
 * Esta função copia o conteúdo da string 'src' para o buffer 'dest'.
 * É vulnerável a buffer overflow porque a função strcpy não verifica
 * se o tamanho da string de origem é maior que a capacidade do buffer de destino.
 */
void copy_data(char *src) {
    char dest[16]; // Buffer de destino com capacidade para 16 bytes
    
    // A função strcpy não verifica o tamanho de 'src'
    strcpy(dest, src);
    
    printf("Dados copiados: %s\n", dest);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <string_de_entrada>\n", argv[0]);
        return 1;
    }
    
    printf("Copiando a string de entrada...\n");
    copy_data(argv[1]);
    
    return 0;
}