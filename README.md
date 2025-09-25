# secure_software_development
Secure Software Development

A seguir um conjuntos de exemplos sobre ataques e vulnerabilidades em desenvolvimento de software.

# Example 01

# XSS Persistente
Estudo de caso de vulnerabilidade em formulários de comentários em que é demonstrado o ataque de XSS persistente. Para testar o exemplo, será necessário simular um ambiente de uma aplicação web vulnerável.

Conclusão:

Este estudo de caso demonstra como a ausência de um controle de segurança simples, como a validação e sanitização de entrada, pode levar a uma vulnerabilidade crítica de XSS. A implementação desse controle em uma fase inicial de desenvolvimento (no SSDLC) é uma prática de baixo custo e alta eficácia para proteger os usuários e a integridade da aplicação.

# Example 02

# buffer overflow - função strcpy

Para ilustrar a vulnerabilidade de buffer overflow, aqui está um exemplo de código em C++ que utiliza a função strcpy de forma insegura.


# Example 03 

# buffer overflow - Substituir a função strcpy pela função snprintf 

Para ilustrar a vulnerabilidade de buffer overflow, aqui está um exemplo de código em C++ que utiliza a função snprintf ao invés da funçãostrcpy de forma a corrigir o problema de buffer overflow.


# Example 04

# Integer Overflow

O Integer Overflow (Estouro de Inteiro) ocorre quando o resultado de uma operação aritmética (como adição, multiplicação ou subtração) excede o valor máximo que o tipo de dado pode conter. Em vez de simplesmente gerar um erro, o valor "dá a volta" (wraps around) para o seu valor mínimo.

# Example 05

# Comparação de Funções de Cópia de String

Para demonstrar a diferença entre funções de manipulação de strings inseguras e seguras, vamos comparar um trecho de código vulnerável usando strcpy com uma versão corrigida usando strncpy_s.

# Example 06

# HTML Injection em Formulário de Feedback

Ilustrar como o HTML Injection funciona, vamos ver um exemplo de código vulnerável e como a injeção pode alterar o layout de uma página. 

# Example 07

# Ataques de Cross-Site Scripting (XSS)

O script JavaScript para roubar cookies é uma das cargas úteis (payloads) mais comuns em ataques de Cross-Site Scripting (XSS). O script a seguir, quando injetado e executado no navegador de uma vítima, faz uma requisição HTTP para um servidor controlado pelo atacante, enviando os cookies da vítima.


# Example 08

# CSRF com Requisições Forjadas

Para demonstrar como um ataque de CSRF pode ser executado, aqui estão exemplos de código malicioso que um atacante poderia usar. O objetivo é forçar o navegador da vítima a realizar uma ação em um site legítimo sem o consentimento dela.


# Example 09

# Exemplo de SQL Injection com Código e Injeção

Para ilustrar o perigo da concatenação de strings em consultas SQL, aqui está um exemplo prático de uma consulta vulnerável e como um atacante pode injetar código malicioso para burlar a autenticação.