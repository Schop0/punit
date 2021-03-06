// Peter's unit testing framework for C

#ifndef PUNIT
#define PUNIT

#include <stdio.h>

extern int tests_run;
extern int tests_failed;
extern int asserts_failed;	// Gets reset by TEST()

#define ASSERT(msg,condition)	\
do{ \
	if (!(condition)) { \
		if (!asserts_failed) { \
			printf("FAIL\n"); \
		} \
		printf("%s\n", msg); \
		asserts_failed++; \
	}; \
} while(0)

#define TEST(name,test)	\
do{ \
	tests_run++; \
	printf("%d: %s... ", tests_run, name); \
	asserts_failed = 0; \
	test(); \
	if (asserts_failed) { \
		tests_failed++; \
	} else { \
		printf("OK\n"); \
	}; \
} while(0)

#endif
