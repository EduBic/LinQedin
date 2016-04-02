Progetto didattico per il corso **programmazione ad oggetti** tenuto dal prof. Francesco Ranzato, dell'Università di Padova, Scienze Informatiche.

# Introduzione e scelte di maggior rilievo
Il progetto riguarda un'**applicazione che simula il noto social network Linkedin®** in un ambiente
locale, rendendo disponibile all'utente le caratteristiche minime di ogni social.
Nella parte logica si sfruttano appieno le capacità comprese alle lezioni del corso di
programmazione ad oggetti, richiedendo specifiche competenze e attenzioni nella costruzione del
design delle classi e nella gestione della memoria.
La parte grafica nasce con l'intento di soddisfare tutti gli obiettivi richiesti dalla consegna,
mostrandosi il più possibile user-friendly, rendendo necessaria una buona conoscenza della Qt
Library per sfruttarne il potenziale offerto.

## Gestione degli errori
Tutti i principali errori sono gestiti dalle classi controller (non è escluso che alcuni controlli siano
fatti anche nella parte logica per mantenerne l'integrità, tuttavia questi non sono segnalati) , le quali
verificano la coerenza dell'input emesso dalla view con le richieste del model. Nel caso di errori si è
usufruito del potente strumento QMessageBox resa disponibile dalla libreria Qt che permette
una facile comunicazione con l'utente dell'evento accaduto e guida l'utente a risolvere il
problema legato all'errore.

## Gestione della ricerca polimorfica
La ricerca come da consegna è stata implementata utilizzando un metodo virtuale puro. Con ciò è
possibile distinguere la effettiva potenza della ricerca all'interno del database tra i vari utenti
favorendo una crescente potenzialità.

## Gestione della memoria
Si è deciso per **efficienza** di aprire il database e leggerlo in memoria una sola volta dal main e
condividere esso tramite puntatori dal controller di start al model. Solo alla chiusura
dell'applicazione il database è scritto su file. I metodi di lettura e scrittura sono chiamati
rispettivamente nel costruttore di DataBase e nel distruttore. Inoltre si è cercato di sfruttare il più
possibile l'uso di puntatori e riferimenti per evitare copie inutili.

## Estensibilità
Il progetto aderisce al pattern **Model-View-Controller**, ogni classe della componente grafica
modifica la parte logica solo attraverso i controller. Ciò garantisce una quasi completa separazione
della parte logica da quella grafica oltre a semplificare la complessità del codice e incrementare le
possibilità di estensione delle classi.
