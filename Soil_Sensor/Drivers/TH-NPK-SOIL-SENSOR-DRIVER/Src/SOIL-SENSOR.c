/*
#include <stdio.h>
#include <string.h>

uint16_t CalculateCRC(uint8_t *buf, int len) {
    uint16_t crc = 0xFFFF;
    for (int pos = 0; pos < len; pos++) {
        crc ^= (uint16_t)buf[pos];
        for (int i = 8; i != 0; i--) {
            if ((crc & 0x0001) != 0) {
                crc >>= 1;
                crc ^= 0xA001;
            } else {
                crc >>= 1;
            }
        }
    }
    return crc;
}


void Read_Soil_Sensor(void)
{
    uint8_t msg[] = {0x01, 0x03,0x00,0x00,0x00,0x07,0x04,0x08};
    uint16_t crc = CalculateCRC(msg, 6);
    msg[6] = crc & 0xFF;
    msg[7] = (crc >> 8) & 0xFF;

    uint8_t response[19] = {0};
    char buffer[256];

    HAL_StatusTypeDef receiveProblem;

    if (HAL_UART_Transmit(&huart1, msg, 8, 2005) == HAL_OK)
    {
    	receiveProblem = HAL_UART_Receive(&huart1, response, 19, 2500);
        if (receiveProblem == HAL_OK)
        {
        	   uint16_t rawHumidity     = (response[3]  << 8) | response[4];
        	    int16_t  rawTemperature  = (int16_t)((response[5]  << 8) | response[6]);
        	    uint16_t rawConductivity = (response[7]  << 8) | response[8];
        	    uint16_t rawPH           = (response[9]  << 8) | response[10];
        	    uint16_t rawNitrogen     = (response[11] << 8) | response[12];
        	    uint16_t rawPhosphorus   = (response[13] << 8) | response[14];
        	    uint16_t rawPotassium    = (response[15] << 8) | response[16];

        	    // Apply scaling factors from datasheet
        	    float humidity     = rawHumidity     * 0.1f;  // 0.1%RH
        	    float temperature  = rawTemperature  * 0.1f;  // 0.1°C, int16 handles negatives
        	    float conductivity = rawConductivity * 1.0f;  // 1 us/cm
        	    float ph           = rawPH           * 0.1f;  // 0.1
        	    float nitrogen     = rawNitrogen     * 1.0f;  // 1 mg/kg
        	    float phosphorus   = rawPhosphorus   * 1.0f;  // 1 mg/kg
        	    float potassium    = rawPotassium    * 1.0f;  // 1 mg/kg

        	    snprintf(buffer, sizeof(buffer),
        	            "--- Soil Report ---\r\n"
        	            "Humidity:     %.1f %%RH\r\n"
        	            "Temperature:  %.1f C\r\n"
        	            "Conductivity: %.0f us/cm\r\n"
        	            "pH:           %.1f\r\n"
        	            "Nitrogen:     %.0f mg/kg\r\n"
        	            "Phosphorus:   %.0f mg/kg\r\n"
        	            "Potassium:    %.0f mg/kg\r\n"
        	            "\r\n",
        	            humidity, temperature, conductivity,
        	            ph, nitrogen, phosphorus, potassium);

        	    HAL_UART_Transmit(&huart2, (uint8_t*)buffer, strlen(buffer), 500);
        }

        else if(receiveProblem == HAL_ERROR){
                	HAL_UART_Transmit(&huart2, (uint8_t*)"ERROR\r\n", 9, 2500);
        }
        else if(receiveProblem == HAL_BUSY){
                	HAL_UART_Transmit(&huart2, (uint8_t*)"BUSY\r\n", 9, 2500);
        }

        else if(receiveProblem == HAL_TIMEOUT)
        {
            HAL_UART_Transmit(&huart2, (uint8_t*)"Timeout\r\n", 9, 2500);
        }
        else
        {
            HAL_UART_Transmit(&huart2, (uint8_t*)"IDFK\r\n", 9, 2500);
        }
    }
}
*/
