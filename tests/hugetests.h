#ifndef _HUGETESTS_H
#define _HUGETESTS_H

#define DEBUG

/* Test return codes */
#define RC_PASS 	0
#define RC_CONFIG 	1
#define RC_FAIL		2

extern int verbose_test;
extern char *test_name;
void test_init(int argc, char *argv[]);
int test_addr_huge(void *p);

#define ALIGN(x, a)	(((x) + (a) - 1) & ~((a) - 1))

/* Each test case must define this function */
void cleanup(void);

#define verbose_printf(...) \
	if (verbose_test) \
		printf(__VA_ARGS__)
#define ERR	"ERR: "
#define ERROR(fmt, args...)	fprintf(stderr, ERR fmt, ## args)
#define PERROR(x)		perror(ERR x)


#define	PASS()						\
	do {						\
		cleanup();				\
		printf("PASS\n");			\
		exit(RC_PASS);				\
	} while (0)

#define IRRELEVANT()					\
	do {						\
		cleanup();				\
		printf("PASS (irrelevant)\n");		\
		exit(RC_PASS);				\
	} while (0)

#define FAIL(s)						\
	do {						\
		cleanup();				\
		printf("FAIL\t%s\n", s);		\
		exit(RC_FAIL);				\
	} while (0)

#define _FAIL()					\
	do {					\
		printf("FAIL\n");		\
		exit(RC_FAIL);			\
	} while (0)

#define CONFIG()					\
	do {						\
		cleanup();				\
		printf("Bad configuration\n");	\
		exit(RC_CONFIG);			\
	} while (0)

#endif /* _HUGETESTS_H */
