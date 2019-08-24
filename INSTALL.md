# Instruções para compilação e execução do programa

## Compilação
 * Após fazer o download do arquivo "incp.c" localizado nesse repositório, deve-se usar o terminal do linux e através dele achar o diretório do arquivo baixado, isso pode ser feito através do comando: "cd", onde após o comando deve-se especificar a localização do arquivo. 
 * Quando estiver na pasta com o arquivo use o comando:
 ```
 gcc incp.c -o incp
 ```
 * Após isso será gerado o binário do código fonte, que estará pronto para ser execultado.


## Execução
 Com o arquivo binário pronto, é possível execultá-lo no terminal de duas maneiras:
 - com o comando ./incp cpu , que irá monitorar o uso percentual da cpu;
 - com o comando ./incp cpu_mem , que irá monitorar o uso da cpu e a alocação da memória;
 Quando tiver achado suficiente a execução basta pressionar ctrl + c para interrompê-la.
