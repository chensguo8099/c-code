CC=g++
FLAG=-c
OUTPUT=-o
ALL=gcsort.o generate_data.o test_generate_data.o test_gcsort.o libgtest.a -lpthread
OBJ=test

$(OBJ):$(ALL)
	$(CC) $^  $(OUTPUT) $@ 
%.o:%.c
	$(CC) $(FLAG) $< $(OUTPUT) $@

.PHONY:clean
clean:
	@rm -rf *.o test
	@echo "del ok"
	

#	$@  代表当前规则的目标文件
#	$<  代表当前规则的第一个依赖文件
#	$^  代表当前规则的所有依赖文件

#main.o:main.c
#	$(CC) $(FLAG) $< $(OUTPUT) $@ 


