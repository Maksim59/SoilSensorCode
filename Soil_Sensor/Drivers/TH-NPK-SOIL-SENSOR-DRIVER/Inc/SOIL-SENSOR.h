#include <stdio.h>
#include <string.h>

uint16_t CalculateCRC(uint8_t *buf, int len);
/*
 * @param buf pointer to the buffer you want to perform error check on
 * @param len the length of the buffer that you are performing an error check no
 */
void Read_Soil_Sensor(void);
/*
 * Reads The Soil Sensor
 */
