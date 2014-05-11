

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

