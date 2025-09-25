# Estudo de Caso: Ataques de Cross-Site Scripting (XSS)

O script JavaScript para roubar cookies é uma das cargas úteis (payloads) mais comuns em ataques de Cross-Site Scripting (XSS). O script a seguir, quando injetado e executado no navegador de uma vítima, faz uma requisição HTTP para um servidor controlado pelo atacante, enviando os cookies da vítima.

# Código de Exemplo de Script de XSS para Roubo de Cookies

arquivo - script_roubo_cookies.html

# Como a injeção funciona:

A função document.cookie acessa todos os cookies de sessão que não estão marcados com a flag HttpOnly.

O script usa a função fetch() para fazer uma requisição HTTP GET para um servidor externo (http://servidor-do-atacante.com).

O valor dos cookies da vítima é adicionado como um parâmetro (cookie=...) na URL da requisição.

O servidor do atacante recebe a requisição e salva o valor do cookie em um arquivo de log ou banco de dados.

Com o cookie em mãos, o atacante pode usá-lo para sequestrar a sessão da vítima e se passar por ela na aplicação web, obtendo acesso não autorizado à sua conta.

# Nota:

Um script de XSS mais simples, como alert(document.cookie), serve apenas para demonstrar a vulnerabilidade, exibindo os cookies em uma janela pop-up, mas não é usado para roubo de dados em um ataque real.