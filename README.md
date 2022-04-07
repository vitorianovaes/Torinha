
<h3 align="center">
    📡 Projeto da Torinha 😼

Tabela de conteúdos
=================
<!--ts-->
   * [Sobre o projeto](#-sobre-o-projeto)
   * [Funcionalidades](#-funcionalidades)
   * [Como executar o projeto](#-como-executar-o-projeto)
     * [Pré-requisitos](#pré-requisitos)

## 💻 Sobre o projeto

📡 Esse projeto de circuito de comunicação wireless foi desenvolvido para o desafio da Tractian; Tem como objetivo enviar um arquivo de 500kb a partir de um espaço aberto de 100m usando uma bateria. 
  
## ⚙️ Componentes 
  
  -> Placa de Transmissão: <br>
     - Transmissor RF 433 mhz: foi escolhido porque é fácil de encontrar em lojas, é barato e opera entre 0m-150m; <br>
     - Bateria; <br>
     - ATMEGA 328P: foi escolhido pela praticidade e custo benefício. O ATMEGA é pequeno em relação ao Arduíno, economizando espaço e portas, apesar de usarem a mesma tecnologia; <br>
     - Resistor: para o LED e bateria; <br>
     - Cartão SD: foi escolhido pela facilidade de operação; <br>
     - Botão de enviar (Push Button); <br>
     - Botão de Liga/Desliga (Switch); <br>
     - LED 5mm: para mostrar ao usuário que o arquivo foi enviado corretamente; <br>
  
  -> Placa de Recepção:
     - Receptor RF 433 mhz; <br>
     - Bateria; <br>
     - ATMEGA 328P; <br>
     - Resistor; <br>
     - Cartão SD; <br>
     - LED; <br>
     - Botão Liga/Desliga; <br>


## ⚙️ Funcionalidades

- [x] Consegue enviar um arquivo 500kb entre 0m-150m;

## 🚀 Como executar o projeto

Este projeto é divido em duas partes:
1. Hardware
2. Firmware <br>
    
    Hardware: schematic e PCB; <br>
    Firmware: a lógica do código fonte é colocar um SD card contendo o arquivo (nomeado BOB.txt) a ser mandado via rádio frequência. O microcontrolador lê o arquivo e o usuário ao pressionar o Push Button inicia o envio do arquivo. Se o arquivo for enviado corretamente o LED irá piscar três vezes. Para se certificar de que todo o arquivo foi enviado, o buffer é limpo e um sinal de Carriage Return (\r) é enviado para o Receptor, onde o LED vai piscar três vezes para confirmar o recebimento do arquivo.


### Pré-requisitos

Antes de começar, você vai precisar ter instalado em sua máquina a seguinte ferramenta:
[Eagle](https://www.autodesk.com/products/eagle/free-download).
Além disto é bom ter um editor para trabalhar com o código como [VSCode](https://code.visualstudio.com/)

Feito com ❤️ por Torinha 😼
