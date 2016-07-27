/*	File name: exu_flags.c
Description: Handler for the 8086 flag register 
Abbreviation Notes: exu = Execution Unit
*/

#include "stdint.h"
#include "stdbool.h"

#include "exu_pub_flags.h"

static uint16_t s_flag_reg;

void EXU_flag_reg_init( void )
{
	s_flag_reg = 0x00; 
}

void EXU_flag_reg_set( EXU_flag_reg_t8 flag )
{
	if (flag < EXU_FLAG_REG_COUNT)
	{
	s_flag_reg |= ( 1 << flag );
	}
}

bool EXU_flag_reg_get( EXU_flag_reg_t8 flag )
{
	/* local variables */
	uint16_t temp_flag_reg; 

	temp_flag_reg = s_flag_reg; 

	/* shift temp register until desired flag is lsb */
	temp_flag_reg = ( temp_flag_reg >> flag ); 

	return ( temp_flag_reg & 0x01 );
}