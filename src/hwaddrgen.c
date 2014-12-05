#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAC_GLB_LEN 
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
