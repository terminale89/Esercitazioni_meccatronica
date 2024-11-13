Questa parte di codice comanda il braccio per seguire dei percorsi preimpostati.
I percorsi sono preimpostati dai blocchi Path (delle mathfunction che ritornano un array costante).
La posizione nel percorso è risultato di un'interpolazione del percorso selezionato al tempo specificato.

Input:
- istante nel percorso  (double; se eccede i tempi specificati viene considerato il punto definito più vicini)
- selettore del percorso (1, 2, 3 o 4; 4 è il valore di default e corrisponde alla situazione di riposo)

Blocchi:

- Definizioni del percorso
- Selettore del percorso
- Interpolatore
- Blocco IK: restituisce gli angoli dal punto 3D specificato
- Driver: produce un segnale PWM a partire dagli angoli

Se si rimonta il braccio conviene ricontrollare gli angoli di riposo, perché possono cambiare.

Per completare il progetto serve un sistema che legge il sensore e produce il selettore e il tempo, ma l'hai già fatto.

Funzionamento blocco IK:

1) Trova l'angolo di M1 all'ineando il braccio nella direzione del punto specificato. Il problema diventa 2D.
2) Trova l'angolo di M4 a partire dall'angolo tra la verticale assoluta e il versore parallelo alla pinza.
3) Dato l'angolo di M4 è definita la posizione di M4. Rimangono solo due giunti, M2 e M3.
4) Gli angoli di M2 e M4 si trovano con la stessa procedura dello Scara
5) Ci sono delle righe in più per gestire i punti fuori dallo spazio raggiungibile dal robot.