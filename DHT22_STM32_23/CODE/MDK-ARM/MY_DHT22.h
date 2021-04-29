
//Header files
#include "stm32l1xx_hal.h"
#include <stdbool.h>
#include <string.h>
#include <math.h>

//Pin Mode enum
typedef enum
{
	ONE_OUTPUT = 0,
	ONE_INPUT,
}OnePinMode_Typedef;



//***Protypes des fonctions ***//

//Initialisation communication 1 fil 
void DHT22_Init(GPIO_TypeDef* DataPort, uint16_t DataPin);

//Changement mode IN/OUT PUT du PIN A9
static void ONE_WIRE_PinMode(OnePinMode_Typedef mode);

//D�finition PIN �criture et lecture
static void ONE_WIRE_Pin_Write(bool state);
static bool ONE_WIRE_Pin_Read(void);

//D�finition du temps en microsecondes
static void DelayMicroSeconds(uint32_t uSec);

//Lancer l'acquisition des donn�es
static void DHT22_StartAcquisition(void);

//Lecture des 4*8 donn�es du DHT22
static void DHT22_ReadRaw(uint8_t *data);

//R�cup�ration des donn�es de temp�rature et d'humidit�
bool DHT22_GetTemp_Humidity(float *Temp, float *Humidity);

