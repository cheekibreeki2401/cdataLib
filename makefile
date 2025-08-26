AR = ar
CFLAGS = -Wall -Wextra -O2
PICFLAG = -fPIC
SRC = src/cdata.c src/cdataframe.c
OBJ = $(SRC:.c=.o)
PICOBJ = $(SRC:.c=.pic.o)
CC = gcc
CC_WIN64 = x86_64-w64-mingw32-gcc
CC_WIN32 = i686-w64-mingw32-gcc

all: linux win32 win64

linux: compiledLibs/static/cdata.a compiledLibs/static/cdataframe.a compiledLibs/shared/cdata.so compiledLibs/shared/cdataframe.so

compiledLibs/static/cdata.a: src/cdata.o
	$(AR) rcs $@ $^

compiledLibs/static/cdataframe.a: src/cdataframe.o
	$(AR) rcs $@ $^

compiledLibs/shared/cdata.so: src/cdata.pic.o src/cdataframe.pic.o
	$(CC) -shared -o $@ $^

compiledLibs/shared/cdataframe.so: src/cdataframe.pic.o
	$(CC) -shared -o $@ $^

src/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

src/%.pic.o: src/%.c
	$(CC) $(CFLAGS) $(PICFLAG) -c $< -o $@

win64: compiledLibs/static/cdata64.lib compiledLibs/static/cdataframe64.lib compiledLibs/shared/cdata64.dll compiledLibs/shared/cdataframe64.dll
win32: compiledLibs/static/cdata32.lib compiledLibs/static/cdataframe32.lib compiledLibs/shared/cdata32.dll compiledLibs/shared/cdataframe32.dll

compiledLibs/static/cdata64.lib: src/cdata.win64.o
	$(AR) rcs $@ $^

compiledLibs/static/cdataframe64.lib: src/cdataframe.win64.o
	$(AR) rcs $@ $^

compiledLibs/static/cdata32.lib: src/cdata.win32.o
	$(AR) rcs $@ $^

compiledLibs/static/cdataframe32.lib: src/cdataframe.win32.o
	$(AR) rcs $@ $^

compiledLibs/shared/cdata64.dll: src/cdata.win64.pic.o src/cdataframe.win64.pic.o
	$(CC_WIN64) -shared -o $@ $^

compiledLibs/shared/cdataframe64.dll: src/cdataframe.win64.pic.o
	$(CC_WIN64) -shared -o $@ $^

compiledLibs/shared/cdata32.dll: src/cdata.win32.pic.o src/cdataframe.win32.pic.o
	$(CC_WIN32) -shared -o $@ $^

compiledLibs/shared/cdataframe32.dll: src/cdataframe.win32.pic.o
	$(CC_WIN32) -shared -o $@ $^

src/%.win64.o: src/%.c
	$(CC_WIN64) $(CFLAGS) -c $< -o $@

src/%.win32.o: src/%.c
	$(CC_WIN32) $(CFLAGS) -c $< -o $@

src/%.win64.pic.o: src/%.c
	$(CC_WIN64) $(CFLAGS) $(PICFLAG) -c $< -o $@

src/%.win32.pic.o: src/%.c
	$(CC_WIN32) $(CFLAGS) $(PICFLAG) -c $< -o $@

clean:
	rm -f src/*.o src/*.pic.o src/*.a src/*.so src/*.lib src/*.dll src/*.win32.o src/*.win64.o src/*.win32.pic.o src/*.win64.pic.o
