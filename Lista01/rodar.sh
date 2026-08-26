#!usr/bin/env bash

# espera um arquivo como argumento
[[ $# -ne 1 ]]  && echo "Passe o arquivo!" && exit

[[ ! -f $1 ]] && echo "O arquivo não existe" && exit 1

arquivo=$1
arquivo_exe=${arquivo%.*}

gcc $arquivo -o $arquivo_exe

./$arquivo_exe

rm $arquivo_exe

