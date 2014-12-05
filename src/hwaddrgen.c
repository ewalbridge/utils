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
//format mac address *
//type: any or local
//prefix
//case
//count

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <getopt.h>

int main(int argc, char* argv[])
{
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

	char* mac_f1 = "%c%c%c%c%c%c%c%c%c%c%c%c\n";
	char* mac_f2 = "%c%c-%c%c-%c%c-%c%c-%c%c-%c%c\n";
	char* mac_f3 = "%c%c:%c%c:%c%c:%c%c:%c%c:%c%c\n";
	char* mac_f4 = "%c%c%c%c.%c%c%c%c.%c%c%c%c\n";

	printf(mac_f1, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mac[6], mac[7], mac[8], mac[9], mac[10], mac[11]);
	printf(mac_f2, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mac[6], mac[7], mac[8], mac[9], mac[10], mac[11]);
	printf(mac_f3, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mac[6], mac[7], mac[8], mac[9], mac[10], mac[11]);
	printf(mac_f4, mac[0], mac[1], mac[2], mac[3], mac[4], mac[5], mac[6], mac[7], mac[8], mac[9], mac[10], mac[11]);

	//for (i = 0; i < hwaddr_len; i++)
	//{
	//	printf("%c", mac[i]);
	//}
	//printf("\n");

	free(mac);
	return 0;
}
