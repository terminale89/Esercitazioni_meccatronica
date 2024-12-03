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

| Indirizzo | Nome               | Settaggio_1| Setteggio_2 | Descrizione |
| :-------: | :---               | :------:   | :---------- | :---------- |
| ------    | Command            | 10100000   |  10100000   |  pag 14     |
| 0x00      | Enable             | 00010011   |  00010011   | PAG 15      |
| 0x01      | Timing             | 0XA0       |  0XCA       | PAG 16      |
| 0x03      | Wait               | 11111111   |  11111111   | PAG 16      |
| 0x04      | Clear_L_th_L_byte  | 00000000   |  00000000   | PAG 17      |
| 0x05      | Clear_L_th_U_byte  | 00000000   |  00000000   | PAG 17      |
| 0x06      | Clear_H_th_L_byte  | 00000000   |  00000000   | PAG 17      |
| 0x07      | Clear_H_th_H_byte  | 00000000   |  00000000   | PAG 17      |
| 0x0C      | Persistance        | 00000000   |  00000000   | PAG 17      |
| 0x0D      | Configuration      | 00000000   |  00000000   | PAG 18      |
| 0x0F      | Control            | 00000000   |  00000000   | PAG 18      |
| 0x12      | ID                 | 0x4D       |  0x4D       | PAG 18      |
| 0x13      | Status             |            |             | PAG 19      |
| 0x14      | Clear_data_L       |            |             |             |
| 0x15      | Clear_data_H       |            |             |             |
| 0x16      | Red_data_L         |            |             |             |
| 0x17      | Red_data_H         |            |             |             |
| 0x18      | Green_data_L       |            |             |             |
| 0x19      | Green_data_H       |            |             |             |
| 0x1A      | Blu_data_L         |            |             |             |
| 0x1B      | Blu_data_H         |            |             |             |

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

Chatgpt -> ATIME ->00, CONTROL -> 01
0xC0, 0x03
OxBA, 0x00

### Configurazione 1

#### Senza nulla sopra

| Indirizzo | Nome               | Lettura | Lettura 2 |
| :-------: | :---               | :------:| :------:  |
| 0x13      | Status             | ??      |           |
| 0x14      | Clear_data_L       | 11      | 11        |
| 0x15      | Clear_data_H       | 49      | 21        |
| 0x16      | Red_data_L         | 07      | 1A        |
| 0x17      | Red_data_H         | 60      | 1E        |
| 0x18      | Green_data_L       | 02      | 14        |
| 0x19      | Green_data_H       | AF      | EF        |
| 0x1A      | Blu_data_L         | 02      | 03        |
| 0x1B      | Blu_data_H         | CB      | 97        |

#### Rosso

| Indirizzo | Nome               | Lettura | Lettura 2 |
| :-------: | :---               | :------:| :------:  |
| 0x13      | Status             | ??      |           |
| 0x14      | Clear_data_L       | 11      | 11        |
| 0x15      | Clear_data_H       | FB      | 21        |
| 0x16      | Red_data_L         | 0F      | 1A        |
| 0x17      | Red_data_H         | 74      | 1E        |
| 0x18      | Green_data_L       | 0C      | 14        |
| 0x19      | Green_data_H       | 41      | EF        |
| 0x1A      | Blu_data_L         | 02      | 03        |
| 0x1B      | Blu_data_H         | 23      | 97        |

#### Blu

| Indirizzo | Nome               | Lettura | Lettura 2 |
| :-------: | :---               | :------:| :-------: |
| 0x13      | Status             | ??      |           |
| 0x14      | Clear_data_L       | 11      | 11        |
| 0x15      | Clear_data_H       | 60      | 7E        |
| 0x16      | Red_data_L         | 04      | 06        |
| 0x17      | Red_data_H         | A7      | 7F        |
| 0x18      | Green_data_L       | 01      | 02        |
| 0x19      | Green_data_H       | 32      | C8        |
| 0x1A      | Blu_data_L         | 01      | 01        |
| 0x1B      | Blu_data_H         | BF      | 83        |

#### Verde

| Indirizzo | Nome               | Lettura | Verde brillante |
| :-------: | :---               | :-----: | :-------------: |
| 0x13      | Status             | ??      | ??              |
| 0x14      | Clear_data_L       | 11      | 11              |
| 0x15      | Clear_data_H       | 86      | 64              |
| 0x16      | Red_data_L         | 03      | 0F              |
| 0x17      | Red_data_H         | 71      | A3              |
| 0x18      | Green_data_L       | 01      | 05              |
| 0x19      | Green_data_H       | 37      | 38              |
| 0x1A      | Blu_data_L         | 01      | 06              |
| 0x1B      | Blu_data_H         | C9      | B4              |

### Configurazione 2

#### Rosso

| Indirizzo | Nome               | Lettura | Lettura 2 |
| :-------: | :---               | :------:| :------:  |
| 0x13      | Status             | ??      |           |
| 0x14      | Clear_data_L       | 11      | 11        |
| 0x15      | Clear_data_H       | FB      | 21        |
| 0x16      | Red_data_L         | 0F      | 1A        |
| 0x17      | Red_data_H         | 74      | 1E        |
| 0x18      | Green_data_L       | 0C      | 14        |
| 0x19      | Green_data_H       | 41      | EF        |
| 0x1A      | Blu_data_L         | 02      | 03        |
| 0x1B      | Blu_data_H         | 23      | 97        |

#### Blu

| Indirizzo | Nome               | Lettura |
| :-------: | :---               | :------:|
| 0x13      | Status             | ??      |
| 0x14      | Clear_data_L       | 11      |
| 0x15      | Clear_data_H       | 01      |
| 0x16      | Red_data_L         | 16      |
| 0x17      | Red_data_H         | 2C      |
| 0x18      | Green_data_L       | 00      |
| 0x19      | Green_data_H       | 35      |
| 0x1A      | Blu_data_L         | 06      |
| 0x1B      | Blu_data_H         | B7      |

#### Verde

| Indirizzo | Nome               | Lettura | Verde brillante |
| :-------: | :---               | :-----: | :-------------: |
| 0x13      | Status             | ??      | ??              |
| 0x14      | Clear_data_L       | 11      | 11              |
| 0x15      | Clear_data_H       | 86      | 64              |
| 0x16      | Red_data_L         | 03      | 0F              |
| 0x17      | Red_data_H         | 71      | A3              |
| 0x18      | Green_data_L       | 01      | 05              |
| 0x19      | Green_data_H       | 37      | 38              |
| 0x1A      | Blu_data_L         | 01      | 06              |
| 0x1B      | Blu_data_H         | C9      | B4              |