<h1 align="center"> Robotic sorter </h1>

## Descrizione generale

Mediante l'uso di un [braccio robotico](https://store.arduino.cc/products/tinkerkit-braccio-robot?srsltid=AfmBOorpDogQ4HbyjZogZo8spMaIm-5Hzn5_y7hVqd3n9clGSyTXihFV) e un [sensore di colore](https://www.amazon.it/dp/B09Z27FXBR?ref=ppx_yo2ov_dt_b_fed_asin_title) si prendono dei cubetti colorati da un caricatore, si mettono davanti al sensore e si mettono una delle 3 scatole.

## Tabella elementi necessari (oltre scheda NXP)

|Elemento               |Descrizione    |Datasheet|
|:---:                  |:---:          |:---:    |
|Tinkerkit Braccio robot|Braccio robot 6 assi|[datasheet](https://store.arduino.cc/products/tinkerkit-braccio-robot?srsltid=AfmBOorpDogQ4HbyjZogZo8spMaIm-5Hzn5_y7hVqd3n9clGSyTXihFV) |
| TCS34725 | Sensore colore I2C | [datasheet](https://homotix_it.e-mind.it/upld/repository/File/tcs34725.pdf) |
| Cubi colorati | Cubetti colorati da mettere nelle scatole| |
| Caricatore | Da fare forse con un'altro servo tipo nastro trasportatore o ascensore | |

## Descrizione elementi utili

### Tinkerkit Braccio Robot

5V @ 4A DC. Alimentatore incluso. Pilotaggio con PWM analogico

1. 2 x SR 311:
    - PWM analogico da 0.5ms a 2.5ms
    - Range di movimento di 180°
2. 4 x SR 431 (uguale a quello sopra ma più grosso e con più coppia)
![Identificatori motori](./Immagini/Identificatori%20motori.png)
![Range motori](./Immagini/Range%20motori.png)

#### Collegamenti

|  M6 |  M5 |  M4 |  M3 |  M2  |  M1  |
|:---:|:---:|:---:|:---:|:----:|:----:|
|PTB-5|PTB-4|PTC-3|PTC-2|PTB-13|PTB-12|
| J2-5| J2-7|J1-13|J5-15|J5-11 | J4-3 |

### Sensore di colore

Il sensore è costituito da una matrice di fotodiodi, 4 adc, una macchina a stati
e un'interfaccia I2C.
Per aumentare l'efficienza ed eliminare la necessità di fare il polling c'è un pin
di interrupt che permette di avvertire il micro quando un colore è sopra o sotto
una certa soglia e fare la lettura con la I2C solo quando necessaria.

#### Macchina a stati

![Macchina a stati](./Immagini/macchina%20a%20stati.png)

#### Indirizzi registri e settaggio

Indirizzo sensore: 0x29.

Per scrivere gli indirizzi del sensore bisogna mandare come primo byte il command.

![Indirizzi dei registri](./Immagini/Indirizzi%20sensore.png)

| Indirizzo | Nome               | Configurazione_1| Configurazione_2 | Descrizione |
| :-------: | :---               | :------:        | :----------      | :---------- |
| ------    | Command            | 10100000        |  10100000        | PAG 14      |
| 0x00      | Enable             | 00000011        |  00000011        | PAG 15      |
| 0x01      | Timing             | 0X2A            |  0XC0            | PAG 16      |
| 0x03      | Wait               | 11111111        |  11111111        | PAG 16      |
| 0x04      | Clear_L_th_L_byte  | 00000000        |  00000000        | PAG 17      |
| 0x05      | Clear_L_th_U_byte  | 00000000        |  00000000        | PAG 17      |
| 0x06      | Clear_H_th_L_byte  | 00000000        |  00000000        | PAG 17      |
| 0x07      | Clear_H_th_H_byte  | 00000000        |  00000000        | PAG 17      |
| 0x0C      | Persistance        | 00000000        |  00000000        | PAG 17      |
| 0x0D      | Configuration      | 00000000        |  00000000        | PAG 18      |
| 0x0F      | Control            | 00000010        |  00000011        | PAG 18      |
| 0x12      | ID                 | 0x4D            |  0x4D            | PAG 18      |
| 0x13      | Status             |                 |                  | PAG 19      |
| 0x14      | Clear_data_L       |                 |                  |             |
| 0x15      | Clear_data_H       |                 |                  |             |
| 0x16      | Red_data_L         |                 |                  |             |
| 0x17      | Red_data_H         |                 |                  |             |
| 0x18      | Green_data_L       |                 |                  |             |
| 0x19      | Green_data_H       |                 |                  |             |
| 0x1A      | Blu_data_L         |                 |                  |             |
| 0x1B      | Blu_data_H         |                 |                  |             |

#### Collegamenti

| Pin Slave | Funzione | Pin Master |
| :-----:    | :------- | :--------- |
| Vin | Tensione di ingresso (da 3,3V a 5V) | J3-9/3 |
| Gnd | Ground | J3-11/13 |
| 3V3 | Tensione di uscita 3V3 | DNC |
| SCL | Clock I2C | J1-3 |
| SDA | Data I2C | J1-1 |
| INT | Interrupt (Open drain) | TBD |
| LED | Spegnimento LED (Vcc spento, Gnd acceso)| DNC |

## Test sensore

### Configurazione 1

#### Rosso

| Indirizzo | Nome               | Lettura |
| :-------: | :---               | :------:|
| 0x13      | Status             | ??      |
| 0x14      | Clear_data_L       | FF      |
| 0x15      | Clear_data_H       | FF      |
| 0x16      | Red_data_L         | 6A      |
| 0x17      | Red_data_H         | D6      |
| 0x18      | Green_data_L       | E4      |
| 0x19      | Green_data_H       | 26      |
| 0x1A      | Blu_data_L         | 97      |
| 0x1B      | Blu_data_H         | 1F      |

#### Blu

| Indirizzo | Nome               | Lettura |
| :-------: | :---               | :------:|
| 0x13      | Status             | 11      |
| 0x14      | Clear_data_L       | FF      |
| 0x15      | Clear_data_H       | FF      |
| 0x16      | Red_data_L         | E4      |
| 0x17      | Red_data_H         | 43      |
| 0x18      | Green_data_L       | 2B      |
| 0x19      | Green_data_H       | 79      |
| 0x1A      | Blu_data_L         | F4      |
| 0x1B      | Blu_data_H         | 66      |

#### Verde

| Indirizzo | Nome               | Lettura |
| :-------: | :---               | :-----: |
| 0x13      | Status             | 11      |
| 0x14      | Clear_data_L       | FF      |
| 0x15      | Clear_data_H       | FF      |
| 0x16      | Red_data_L         | 48      |
| 0x17      | Red_data_H         | 55      |
| 0x18      | Green_data_L       | B9      |
| 0x19      | Green_data_H       | 7C      |
| 0x1A      | Blu_data_L         | 6C      |
| 0x1B      | Blu_data_H         | 3B      |

### Configurazione 2

#### Rosso

| Indirizzo | Nome               | Lettura |
| :-------: | :---               | :------:|
| 0x13      | Status             | 11      |
| 0x14      | Clear_data_L       | FF      |
| 0x15      | Clear_data_H       | FF      |
| 0x16      | Red_data_L         | 01      |
| 0x17      | Red_data_H         | FF      |
| 0x18      | Green_data_L       | 31      |
| 0x19      | Green_data_H       | 2F      |
| 0x1A      | Blu_data_L         | 62      |
| 0x1B      | Blu_data_H         | 25      |

#### Blu

| Indirizzo | Nome               | Lettura |
| :-------: | :---               | :------:|
| 0x13      | Status             | 11      |
| 0x14      | Clear_data_L       | FF      |
| 0x15      | Clear_data_H       | FF      |
| 0x16      | Red_data_L         | 2D      |
| 0x17      | Red_data_H         | 49      |
| 0x18      | Green_data_L       | 03      |
| 0x19      | Green_data_H       | 80      |
| 0x1A      | Blu_data_L         | 77      |
| 0x1B      | Blu_data_H         | 6C      |

#### Verde

| Indirizzo | Nome               | Lettura |
| :-------: | :---               | :-----: |
| 0x13      | Status             | 11      |
| 0x14      | Clear_data_L       | FF      |
| 0x15      | Clear_data_H       | FF      |
| 0x16      | Red_data_L         | 79      |
| 0x17      | Red_data_H         | 5A      |
| 0x18      | Green_data_L       | CD      |
| 0x19      | Green_data_H       | 80      |
| 0x1A      | Blu_data_L         | 9A      |
| 0x1B      | Blu_data_H         | 3D      |

Si sceglie la Configurazione_2 in quanto ci permette a parità di valori
di uscita comparabili con la configurazione 1 con tempi di misura molto
più veloci (154ms vs 511ms) che moltiplicato per i tre valori del voter
fa un risparmio di più di un secondo nella misura a parità (o con una maggiore) accuratezza.
