# Compila para um arquivo objeto 
# fPIC cria um endereço de memoria independente do arquivo que chama a biblioteca
gcc -c -fPIC fibonacci.c -o fibonacci.o
# Cria a biblioteca compartilhada 
gcc -shared fibonacci.o -o libfibonacci.so 
# Cria o arquivo objeto do main
gcc -c main.c -o main.o
# Une o arquivo obeto com a biblioteca
gcc main.o -L. -lfibonacci -o main
# Como o dll não está em uma pasta padrão roda-se com o comando
#LD_LIBRARY_PATH=. ./main