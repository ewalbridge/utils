#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <getopt.h>

// type: global or local -t[global, local]
// count -n [n]
// format mac address -f [1,2,3,4]
// prefix -p [00:00:00]
// case -c [lower, upper]


int main(int argc, char **argv)
{
	char *tvalue = "local"; //type -t
	char *nvalue = "1"; //count -n
	char *fvalue = "1"; //format -f
	char *pvalue = NULL; //prefix -p
	char *cvalue = "lower"; //case -c
	int index;
	int c;

	char *mac_format = NULL;
	char *mac_f1 = "%c%c%c%c%c%c%c%c%c%c%c%c\n";
	char *mac_f2 = "%c%c-%c%c-%c%c-%c%c-%c%c-%c%c\n";
	char *mac_f3 = "%c%c:%c%c:%c%c:%c%c:%c%c:%c%c\n";
	char *mac_f4 = "%c%c%c%c.%c%c%c%c.%c%c%c%c\n";


	opterr = 0;
	while ((c = getopt(argc, argv, "t:n:f:p:c:")) != -1)
	{
		switch (c)
		{
		case 't':
			tvalue = optarg;
			//printf("type = %s\n", tvalue);
			break;
		case 'n':
			nvalue = optarg;
			//printf("count = %s\n", nvalue);
			break;
		case 'f':
			fvalue = optarg;
			if (fvalue == "1")
			{
				mac_format = mac_f1;
			}
			else if (fvalue == "2")
			{
				mac_format = mac_f2;
			}
			//printf("format = %s\n", fvalue);
			break;
		case 'p':
			pvalue = optarg;
			//printf("prefix = %s\n", pvalue);
			break;
		case 'c':
			cvalue = optarg;
			//printf("case = %s\n", cvalue);
			break;
			/*case '?':
				if (optopt == 'c')
				fprintf(stderr, "Option -%c requires an argument.\n", optopt);
				else if (isprint(optopt))
				fprintf(stderr, "Unknown option `-%c'.\n", optopt);
				else
				fprintf(stderr, "Unknown option character `\\x%x'.\n", optopt);
				return 1;*/
		default:
			abort();
		}
	}

	struct timeval tm;
	gettimeofday(&tm, NULL);
	srand(tm.tv_sec + tm.tv_usec * 1000000ul);

	enum { hwaddr_len = 12 };
	enum { hwaddr_glb_len = 16 };
	enum { hwaddr_loc_len = 4 };
	static char hwaddr_glb[hwaddr_glb_len] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	static char hwaddr_loc[hwaddr_loc_len] = { '2', '6', 'A', 'E' };

	int i;
	size_t space = 1;
	char* mac = malloc(space);

	int local = 0;
	for (i = 0; i < hwaddr_len; i++)
	{
		if (i == 1 && local == 1)
		{
			mac[i] = hwaddr_loc[rand() % hwaddr_loc_len];
		}
		else
		{
			mac[i] = hwaddr_glb[rand() % hwaddr_glb_len];
		}
		space++;
		mac = realloc(mac, space);
	}

	printf(mac_format, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mac[6], mac[7], mac[8], mac[9], mac[10], mac[11]);
	//printf(mac_f2, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mac[6], mac[7], mac[8], mac[9], mac[10], mac[11]);
	//printf(mac_f3, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mac[6], mac[7], mac[8], mac[9], mac[10], mac[11]);
	//printf(mac_f4, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mac[6], mac[7], mac[8], mac[9], mac[10], mac[11]);

	//printf("type = %s, count = %s, format = %s, prefix = %s, case = %s\n", tvalue, nvalue, fvalue, pvalue, cvalue);


	//for (index = optind; index < argc; index++)
		//printf("Non-option argument %s\n", argv[index]);
	//return 0;
}