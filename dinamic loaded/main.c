#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include "file_read.h" //Nesse caso não precisa, mas continua sendo uma boa pratica

//Obtem um ponteiro de função para a função da biblioteca compartilhada
void* obtemPonteiroFuncao(void* lib, const char* funcName) {
    void* fptr = dlsym(lib, funcName);
    if (!fptr) {
      fprintf(stderr, "Could not get function pointer for %s\n  error is: %s\n\n", funcName, dlerror());
      return NULL;
    }
    return fptr;
}

//Executa a função compartilhada
char* obtemTexto(char* libraryName){
    char* (*readFile)();
    void* lib = dlopen(libraryName,  RTLD_LAZY | RTLD_GLOBAL);

    if (!lib) {
        //Não conseguiu abrir a biblioteca
        fprintf(stderr, "Não pode abrir %s", libraryName);
        exit(1);
    }

    readFile = obtemPonteiroFuncao(lib, "readFile");
    return readFile();
}

int main(int argc, char** argv){
    
    for(int i = 0; i < 4; i++){
        if(i%2){
            printf("%s\n", obtemTexto("libtext.so"));
        }else{
            printf("%s\n", obtemTexto("libbinary.so"));
        }
    }

    return 0;
}
