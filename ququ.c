#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void	usage(void);

int
main(int argc, char *argv[])
{
	int c, n;
	FILE *fp;

	n = 1;
	while ((c = getopt(argc, argv, "+n:")) != -1)
		switch (c) {
		case 'n':
			n = atoi(optarg);
			break;
		case '?':
		default:
			usage();
			/* NOTREACHED */
		}
	argc -= optind;
	argv += optind;

	do {
		if (argc == 0 || strcmp(*argv, "-") == 0)
			fp = stdin;
		else
			fp = fopen(*argv, "r");
		if (fp == NULL)
			err(1, "%s", *argv);

		while ((c = getc(fp)) != EOF)
			if (putchar(n < 0 ? c << -n : c >> n) == EOF)
				err(1, "stdout");

		if (fp != stdin)
			fclose(fp);
	} while (++argv, --argc > 0);

	return 0;
}

static void
usage(void)
{
	fprintf(stderr, "usage: ququ [-n number] [files ...]\n");
	exit(1);
}
