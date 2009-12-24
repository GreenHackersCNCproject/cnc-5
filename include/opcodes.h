#ifndef OPCODES_H
#define OPCODES_H

#define CNC_OPCODE_RESET  1  // Reset to (0,0,0) with drill in "inactive" position
#define CNC_OPCODE_LOCK   2  // Lock portion of CNC
#define CNC_OPCODE_UNLOCK 3  // Unlock portion of CNC
#define CNC_OPCODE_MOVE   4  // Move to provided location
#define CNC_OPCODE_HOLE   5  // Drill hole at current location

#endif
