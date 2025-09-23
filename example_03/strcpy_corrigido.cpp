#include <stdio.h>
#include <string.h>

void copy_data_safe(char *src) {
    char dest[16]; // Buffer de destino com capacidade para 16 bytes
    
    // snprintf limita o número de bytes copiados, prevenindo o overflow
    snprintf(dest, sizeof(dest), "%s", src);
    
    printf("Dados copiados com segurança: %s\n", dest);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Uso: %s <string_de_entrada>\n", argv[0]);
        return 1;
    }
    
    printf("Copiando a string de entrada...\n");
    copy_data_safe(argv[1]);
    
    return 0;
}