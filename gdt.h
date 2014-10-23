
//#ifndef __GDT_H
#define __GDT_H

#define SEG_DESCTYPE(x)		((x) << 0x04)			// Descriptor (0 System, 1 Code/Data)
#define SEG_PRES(x)			((x) << 0x07)			// Present
#define SEG_SAVL(x)			((x) << 0x0C)			// Available for system use
#define SEG_LONG(x)			((x) << 0x0D)			// Long mode
#define SEG_SIZE(x)			((x) << 0x0E)			// Size(0 16bit, 1 32bit)
#define SEG_GRAN(x)			((x) << 0x0F)			// Granularity (0 1B-1M; 1 4K - 4M)
#define SEG_PRIV(x)			(((x) & 0x03) << 0x05)	// Set priv level (0 - 3)

#define SEG_DATA_RD			0x00	// Read-Only
#define SEG_DATA_RDA		0x01	// Read-Only, accessed
#define SEG_DATA_RDWR		0x02	// Read/Write
#define SEG_DATA_RDWRA		0x03	// Read/Write, accessed
#define SEG_DATA_RDEXPD		0x04	// Read-Only, expand-down
#define SEG_DATA_RDEXPDA	0x05	// Read-Only, expand-down, accessed
#define SEG_DATA_RDWREXPD	0x06	// Read/Write, expand-down
#define SEG_DATA_RDWREXPDA	0x07	// Read/Write, expand-down, accessed
#define SEG_CODE_EX			0x08	// Exec-Only
#define SEG_CODE_EXA		0x09	// Exec-Only, accessed
#define SEG_CODE_EXRD		0x0A	// Exec/Read
#define SEG_CODE_EXRDA		0x0B	// Exec/Read, accessed
#define SEG_CODE_EXC		0x0C	// Exec-Only, conforming
#define SEG_CODE_EXCA		0x0D	// Exec-Only, conforming, accessed
#define SEG_CODE_EXRDC		0x0E	// Exec/Read, conforming
#define SEG_CODE_EXRDCA		0x0F	// Exec/Read, conforming, accessed

#define GDT_CODE_PL0	SEG_DESCTYPE(1)	| SEG_PRES(1) | SEG_SAVL(0) | \
						SEG_LONG(0)		| SEG_SIZE(1) | SEG_GRAN(1) | \
						SEG_PRIV(0)		| SEG_CODE_EXRD

#define GDT_DATA_PL0	SEG_DESCTYPE(1)	| SEG_PRES(1) | SEG_SAVL(0) | \
						SEG_LONG(0)		| SEG_SIZE(1) | SEG_GRAN(1) | \
						SEG_PRIV(0)		| SEG_DATA_RDWR

#define GDT_CODE_PL3	SEG_DESCTYPE(1)	| SEG_PRES(1) | SEG_SAVL(0) | \
						SEG_LONG(0)		| SEG_SIZE(1) | SEG_GRAN(1) | \
						SEG_PRIV(3)		| SEG_CODE_EXRD

#define GDT_DATA_PL3	SEG_DESCTYPE(1)	| SEG_PRES(1) | SEG_SAVL(0) | \
						SEG_LONG(0)		| SEG_SIZE(1) | SEG_GRAN(1) | \
						SEG_PRIV(3)		| SEG_DATA_RDWR

//#endif // __GDT_H

