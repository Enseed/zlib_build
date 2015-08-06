// test.cpp : Defines the entry point for the console application.
//

#include <zlib.h>
#include <cstdio>
#include <cstring>
int main()
{
	gzFile wfile = gzopen("test.gz", "w");
	const char hello[] = "hello world!!!";
	gzwrite(wfile, hello, sizeof(hello)-1);
	gzclose(wfile);

	gzFile rfile = gzopen("test.gz", "r");
	char buf[sizeof(hello)] = { 0 };
	gzread(rfile, buf, sizeof(hello) - 1);
	if (strcmp(buf, hello) == 0)
		printf("SUCCESS\n");
	else
		printf("FAILURE\n");
	
	return 0;
}

