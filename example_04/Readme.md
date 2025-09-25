# Integer Overflow

# 1. O que é um Inteiro?

Em programação, um inteiro é um tipo de dado que armazena números inteiros (sem casas decimais). O espaço de memória alocado para um inteiro é fixo, geralmente 8, 16, 32 ou 64 bits. Esse tamanho limita a quantidade de números que o inteiro pode representar. Por exemplo, um unsigned int de 32 bits pode armazenar valores de 0 a 4.294.967.295.

# 2. O Mecanismo do Ataque

O Integer Overflow (Estouro de Inteiro) ocorre quando o resultado de uma operação aritmética (como adição, multiplicação ou subtração) excede o valor máximo que o tipo de dado pode conter. Em vez de simplesmente gerar um erro, o valor "dá a volta" (wraps around) para o seu valor mínimo.

# Exemplo Simples:

Se você tem um inteiro de 8 bits sem sinal (valores de 0 a 255) e o valor atual é 255.

Ao somar 255 + 1, o resultado não será 256. Em vez disso, ele voltará para 0.

Da mesma forma, se você subtrair 0 - 1, o resultado será 255.

Essa "volta" inesperada pode ser explorada por atacantes para subverter a lógica do programa.

# 3. Como um Ataque de Integer Overflow Funciona

Um atacante pode manipular a entrada de dados para causar um estouro de inteiro, o que muitas vezes leva a outras vulnerabilidades, como o buffer overflow. O ataque geralmente segue este padrão:

Entrada Maliciosa: O atacante fornece um valor de entrada que, quando submetido a uma operação aritmética, causará um overflow.

Bypass de Verificações: O overflow faz com que uma verificação de segurança, como um limite de tamanho ou uma alocação de memória, seja ignorada.

Vulnerabilidade Secundária: O programa então executa uma operação insegura (como uma cópia de buffer) com um valor incorreto (causado pelo overflow), levando a um crash ou, mais perigosamente, a um buffer overflow controlável.

# 4. Código 

- código em C++ - integer_overflow.cpp

Neste exemplo, se o atacante fornecer um valor negativo para data_length, a verificação if (size > 1024) seria ignorada. malloc pode interpretar um número negativo como um número muito grande, ou o memcpy pode copiar dados em excesso, pois um número negativo, quando interpretado como um size_t (que é unsigned), se torna um número positivo enorme.

# 5. Mitigações e Boas Práticas

Tipos de Dados Apropriados: Usar tipos de dados sem sinal (unsigned int, size_t) para valores que nunca devem ser negativos, como tamanhos ou contadores.

Verificação de Limites: Validar sempre a entrada do usuário para garantir que os valores estão dentro de limites esperados antes de realizar operações aritméticas.

Verificação Pós-Cálculo: Após uma operação, verificar se o resultado é maior que o valor de entrada original, o que pode indicar um overflow (ex: if (a + b < a)).

Bibliotecas Seguras: Usar bibliotecas que fornecem funções seguras para operações aritméticas, que podem detectar e lidar com overflows.

Compiladores Modernos: Compiladores recentes podem ser configurados para emitir avisos ou até mesmo adicionar verificações de overflow em tempo de execução para certos tipos de dados, tornando o desenvolvimento mais seguro.


# ##########################################################################
# Exemplo de um Estudo de Caso: Integer Overflow em um Sistema de E-commerce

# Cenário:

Imagine um sistema de e-commerce simples onde os clientes têm uma carteira digital (saldo) para realizar compras. Quando um cliente compra um produto, o sistema subtrai o preço do produto do saldo da carteira.

# Lógica Vulnerável:

O código do sistema utiliza um tipo de dado unsigned int para armazenar o saldo do cliente. O problema é que um unsigned int não pode ser negativo. A lógica do sistema é a seguinte:

- código em C++ - carteira_digital.cpp


O desenvolvedor assume que a verificação saldo_cliente >= preco_produto é suficiente para evitar problemas.

# O Ataque:

Um atacante, ciente de que o saldo é um unsigned int, compra um produto que custa, digamos, R$ 50,00.

Saldo inicial do atacante: R$ 100,00.

Preço do produto: R$ 50,00.

O atacante compra o produto, e o saldo se torna R$ 50,00.

Agora, o atacante manipula o valor do preço do produto para um valor muito alto, usando alguma falha na comunicação ou na interface do sistema. Ele faz o sistema acreditar que o preço do produto é um número tão grande que causará um integer overflow na subtração.

Por exemplo, ele pode conseguir que o sistema interprete o preço do produto como 200.

Saldo do atacante: R$ 50,00.

Preço "manipulado" do produto: R$ 200,00.

O código vulnerável faria a seguinte operação:

saldo_cliente = 50 - 200

Como saldo_cliente é um unsigned int, a subtração não resulta em -150. Em vez disso, o valor "dá a volta" e se torna um número positivo muito grande (por exemplo, 4.294.967.146 em um sistema de 32 bits).

# Conclusão:

A verificação de segurança if (saldo_cliente >= preco_produto) falha. O atacante consegue enganar o sistema para processar a compra, e como resultado do integer overflow, o saldo da sua carteira se torna um valor enorme, concedendo-lhe um "crédito" virtual, que pode ser usado para comprar outros produtos ou até mesmo ser sacado em alguns sistemas.


# A Solução com um Controle de Segurança:

A prevenção deste ataque é simples, mas crucial:

Usar tipos de dados assinados (int ou long) para valores que podem se tornar negativos. Isso faz com que a verificação saldo_cliente >= preco_produto funcione corretamente, impedindo que a transação ocorra se o saldo for insuficiente.

Implementar verificações de overflow antes da operação. Em linguagens que não oferecem proteção nativa, o código deve verificar se a operação resultará em um valor fora do limite do tipo de dados. 

Ex: if (preco_produto > saldo_cliente) { // Tratar como saldo insuficiente }.