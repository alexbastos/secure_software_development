# Exploração Detalhada: SQL Injection (SQLi)

# Exemplo de SQL Injection com Código e Injeção

Para ilustrar o perigo da concatenação de strings em consultas SQL, aqui está um exemplo prático de uma consulta vulnerável e como um atacante pode injetar código malicioso para burlar a autenticação.

# 1. Código Vulnerável (Pseudocódigo)

Considere um trecho de código que lida com um formulário de login. A aplicação pega a entrada do usuário e constrói a consulta SQL diretamente, sem qualquer tipo de sanitização ou validação.

// Entrada do usuário (vinda de um formulário de login)
user_input = "alberto"
pass_input = "minhasenha123"

// Consulta SQL vulnerável, construída por concatenação de strings
query = "SELECT * FROM users WHERE username = '" + user_input + "' AND password = '" + pass_input + "';"
Neste cenário normal, a consulta gerada seria:

SELECT * FROM users WHERE username = 'alberto' AND password = 'minhasenha123';

Se o nome de usuário e a senha corresponderem a uma entrada no banco de dados, o login será bem-sucedido.

# 2. O Ataque (Injeção de Código)

Agora, vamos ver o que acontece quando um atacante fornece uma entrada maliciosa. O atacante não sabe a senha do usuário alberto, mas ele sabe que a consulta SQL é vulnerável.

Entrada do Atacante:

user_input = "alberto"

pass_input = "' OR 1=1 -- "

Quando o servidor concatena essa entrada na consulta, ela se torna:

SELECT * FROM users WHERE username = 'alberto' AND password = '' OR 1=1 -- ';

# 3. Análise da Consulta Injetada

Vamos quebrar a consulta gerada para entender como ela funciona:

SELECT * FROM users WHERE username = 'alberto' AND password = ''

Esta primeira parte da consulta tenta encontrar um usuário com o nome alberto e uma senha vazia, o que provavelmente falhará.

OR 1=1

Esta é a parte crítica da injeção. A condição 1=1 é sempre verdadeira. Isso faz com que a cláusula WHERE inteira seja avaliada como verdadeira, independentemente da senha correta.

-- '

O -- é um comentário em SQL. Ele faz com que o restante da consulta original (o ' que fecharia a string) seja ignorado pelo banco de dados.

# Resultado:

O banco de dados executa a consulta injetada, que retorna o primeiro usuário da tabela (geralmente o usuário alberto). O atacante consegue ignorar a autenticação e fazer o login como alberto sem saber a senha, demonstrando a vulnerabilidade do sistema.

