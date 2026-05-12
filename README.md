# G33_Greedy_PA_26.1

Trabalho de Projeto de Algoritmos do semestre 26.1 sobre Gananciosos.

# Alocador de rotas aéreas

*Conteúdo da Disciplina*: Greedy (Gananciosos) <br>

## Alunos

|Matrícula | Aluno |
| -- | -- |
| 23/2014404  |  [Carlos Henrique Brasil de Souza](https://github.com/Carlos-UCH) |
| 23/2014576  |  [Yogi Nam de Souza Barbosa](https://github.com/oyogi)

## Sobre

Projeto desenvolvido por alunos da Universidade de Brasília (UnB) para a disciplina de Projeto de Algoritmos. 

O projeto consiste em com dados de voos da ANAC do aeroporto de Brasília determinar a quantidade mínima de rotas aéreas que devem operar simultaneamente, garantindo a execução de todos os voos em uma data específica. 

Para isso, no algoritmo baixamos a base de dados da ANAC que disponibiliza o histórico de voos na página de dados abertos. Com os horários de partida e chegada de cada voo utilizamos o algoritmo Interval Partitioning para determinar a menor quantidade de rotas que seriam necessárias.

<div align="center">
 <figure>
  <img width="1215" height="543" alt="image" src="https://github.com/user-attachments/assets/ac78024a-16ff-4f95-8ef5-c802f7a03eb3" />
  <figcaption>Figura 1: Exemplo de Interval Partitioning. Fonte: <a href="https://www.youtube.com/watch?v=i_G8hZYcKnI">MisterCode Youtube</a></figcaption>
 </figure>
</div>

### Rotas Aéras?

Rota aérea ou aeronáutica é uma rota em que passam aviões, semelhante a uma rodovia para carros. É um corredor definido que conecta um local especificado a outro em uma altitude especificada, ao longo do qual uma aeronave que atende aos requisitos da via aérea pode ser usada.

<div align="center">
 <figure>
   <img width="1520" height="786" alt="Um avião passando numa rota aérea" src="https://github.com/user-attachments/assets/3683cf7b-1c5d-4d56-91c5-eb77ee1e959c" />
   <figcaption >Figura 2: Um avião passando numa rota aérea. Fonte: DECEA.</figcaption>  
 </figure>
</div>

Rota aeronáutica é também denominada "Rota de Navegação Aérea", que são formadas por aerovias. Essas são classificadas, no Brasil, como de baixa (L) altitude ou de alta (H) altitude. A Organização de Aviação Civil Internacional é o organismo internacional que sugere normas para os países signatários quanto às regras de tráfego aéreo.

<div align="center">
 <figure>
   <img width="1610" height="1128" alt="Rotas aéreas do Brasil" src="https://github.com/user-attachments/assets/fff6b44a-cb32-49ab-bfe3-6ba0283b4d1b" />
   <figcaption>Figura 3: Rotas aéreas do Brasil. Fonte: DECEA.</figcaption>
 </figure>
</div>

Fonte: [Rotas Aeronáuticas](https://pt.wikipedia.org/wiki/Rota_aeron%C3%A1utica)

### Simplificações

Na vida real vários aviões podem voar simultaneamente numa mesma aerovia. É a separação vertical das aeronaves, ou seja, a altitude (ou nível de voo), que garante a segurança das operações. 

Além disso, como muitas aerovias são de mão dupla, o controle de tráfego aéreo utiliza níveis de voos em altitudes pares e ímpares, dependendo da direção, para impedir que dois aviões se cruzem em direções diferentes.

Fonte: [Aerovias: quais são e como funcionam as rotas utilizadas pelos aviões](https://www.melhoresdestinos.com.br/aerovias-rotas-avioes.html)

No nosso algoritmo simplificamos para apenas um avião pode voar simultaneamente numa mesma aerovia e sem via de mão dupla.

## Link do Vídeo da Apresentação

[https://youtu.be/S29yHLG9dwk](https://youtu.be/S29yHLG9dwk)

## Instalação 

*Linguagem*: C++<br>

## Clone o repositório  

 ```sh 
git git@github.com:projeto-de-algoritmos-2026/G33_Greedy_PA_26.1.git
cd G33_Greedy_PA_26.1
 ```

### Pre-requisitos

- Ter o C++20 instalado.
- Editor de texto

## Uso

Rode no terminal: 
```sh 
g++ -O2 -std=c++20 main.cpp csv_download.cpp csv_parser.cpp -o airport
./airport
```
 - Escolha uma data válida(mês e ano)
 - Abra o arquivo .txt
 
## Screenshots

Executando o programa:

<img width="1122" height="808" alt="Executando o programa" src="https://github.com/user-attachments/assets/0aecc374-9a0b-4db5-afc1-e2e1347a52ea" />

Relatório gerado (apenas as primeiras ~20 linhas):

<img width="872" height="808" alt="Relatório gerado" src="https://github.com/user-attachments/assets/9ce02819-203c-4b33-b0e6-e474e619f029" />
