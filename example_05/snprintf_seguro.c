#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
    char pequeno_buffer[10];
    const char* string_de_entrada;

    printf("Tamanho do buffer de destino: %zu\n", sizeof(pequeno_buffer));

    if (argc < 2) {
        printf("Uso: %s <string_de_entrada>\n", argv[0]);
        return 1;
    }
    
    string_de_entrada = argv[1];

    // A operação segura e portável:
    // snprintf copia no máximo (tamanho do buffer - 1) caracteres
    // e garante que o buffer será terminado em nulo.
    snprintf(pequeno_buffer, sizeof(pequeno_buffer), "%s", string_de_entrada);

    printf("String copiada com segurança: %s\n", pequeno_buffer);

    return 0;
}