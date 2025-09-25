#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char pequeno_buffer[10];

    printf("Tamanho do buffer de destino: %zu\n", sizeof(pequeno_buffer));

    if (argc < 2) {
        printf("Uso: %s <string_de_entrada>\n", argv[0]);
        return 1;
    }

    // A operação perigosa:
    // strcpy não verifica o tamanho da string de origem,
    // permitindo que dados extra sobrescrevam a memória adjacente.
    strcpy(pequeno_buffer, argv[1]);

    printf("String copiada: %s\n", pequeno_buffer);

    return 0;
}