# Estudo de Caso: HTML Injection em Formulário de Feedback

Para ilustrar como o HTML Injection funciona, vamos ver um exemplo de código vulnerável e como a injeção pode alterar o layout de uma página. 

*** Para rodar os testes, será necessário um Servidor Web.

# 1. Código Vulnerável (HTML e Lógica)

Imagine uma página de feedback com um formulário simples. A página de agradecimento, que exibe os dados do usuário, é onde a vulnerabilidade se manifesta.

arquivo:  feedback.html

Lógica de processamento (Exemplo simplificado):

O servidor recebe o nome do usuário e a mensagem. Em seguida, ele gera uma página de resposta agradecimento.html que insere esses dados diretamente.

arquivo:  agradecimento.html

# 2. O Ataque (Injeção de Código)

Um atacante fornece o seguinte conteúdo malicioso no campo "Nome":

Conteúdo Injetado:

<img src="http://site-atacante.com/logo-falsa.png"><h1>Feedback Recebido!</h1>


# 3. O Resultado (Página Alterada)

Quando o servidor processa essa entrada sem sanitizá-la, a página de agradecimento se torna:

<h1>Obrigado por seu feedback!</h1>
<p>Nome: <img src="http://site-atacante.com/logo-falsa.png"><h1>Feedback Recebido!</h1></p>
<p>Mensagem: [Aqui a mensagem do usuário é inserida]</p>


O navegador renderiza a página de forma inesperada. O texto original "Nome: " some, e a imagem maliciosa é exibida. O texto "Feedback Recebido!" é exibido como um título grande (<h1>), alterando completamente o layout e o contexto da página. O atacante pode usar isso para realizar um ataque de phishing (enganando o usuário) ou simplesmente para desfigurar o site.

Como a injeção funciona: A tag <h1> do atacante fecha a tag <p> que a precede, e sua própria tag de fechamento </h1> fecha o título. O navegador tenta corrigir o HTML quebrado, mas ainda renderiza as tags injetadas, causando o defacing.


# 4. A Solução com um Controle de Segurança

A solução para esta vulnerabilidade é o Output Encoding. Antes de exibir qualquer dado de entrada do usuário, o servidor deve codificar caracteres especiais de HTML, como <, >, ", ' e &, em suas entidades HTML correspondentes (&lt;, &gt;, &quot;, &#39;, &amp;).

# Código de Saída Corrigido:

arquivo:  agradecimento_seguro.html

Com a saída sanitizada, o navegador interpreta o conteúdo injetado como texto literal, exibindo-o na tela exatamente como o atacante o digitou, sem renderizar as tags. Isso impede que o ataque tenha sucesso. 