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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAC_GLB_LEN 16
#define MAC_LOC_LEN 4

int main(void)
{
	struct timeval tm;
	gettimeofday(&tm, NULL);
	srand(tm.tv_sec + tm.tv_usec * 1000000ul);

	static char mac_glb_hex[MAC_GLB_LEN] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F' };
	static char mac_loc_hex[MAC_LOC_LEN] = { '2', '6', 'A', 'E' };

	int i;
	for (i = 0; i < 12; i++)
	{
		if (i == 1)
		{
			printf("%c", mac_loc_hex[rand() % MAC_LOC_LEN]);
		}
		else
		{
			printf("%c", mac_glb_hex[rand() % MAC_GLB_LEN]);
		}
	}

	printf("\n");
	return 0;
}
