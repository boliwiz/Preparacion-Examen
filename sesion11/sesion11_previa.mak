#############################################################################
#
# METODOLOGIA DE LA PROGRAMACION
# GRADO EN INGENIERIA INFORMATICA
#
# CURSO 2019-2020
# (C) FRANCISCO JOSE CORTIJO BON
# DEPARTAMENTO DE CIENCIAS DE LA COMPUTACION E INTELIGENCIA ARTIFICIAL
#
# sesion11_previa.mak
#
# makefile para la sesión de prácticas 11 (previa, para alumnos)
#
#############################################################################

SESION = 11

HOME = .
HOME_CLASES_UTILS = .

BIN = $(HOME)/bin
SRC = $(HOME)/src
OBJ = $(HOME)/obj
LIB = $(HOME)/lib
INCLUDE = $(HOME)/include

SRC_CLASES_UTILS =  $(HOME_CLASES_UTILS)/src
OBJ_CLASES_UTILS =  $(HOME_CLASES_UTILS)/obj
LIB_CLASES_UTILS =  $(HOME_CLASES_UTILS)/lib
INCLUDE_CLASES_UTILS = $(HOME_CLASES_UTILS)/include

#................................................
all:  preambulo \
      $(BIN)/IV_Demo-Secuencia \
      final

#................................................
preambulo:
	@echo
	@echo ------------------------------------------------------------
	@echo Ejercicios de la Relación de Problemas II
	@echo Sesion de practicas $(SESION)	
	@echo
	@echo METODOLOGÍA DE LA PROGRAMACIÓN
	@echo Grado en Ingeniería Informática
	@echo
	@echo "("c")" Francisco José CORTIJO BON
	@echo Depto. Ciencias de la Computación e Inteligencia Artificial
	@echo Universidad de Granada
	@echo ------------------------------------------------------------
	@echo

#................................................
final: 
	@echo

#................................................
# EJECUTABLES

$(BIN)/IV_Demo-Secuencia : \
              $(OBJ)/IV_Demo-Secuencia.o \
              $(LIB)/libSecuencia.a
	@echo 
	@echo Creando ejecutable: IV_Demo-Secuencia
	@echo 
	g++ -o $(BIN)/IV_Demo-Secuencia \
         $(OBJ)/IV_Demo-Secuencia.o -L$(LIB) -lSecuencia

#................................................
# OBJETOS 

$(OBJ)/IV_Demo-Secuencia.o : \
              $(SRC)/IV_Demo-Secuencia.cpp \
              $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: IV_Demo-Secuencia.o
	@echo
	g++ -c -o $(OBJ)/IV_Demo-Secuencia.o $(SRC)/IV_Demo-Secuencia.cpp  \
        -I$(INCLUDE) -std=c++11


#................................................
# BIBLIOTECAS


# (Secuencia) ........................
 
$(OBJ)/Secuencia.o : $(SRC)/Secuencia.cpp \
                     $(INCLUDE)/Secuencia.h $(INCLUDE)/TipoBase_Secuencia.h
	@echo 
	@echo Creando objeto: Secuencia.o
	@echo  
	g++ -c -o $(OBJ)/Secuencia.o  $(SRC)/Secuencia.cpp \
       -I$(INCLUDE) -std=c++11

$(LIB)/libSecuencia.a : $(OBJ)/Secuencia.o
	@echo 
	@echo Creando biblioteca: libSecuencia.a 
	@echo  
	ar rvs $(LIB)/libSecuencia.a  $(OBJ)/Secuencia.o


#................................................
# LIMPEZA

clean: clean-objs clean-libs

clean-objs: clean-objetos-bibliotecas

	@echo Borrando objetos de la sesion de practicas $(SESION)...

	-rm $(OBJ)/IV_Demo-Secuencia.o

	@echo ...Borrados objetos de la sesion de practicas $(SESION)
	@echo 

clean-objetos-bibliotecas: 
	@echo Borrando objetos usados en bibliotecas de la Sesión $(SESION)......

	-rm $(OBJ)/Secuencia.o 

	@echo ...Borrados
	@echo 

clean-libs: 
	@echo Borrando bibliotecas de la sesion de practicas $(SESION)...

	-rm $(LIB)/libSecuencia.a

	@echo ...Borradas bibliotecas de la sesion de practicas $(SESION)
	@echo 

clean-bins : 
	@echo Borrando ejecutables de la sesion de practicas $(SESION)...

	-rm $(BIN)/IV_Demo-Secuencia
	
	@echo ...Borrados ejecutables de la sesion de practicas $(SESION)

mr.proper:  clean-objs clean-libs clean-bins

