:data-transition-duration: 1000
:skip-help: true
:css: css/style.css

.. role:: i
.. |---| unicode:: U+02015 .. em dash

.. title:: Formation Arduino : Part 1

----

Formation Arduino
=================

----

Partie 0 : les outils pour programmer !
---------------------------------------

----

:id: sect_outils

IDE Arduino
===========

.. image:: imgs/IDE.png
	:width: 600px

Disponible pour Windows, Linux, MacOS

http://arduino.cc

----

IDE web
=======

.. image:: imgs/codebender.png
	:width: 600px

http://codebender.cc

Juste un plug-in à installer dans son navigateur (FF & Chrome/Chromium)

----

Partie 1 : Bases !
------------------

----

:data-y: r1600
:data-x: r0

:id: sect_structure

Structure d'un programme
========================

Depuis la version 1 : programmes en ``.ino``

----

:data-y: r0
:data-x: r1600

# Déclarations
==============

.. code:: c

    #define FOO 42          // define, macros
    #include "stuff.h"      // fichier du projet
    #include <DmxSimple.h>  // lib

- évaluées à la compilation (et remplacés)

----

setup()
=======

.. code:: c

    void setup() {
        // init ....
    }

Initialisation du programme

- déclaration des entrée/sorties (E/S)
- interruptions
- variables globales
- tout pour mettre en marche...

----

loop()
======

.. code:: c

    void loop() {
        // init ....
    }

Le programme en lui même : fonction principale.

Elle boucle indéfiniment....

::

    Pour toujours...
        loop()

----

Premier programme
=================

.. code:: c

    void setup() {
        // init...
    }

    void loop() {
        // programme...
    }

Un programme (inutile mais) fonctionnel...

----

:id: sect_sorties_num
:data-y: r1600
:data-x: r0

Entrées et Sorties Numériques
-----------------------------

.. image:: imgs/sorties_num/entre_sorties.png
    :width: 600px

----

Sorties Numériques
==================

.. image:: imgs/sorties_num/carte_arduino.png
    :width: 600px

----

:data-y: r0
:data-x: r1600

pinMode()
=========

Une broche peut être en entrée ou sortie...

il faut choisir au démarrage du programme (``setup()``)

.. code:: c

    void setup() {
        pinMode(LED_BUILTIN, OUTPUT);
    }

    void loop() {}

----

Constantes
==========

Arduino propose des constantes

- modes

    - ``OUTPUT``
    - ``INPUT``
    - ``INPUT_PULLUP``

- niveaux

    - ``HIGH``
    - ``LOW``

- des raccourcis...

    - ``LED_BUILTIN``
    - ``true``
    - ``false``

----

Allumer une LED
===============

.. note::

    lancer un bout d'exo pour allumer la LED

----

Solution :)
-----------

.. code:: c

    void setup() {
        pinMode(LED_BUILTIN, OUTPUT);
    }

    void loop() {
        digitalWrite(LED_BUILTIN, HIGH);
    }

----

Pour deux instructions...
=========================

digitalWrite()
--------------

- permet *"d'écrire"* un niveau logique sur une sortie
- active :i:`immédiatement` la sortie au niveau demandé

delay(t)
--------

