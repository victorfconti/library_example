# Compila para um arquivo objeto 
# fPIC cria um endereço de memoria independente do arquivo que chama a biblioteca
gcc -c -fPIC binary.c -o binary.o
gcc -c -fPIC text.c -o text.o
# Cria a biblioteca compartilhada 
gcc -shared binary.o -o libbinary.so 
gcc -shared text.o -o libtext.so 
# Cria o arquivo objeto do main
gcc main.c -ldl -o main
# Como o dll não está em uma pasta padrão roda-se com o comando
#LD_LIBRARY_PATH=. ./main