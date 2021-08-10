# Compila para um arquivo objeto
gcc -c fibonacci.c -o fibonacci.o
# Une um ou vários arquivos objetos em uma biblioteca estática 
ar rcs libfibonacci.a fibonacci.o 
# Cria o arquivo objeto do main
gcc -c main.c -o main.o
# Une o arquivo obeto com a biblioteca
gcc -static main.o -L. -lfibonacci -o main