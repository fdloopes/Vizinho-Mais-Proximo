#
# File: Makefile
# Author: Felipe Lopes
# Created on 25 de Junho de 2016, 20:00
#

MAKEFLAGS += --silent
all: main clean
main:
	# Compila o programa
	g++ main.cpp -o main

	# executa o programa com arquivo de entrada default com 3 vertices, mas contendo 100 vertices
	./main entrada.txt 

	# Para remover o executavel basta make clean
clean:
	-rm -f main