WORKDIR := $(shell pwd)

TARGET := logger_test
SRC := test_main.c

CFLAG := -Wall \
		 -I$(WORKDIR)/../inc \
		 -Wl,-rpath,$(WORKDIR)/../
LDFLAG := -L$(WORKDIR)/../ -llogger

all:$(TARGET)

$(TARGET):$(SRC)
	$(CC) $(CFLAG) $^ -o $@ $(LDFLAG)

clean:
	rm $(TARGET)

.PHONY: all clean