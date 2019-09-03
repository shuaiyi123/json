CC=gcc
AR=ar crv
#CC=arm-linux-gnueabihf-gcc
#AR=arm-linux-gnueabihf-ar crv


RM=rm -f

H_SRC=cJSON.h

C_SRC=cJSON.c

SRC_OBJ=cJSON.o
LIB_OBJ=libcjson.a

all:$(LIB_OBJ)

$(LIB_OBJ):$(SRC_OBJ)
	$(AR) $(LIB_OBJ) $(SRC_OBJ)

$(SRC_OBJ):$(C_SRC) $(H_SRC)
	$(CC) -c $(C_SRC)

clean	:
	$(RM) *.o *.a

.PHONY : clean all
