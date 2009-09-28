#ifndef CNC_H
#define CNC_H

#include <stdint.h>

#define CNC_OPCODE_HOLE 1

typedef uint16_t CNCOpcode;
typedef uint64_t CNCOptions;

typedef struct cnc_instruction {
	uint16_t magic;
	CNCOpcode opcode;
	CNCOptions options;
} CNCInstruction;

typedef struct cnc_hole_options {
	uint16_t x;
	uint16_t y;
	uint16_t z;
	uint16_t pad;
} CNCHoleOptions;

typedef struct cnc_point {
	uint32_t x;
	uint32_t y;
	uint32_t z;
} CNCPoint;

int CNCCreateInstruction(CNCInstruction *p, CNCOpcode opcode,
		CNCOptions *options);
int CNCCreateOptions(CNCOptions *p, CNCOpcode opcode, ...);
int CNCCreatePoint(CNCPoint *p, uint32_t x, uint32_t y, uint32_t z);
#endif
