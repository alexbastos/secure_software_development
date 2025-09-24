# buffer overflow - Problema Corrigido

Para ilustrar uma possibilidade de correção da vulnerabilidade de buffer overflow, aqui está um exemplo de código em C que utiliza a função snprintf que limita o número de bytes copiados, prevenindo o overflow

# Para executar o código

# complilar o código em C++
    g++ strcpy_corrigido.cpp 

# executar o código 
    ./a.out Frase que será copiada

# Exemplo 
(base) alex@iMac-de-Alex example_03 % ./a.out AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA
Copiando a string de entrada...
Dados copiados com segurança: AAAAAAAAAAAAAAA

# Solução (Boas Práticas):

Para evitar esse problema, você deve usar funções mais seguras que realizam a verificação de limites. A melhor prática é sempre especificar o tamanho máximo de dados a serem copiados.

Em C++, as alternativas seguras para strcpy são:

strncpy: Copia no máximo n caracteres. No entanto, ela não garante que a string de destino será terminada com \0, então é preciso adicionar o terminador manualmente.

snprintf: Uma opção ainda melhor. Ela formata e copia uma string com segurança, garantindo que o buffer não será estourado e que a string será sempre terminada com um caractere nulo.

A sua experiência prática demonstra exatamente por que o desenvolvimento de software seguro é crucial: um erro simples de programação pode levar a uma vulnerabilidade crítica, como um buffer overflow.
