.PHONY: test
test:
	mkdir -p bin
	cc -std=c99 -Wall test/test.c test/unity/unity.c -o bin/run-test
	bin/run-test