- permet d'attendre un temps t... :i:`en millisecondes` !
- pendant ce temps là, l'arduino ne fait :i:`rien d'autre` !

----

Faire clignoter la LED
======================

... le *hello world* en électronique...

.. note::

    encore un exo

----

Solution :)
-----------

.. code:: c

    #define TEMPS 1000

    void setup() {
        pinMode(LED_BUILTIN, OUTPUT);
    }

    void loop() {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(TEMPS);
        digitalWrite(LED_BUILTIN, LOW);
        delay(TEMPS);
    }

----

:data-y: r1600
:data-x: r0

Boucles simples
===============

----

:data-y: r0
:data-x: r1600

Conditions
==========

- Tout ce qui n'est pas 0 est vrai

.. code:: c

    true || true // true
    true || false // true
    false || false // false

    true && true // true
    true && false // false
    false && false // false

    !true // false

.. note::

    distributif, communatif

----

Variables
=========

- Définir des noms pour y mettre des valeurs :

.. code:: c

    // premier exemple : l'entier
    int foo = 42;

    // pour les autres on verra plus tard.

----

Opérations, Opérateurs
======================

Maths
-----

.. code:: c

    =       // assignation
    - + *   // vous connaissez...
    /       // division entière
    %       // reste de la division entière
    -- ++   // décrément/incrément

Logiques
--------

.. code:: c

    ==      // égalité
    !=      // différent
    < >     // inférieur/supérieur
    >= <=   // inf/sup ou égal

----

While
=====

    Tant que je gagne, je joue ! |---| Coluche

.. code:: c

    while (je gagne) {
        // je joue
    }

    // -- Arduino

- faire quelque chose tant qu'une condition est vraie...
- ou infiniment si la condition est toujours vraie (``true``)

----

Faire clignoter une LED 10 fois
===============================

----

Solution
========

.. code:: c

    #define NB 10       // nombre de blinks
    #define TEMPS 1000  // intervales

    int i;

    void setup() {
        pinMode(LED_BUILTIN, OUTPUT);
        i=0;
    }

    void loop() {
        while (i < NB) {
            digitalWrite(LED_BUILTIN, HIGH);
            delay(TEMPS);
            digitalWrite(LED_BUILTIN, LOW);
            delay(TEMPS);
            i++;
        }
    }

----

:data-y: r1600
:data-x: r0

Fonctions/Procédures
====================

.. image:: imgs/fonctions.png
    :width: 600px

----

:data-y: r0
:data-x: r1600

Concept
=======

- bout de programme désigné par un nom
- peut recevoir des paramètres en entrée
- peut renvoyer une valeur

Variables et fonctions
======================

- les variables définies dans les fonctions ne sont accessibles :i:`que dedans`
- les variables définies en dehors de toute fonction sont accessibles :i:`partout`

----

Syntaxe générale
================

.. code:: c

    // pseudo-code
    <type de retour> nom_de_la_fonction (type1, param1, etc...) {
        // code
    }

    // exemples...
    // pour une procédure (sans retour)
    void fonction() {
        // code
    }

    // retour d'un entier :
    int fonction() {
        // code
        return un_truc;
    }

    // +42
    int plus42(int n) {
        int temp = n+42;
        return temp;
    }

----

Blink en fonction !
===================

----

Solution
========

.. code:: c

    #define LED 13
    #define TEMPS 1000

    void setup() {
        pinMode(LED, OUTPUT);
    }

    void loop() {
        blink();
    }

    void blink() {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(TEMPS);
        digitalWrite(LED_BUILTIN, LOW);
        delay(TEMPS);
    }


----

Paramètrer le temps d'allumage
==============================

----

Solution
========

.. code:: c

    #define LED 13
    #define TEMPS 500

    void setup()
    {
        pinMode(LED, OUTPUT);
    }

    void loop()
    {
        blink(TEMPS);
    }

    void blink(int temps)
    {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(temps);
        digitalWrite(LED_BUILTIN, LOW);
        delay(temps);
    }

----

:data-y: r1600
:data-x: r0

Conditionnelles
===============

----

:data-y: r0
:data-x: r1600

Et si ?
=======

.. code:: c

    if (condition) {
        // fait un truc
    }

Et sinon ?
==========

.. code:: c

    if (condition) {
        // fait un truc
    } else { // sinon...
        // ou un autre
    }

----

On (en)chaine !
===============

.. code:: c

    if (condition A) {
        // truc A
    } else if (condition B) {
        // truc B
    } else { // sinon
        // truc C
    }

----

:data-y: r1600
:data-x: r0

Entrées numériques
==================

(*digital* chez les anglais...)

----

:data-y: r0
:data-x: r1600
:id: pullup

Généralités
===========

- mêmes ports que les sorties numériques
- choix de la "fonction" entrée avec ``pinMode`` et ``INPUT``
- l'entrée à deux niveaux : ``HIGH`` et ``LOW``

INPUT_PULLUP ?
==============

.. image:: imgs/pullup.png
    :width: 200px

Permet de mettre une entrée au niveau :i:`haut` si l'interrupteur est **ouvert** !

Sur Arduino la résistance de :i:`pull-up est interne`. Sur certains microcontrôlleurs, on peut aussi choisir d'activer un
pull-down.

----

Exemples
========

.. code:: c

    void setup() {
        pinMode(5,INPUT); // input standard

        pinMode(6, INPUT_PULLUP); // entrée "tirée"
    }

----

Push-to-blink
=============

La LED clignote **si** le bouton est enfoncé !

----

Solution
========

.. code:: c

    #define BP 2 // bp sur l'entrée 2
    #define TEMPS 250
     
    void setup() {
        pinMode(LED_BUILTIN, OUTPUT);
        pinMode(BP, INPUT_PULLUP);
    }
     
    void loop() {
        if (!digitalRead(BP)) {
            blink(TEMPS);
        }
    }
     
    void blink(int temps) {
        digitalWrite(LED_BUILTIN, HIGH);
        delay(temps);
        digitalWrite(LED_BUILTIN, LOW);
        delay(temps);
    }

----

Double blink
============

Deux boutons activent la LED, à :i:`deux fréquences différentes`.

----

Solution
========

.. code:: c

    // TODO

----

Toggle-to-shine
===============

Un première appui allume la LED, un second l'éteint.

----

Solution
========

.. code:: c

    const int PB_PIN = 2; // BP connecté pin 2 
    const int LED_PIN = 13; // onboard LED on pin 13
    boolean ledOn = false; // Drapeau de l'etat de la LED
     
    void setup() {
        // Configuration des broches d'E/S
        pinMode(PB_PIN, INPUT_PULLUP); // internal pull-up
        pinMode(LED_PIN, OUTPUT);
    }
     
    void loop()
    {
        if (digitalRead(PB_PIN) == LOW) {
            // on change l'etat de la led
            ledOn = !ledOn;
            digitalWrite(LED_PIN, ledOn);
        }
    }


Seulement, ça ne marche pas très bien... pourquoi ?

----

:id: bouncing

Anti-rebond
===========

.. image:: imgs/antirebond.png
    :width: 300px

Problème : comment prendre en compte seulement le premier contact ?

----

.. code:: c

    const int PB_PIN = 2; // BP connecté pin 2
    const int LED_PIN = 13; // onboard LED sur pin 13
    const int TRANSIENT_PERIOD = 10; // Période transitoire (ms) 
    boolean transientPeriodStarted = false; // Drapeau "début du basculement du BP"
    boolean ledOn = false; // Drapeau "état de la LED"
    // indicateur de traitement du basculement de bouton débuté
    boolean bPressAccepted = false;
    // Pour enregistrer le temps de demarrage du basculement
    unsigned long timeRef = 0;

    void setup() {
        // Configuration des broches d'E/S
        pinMode(PB_PIN, INPUT_PULLUP); // internal pull-up
        pinMode(LED_PIN, OUTPUT);
    }

    void loop() {
        if (digitalRead(PB_PIN) == LOW) {
            if (!transientPeriodStarted) { // si c'est le 1er passage a Zero
                transientPeriodStarted = true; //on l'indique
                timeRef = millis(); // et on prend la reférence de temps
            }
            // si la periode du délais d'attente est passée
            // et que le BP n'est pas encore considéré comme appuyé
            else if (!bPressAccepted &&
                (unsigned long)(millis() - timeRef) > TRANSIENT_PERIOD) {
                ledOn = !ledOn; // on change l'etat de la led
                digitalWrite(LED_PIN, ledOn);

                bPressAccepted = true; // et on enregistre l'appuis sur le BP
            }
        }
        else { // BP relaché -> on remet a 0 tout les indicateurs
            transientPeriodStarted = false;
            bPressAccepted = false;
        }
    }


----

Plus simple ?
=============

Le code est lourd non ?

Il doit y avoir plus simple...

----

E/S analogiques
===============

----

Sorties

PWM : sortie analogique
Pas sur toutes les sorties, variable en fonction des models d'arduino

pas vrai analogique mais PWM

fonction analogWrite()

exemlpe de code heartbeat

----

entrées

que quelques entrées

value = analogRead();
valeur de 0 a 1024


----



:data-y: r1600
:data-x: r0

Interruptions
=============

----

:data-y: r0
:data-x: r1600

Concept
=======

- Permet de prendre en compte immédiatement un évènement.
- On :i:`attache` une routine d'interruption à une entrée...
- Sur Arduino, on a le choix entre les entrées 2 et 3 : on les appelle 0 et 1...
- On utilise la fonction ``attachInterrupt(pin, routine, mode)``
- 4 modes différents :

    - ``LOW``
    - ``CHANGE`` : trig. à chaque changement de niveau
    - ``RISING`` : trig. sur front montant
    - ``FALLING`` : trig. sur front descendant

- on ne peut utiliser :i:`que des variables volatile`

.. note::

    "Les variables partagées entre les fonction standard et les ISR (Routine de service d'interruption) doivent être
    déclarées "volatile". Cela explique au compilateur que ce genre de variable peut changer à tout moment et qu'il
    doit la recharger à chaque fois quelle est référencée, plutot que de se contenter d'une copie trouvée dans un registre processeur."

----

Interruptions : Exemple
=======================

.. code:: c

    int pin = 13;
    volatile int state = LOW;

    void setup() {
        pinMode(pin, OUTPUT);
        attachInterrupt(0, blink, CHANGE);
    }

    void loop() {
        digitalWrite(pin, state);
    }

    void blink() {
        state = !state;
    }

Simple non?

