# UDESC-LPG-TC3

Este programa foi desenvolvido durante a disciplina de Linguagem de Programação, no curso de Ciência da Computação na UDESC (2021/2) por [Pedro Fernandes](https://github.com/peedrofernandes) e [Vinícios Bidin](https://github.com/bidinpithecus).

## Resumo

Rodando no terminal, o programa é um sisteminha simples de criação, exclusão e busca de registros com vários dados.

## Instruções

Quer rodar o programa na sua máquina? Siga os passos a seguir:

1. Como o programa é em linguagem C, você precisará ter o compilador GNU de C - o [GCC](https://gcc.gnu.org/install). Você pode verificar a existência ou não desse compilador no seu computador rodando o seguinte comando:

> `$ gcc -v`

Se o seu terminal mostrar a versão do GCC, pode seguir os próximos passos. Caso contrário, instale-o clicanco no link acima.

2. Uma vez com o GCC instalado, clone o repositório na sua máquina em uma pasta de sua preferência com o comando:

> `$ git clone https://github.com/peedrofernandes/UDESC-LPG-TC3`

O git criará uma pasta no seu diretório corrente normalmente, com todos os arquivos fonte. Caso não queira que o git crie uma nova pasta, coloque um "`.`" no final do comando acima, dessa forma:

> `$ git clone https://github.com/peedrofernandes/UDESC-LPG-TC3 .`

3. Agora, já dentro da pasta do projeto, rode o seguinte comando:

```
$ gcc src/main.c -o main
```

Agora o programa já virou um arquivo executável. Execute-o apenas com:

```
$ ./main
```

Dessa forma, seu terminal deverá ser limpo automaticamente e seu programa começará a rodar!
  
## Funcionalidades do programa:

1. **Inserção de registros**;

2. **Remoção de registros**;

3. **Leitura de registros**;

4. **Busca dados de uma pessoa de acordo com o input do usuário**;

5. **Busca aniversariantes do mês**;

6. **Busca aniversariantes do dia**;

7. **Otimização contra desperdício de memória decorrente da inserção e remoção de registros**.

Outras características não-funcionais do programa:

1. **Multi-compatibilidade entre sistemas operacionais**;

2. **Encapsulamento forte e organização estutural do código**;

3. **Tratamento de erros e contorno de problemas como o do buffer em C**.

 O principal intuito da criação deste programa é a familiarização (dos desenvolvedores) com a linguagem C. Fique à vontade para dar sugestões de melhoria!