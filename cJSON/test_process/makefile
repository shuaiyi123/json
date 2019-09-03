CC =gcc
#CC =arm-linux-gnueabihf-gcc

INCLUDE     = -I./include  #-I表示头文件位置
#LIB_DIR     = -L./zlog/lib
LIBS        = -lpthread -lrt  #链动态库
#STATIC_LIBS = -static -L. -lcjson  #-L表示库文件位置，链接静态库
CFLAGS      = -Wall -g
OBJS        = gstruct.o gshm.o test.o
TARGET      = test.app

all : $(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $^ $(STATIC_LIBS) $(LIB_DIR) $(LIBS) 

%.o:%.c 
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDE)

.PHONY: all clean
clean:
	rm -rf $(TARGET) *.o 