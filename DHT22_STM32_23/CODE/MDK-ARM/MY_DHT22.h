
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

//Définition PIN écriture et lecture
static void ONE_WIRE_Pin_Write(bool state);
static bool ONE_WIRE_Pin_Read(void);

//Définition du temps en microsecondes
static void DelayMicroSeconds(uint32_t uSec);

//Lancer l'acquisition des données
static void DHT22_StartAcquisition(void);

//Lecture des 4*8 données du DHT22
static void DHT22_ReadRaw(uint8_t *data);

//Récupération des données de température et d'humidité
bool DHT22_GetTemp_Humidity(float *Temp, float *Humidity);

