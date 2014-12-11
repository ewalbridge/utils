/*

	The MIT License (MIT)

	Copyright (c) 2014 Eric Walbridge

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.

*/

//
//format mac address -f [1,2,3,4]
//type: any or local -a
//prefix -p [00:00:00]
//case -c [l,u]
//count -n [n]

#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

enum { hwaddr_len = 12 };
enum { hwaddr_glb_len = 16 };
enum { hwaddr_loc_len = 4 };
static char hwaddr_glb[hwaddr_glb_len] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
static char hwaddr_loc[hwaddr_loc_len] = { '2', '6', 'A', 'E' };
const char *fmt_mac[] = { "%c%c%c%c%c%c%c%c%c%c%c%c", "%c%c-%c%c-%c%c-%c%c-%c%c-%c%c", "%c%c:%c%c:%c%c:%c%c:%c%c:%c%c", "%c%c%c%c.%c%c%c%c.%c%c%c%c", };

char *generate_mac(char *buffer, size_t buffer_size, const int local_addr, const int format_addr, const int case_addr) 
{
	struct timeval tm;
	gettimeofday(&tm, NULL);
	#ifdef __linux__
		srand(tm.tv_usec * tm.tv_sec);
	#elif _WIN32
		srand(tm.tv_usec * tm.tv_sec * rand());
	#endif
	
	int i;
	size_t space = 1;
	char *mac = malloc(space);
	
	for (i = 0; i < hwaddr_len; i++)
	{
		if (i == 1 && local_addr == 1)
		{
			if(case_addr == 0)
			{
				mac[i] = hwaddr_loc[rand() % hwaddr_loc_len];
			}
			else
			{
				mac[i] = tolower(hwaddr_loc[rand() % hwaddr_loc_len]);
			}
		}
		else
		{
			if(case_addr == 0)
			{
				mac[i] = hwaddr_glb[rand() % hwaddr_glb_len];
			}
			else
			{
				mac[i] = tolower(hwaddr_glb[rand() % hwaddr_glb_len]);
			}
		}
		
		space++;
		mac = realloc(mac, space);
	}
	
	int n = snprintf(buffer, buffer_size, fmt_mac[format_addr], mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mac[6], mac[7], mac[8], mac[9], mac[10], mac[11]);
    assert(0 <= n && (unsigned) n < buffer_size);
	free(mac);
    return buffer;
	//return "";
}

int main(int argc, char **argv)
{
    char buffer[64];
    assert(1 < argc);
	int local_addr = atoi(argv[1]);
	int format_addr = atoi(argv[2]);
	int case_addr = atoi(argv[3]);
	int count_addr = atoi(argv[4]);
	int i;
	for (i = 0; i < count_addr; i++)
	{
		printf("%s", generate_mac(buffer, sizeof(buffer), local_addr, format_addr - 1, case_addr));
		if(i < count_addr -1)
		{
			printf("\n");
		}
	}
	#ifdef __linux__
		printf("\n");
	#elif _WIN32
	#endif
    return 0;
}

