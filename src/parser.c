#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <libcnc.h>
#include <math/converter.h>

int CNCCreateInstruction(CNCInstruction *p, CNCOpcode opcode, CNCOptions *options)
{
	p->magic = 0; // TODO: Figure out what in the heck this is for (@ sdkmvx, since it was your idea)
	p->opcode = opcode;
	p->options = *options;

	return 0;
}

int CNCCreateOptions(CNCOptions *p, CNCOpcode opcode, ...)
{
	// What goes here?
	return 0;
}

int CNCCreatePoint(CNCPoint *p, uint32_t x, uint32_t y, uint32_t z)
{
	p->x = x;
	p->y = y;
	p->z = z;

	return 0;
}

void CNCPrintPoint(CNCPoint p)
{
	int i, n, temp;
	char *data, *bin;
	printf("Point coordinates: (%u, %u, %u)\n\n", p.x, p.y, p.z);

	printf("Binary data:\n\n");
	printf("Byte Num |  Bits");
	data = (char*) &p;
	for ( i = 0; i < sizeof(CNCPoint); i+=8) {
		for ( n = 0; n < i+8; n++ ) {
			temp += data[n];
		}
		bin = dec2bin(temp);
		printf("\n%7i  |  %s", (i/8)+1, alignbin(bin, 8));
	}
	putchar('\n');
}

int main(void)
{
	CNCPoint p;

	CNCCreatePoint(&p, 1, 2, 3);
	CNCPrintPoint(p);

	CNCCreatePoint(&p, 100, 2, 3);
	CNCPrintPoint(p);

	CNCCreatePoint(&p, 100, 200, 300);
	CNCPrintPoint(p);

	return 0;
}
