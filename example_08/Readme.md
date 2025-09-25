# Estudo de Caso: CSRF com Requisições Forjadas

Para demonstrar como um ataque de CSRF pode ser executado, aqui estão exemplos de código malicioso que um atacante poderia usar. O objetivo é forçar o navegador da vítima a realizar uma ação em um site legítimo sem o consentimento dela.

# 1. Ataque usando uma Tag <img> (Simples e comum)

Este é um método muito comum para ataques CSRF, pois a maioria dos navegadores e clientes de e-mail carregam imagens automaticamente. O atacante pode incorporar esta tag em um e-mail ou em um site malicioso.

<img src="http://banco-online.com/transferencia?conta_destino=987654321&valor=1000"
     style="display: none;" />

# Como funciona: 
O navegador da vítima, ao tentar carregar a imagem (<img src="...">), envia uma requisição GET para a URL fornecida. Se o usuário estiver autenticado no banco-online.com, o navegador inclui automaticamente o cookie de sessão válido. O servidor do banco, ao receber esta requisição GET, assume que é legítima e executa a transferência de R$ 1.000 para a conta do atacante (987654321). O atributo style="display: none;" é usado para tornar a imagem invisível, para que a vítima não perceba o que está acontecendo.



# 2. Ataque usando um Formulário Oculto (Mais versátil)

Este método é usado quando a aplicação alvo espera uma requisição POST, que não pode ser facilmente forjada com uma tag <img>. O atacante cria um formulário oculto em seu próprio site e usa JavaScript para enviá-lo automaticamente quando a página é carregada.

arquivo - example_02.html

# Como funciona: 

Quando a vítima visita a página, o JavaScript executa o comando submit() no formulário oculto. O navegador envia uma requisição POST para loja-online.com/alterar_senha com a nova senha do atacante. O cookie de sessão da vítima é anexado à requisição. O servidor da loja, ao receber o POST com um cookie válido, processa a alteração de senha. O atacante agora tem acesso à conta da vítima.

Ambos os exemplos demonstram como o CSRF se aproveita da confiança do navegador na sessão do usuário. A defesa, como mencionado, é a implementação de tokens anti-CSRF para garantir que a requisição seja originada pela aplicação legítima.