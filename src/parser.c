#include <stdint.h>
#include <stdio.h>
#include <libcnc.h>

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
	int i;
	unsigned char *data;
	printf("x: %u\ny: %u\nz: %u\n", p.x, p.y, p.z);

	data = (unsigned char*) &p;
	for (i = 0; i < sizeof(CNCPoint); i++) {
		if (i % 8 == 0)
			printf("\n%04x  ", i);
		printf("%02x ", data[i]);
	}

	putchar('\n');
}

int main(void)
{
	CNCPoint p;

	CNCCreatePoint(&p, 1, 2, 3);

	CNCPrintPoint(p);

	return 0;
}
