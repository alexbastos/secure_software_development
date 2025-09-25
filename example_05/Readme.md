# Estudo de Caso: Comparação de Funções de Cópia de String

Para demonstrar a diferença entre funções de manipulação de strings inseguras e seguras, vamos comparar um trecho de código vulnerável usando strcpy com uma versão corrigida usando strncpy_s.

Nota: As funções com sufixo _s (como strncpy_s, memcpy_s) são partes do anexo seguro da biblioteca padrão C11, projetadas para evitar vulnerabilidades de segurança. Elas podem não estar disponíveis ou ativadas em todos os compiladores.

# 1. Código Vulnerável (usando strcpy)

Este exemplo demonstra como strcpy pode ser usado para causar um buffer overflow.

arquivo: strcpy_buffer.C

# Problema: 

Se o usuário executar este programa com uma string de entrada com mais de 9 caracteres (ex: ./programa "AAAAAAAAAAAAAAAAAAAA"), a função strcpy tentará copiar todos os 20 caracteres para um buffer de 10 bytes, resultando em um buffer overflow. A execução do programa pode falhar, travar ou, em um ataque, executar código malicioso.

# 2. Código Seguro (usando snprintf)

# Solução Segura e Padrão

A função snprintf escreve no buffer de destino garantindo que o número de caracteres copiados não exceda o tamanho máximo que você especificar. Ela também adiciona automaticamente o terminador nulo (\0) se houver espaço.

Aqui está o seu código corrigido usando snprintf:

arquivo: snprintf_seguro.C

# Por que esta solução é melhor?

O código acima é considerado uma boa prática porque:

É Portátil: A função snprintf é parte do padrão C e funciona em praticamente todos os compiladores e sistemas operacionais.

É Segura: Ela previne o estouro de buffer, pois nunca escreverá mais dados do que o tamanho do buffer especificado.

É Confiável: Garante que a string no pequeno_buffer será sempre terminada em nulo, evitando erros de leitura de string no futuro.


# Compilar e Executar

gcc strcpy_buffer.c   

./a.out AAAAAAAAAAAAAAAAAAAAAA

Após execução:
Tamanho do buffer de destino: 10
zsh: illegal hardware instruction  ./a.out AAAAAAAAAAAAAAAAAAAAAA

gcc snprintf_seguro.c   

./a.out AAAAAAAAAAAAAAAAAAAAAA

Após execução:
Tamanho do buffer de destino: 10
String copiada com segurança: AAAAAAAAA