:data-transition-duration: 1000
:skip-help: true
:css: css/style.css

.. role:: i
.. |---| unicode:: U+02015 .. em dash

.. title:: Formation Arduino : Part 1

----

Formation Arduino
=================

Partie 1 : Bases !
------------------

----

:id: sect_structure

Structure d'un programme
========================

Depuis la version 1 : programmes en ``.pde``

----

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

Sorties Numériques
==================

.. image:: imgs/sorties_num/ArduinoUno.jpg
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

Soluce :)
---------

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

Soluce :)
---------

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

