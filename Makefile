WORKDIR := $(shell pwd)

TARGET := liblogger.so
SRC := $(wildcard $(WORKDIR)/src/*.c)

CFLAG := -Werror -Wall -fPIC
CFLAG += -I$(WORKDIR)/inc -I$(WORKDIR)/inc/priv

all:$(TARGET) test

$(TARGET):$(SRC)
	$(CC) $(CFLAG) $^ -shared -o $@

test:
	$(MAKE) -C test

clean:
	rm $(TARGET)
	$(MAKE) -C test clean

.PHONY: all clean test