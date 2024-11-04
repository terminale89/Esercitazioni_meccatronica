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

### Sensore di colore

Il sensore è costituito da una matrice di fotodiodi, 4 adc, una macchina a stati
e un'interfaccia I2C.
Per aumentare l'efficienza ed eliminare la necessità di fare il polling c'è un pin
di interrupt che permette di avvertire il micro quando un colore è sopra o sotto
una certa soglia e fare la lettura con la I2C solo quando necessaria.

#### Macchina a stati:
