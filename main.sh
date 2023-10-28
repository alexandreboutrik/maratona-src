#!/bin/bash

Exit() {
	rm -rf ./bin
	exit
}

Print() {
	color=$1
	shift
	echo -e "\e[${color};1m $*\e[0m"
}

CheckError() {
	if [ $1 -ne 0 ]; then
		shift
		Print 31 - $*
		Exit
	fi
}

LS_CMD="ls -1 --color=no"

if [ $# -eq 0 ]; then
	read -p "Digite a maratona: " maratona
	shift
else
	maratona=$1
	shift
fi

if [ $# -eq 0 ]; then
	read -p "Digite o identificador do problema: " problem
else
	problem=$1
fi

DIRM=$(${LS_CMD} | grep "${maratona}")
CheckError $? Maratona "${maratona}" não encontrado

DIRP=$(${LS_CMD} ${DIRM} | grep "${problem}-")
CheckError $? Problema "${problem}" não encontrado

DIRC=${DIRM}/${DIRP}
DIRT=${DIRC}/test

if [ ! -d ./bin ]; then
	mkdir ./bin
	CheckError $? Erro ao criar o diretório ./bin
fi

Print 34 \* Compilando o código \(${DIRP}/src.c\)
gcc ${DIRC}/src.c -o ./bin/exe -lm
CheckError $? Erro de compilação

LISTA_IN=$(${LS_CMD} ${DIRT} | grep "input")
CheckError $? Nenhum caso de teste encontrado

LISTA_OUT=$(${LS_CMD} ${DIRT} | grep "output")
CheckError $? Nenhuma resposta para os casos de teste encontrado

QNT_IN=$(echo "${LISTA_IN}" | wc -l)
QNT_OUT=$(echo "${LISTA_OUT}" | wc -l)

if [ "${QNT_IN}" != "${QNT_OUT}" ]; then
	CheckError 1 Incongruência: quantidade de input diferente de output
fi

i=1
while [ $i -le ${QNT_IN} ]; do
	FILE_IN=$(echo "${LISTA_IN}" | head -$i | tail -1)
	FILE_OUT=$(echo "${LISTA_OUT}" | head -$i | tail -1)

	EXPECTED=$(cat "${DIRT}/${FILE_OUT}")
	CheckError $? Não foi possível ler o arquivo ${FILE_OUT}

	Print 34 \* Testando o código com ${FILE_IN}

	RESULT=$(cat ${DIRT}/${FILE_IN} | ./bin/exe)
	CheckError $? Erro ao testar o código com a entrada de "${FILE_IN}"

	if [ "${EXPECTED}" != "${RESULT}" ]; then
		Print 33 × Incorreto
		Print 0 =====
		Print 0 Saída esperada:
		Print 0 =====
		echo "${EXPECTED}"
		Print 0 =====
		Print 0 Saída do código:
		Print 0 =====
		echo "${RESULT}"
		Print 0 =====
	else
		Print 32 ! Correto
	fi

	true $((i = i + 1))
done

Exit
