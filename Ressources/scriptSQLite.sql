CREATE DATABASE IF NOT EXISTS cmentic;

USE cmentic;

CREATE TABLE IF NOT EXISTS groupe (
  id_groupe integer NOT NULL PRIMARY KEY AUTOINCREMENT,
  nom_groupe varchar(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS groupetemps (
  id_temps integer NOT NULL,
  id_groupe integer NOT NULL,
  id_terminaison integer NOT NULL,
  PRIMARY KEY (id_temps,id_groupe)
);

CREATE TABLE IF NOT EXISTS irregulier (
  id_verbe integer NOT NULL,
  id_temps integer NOT NULL,
  id_terminaison integer NOT NULL,
  PRIMARY KEY (id_verbe,id_temps)
);

CREATE TABLE IF NOT EXISTS mot (
  id_mot integer NOT NULL PRIMARY KEY autoincrement,
  mot varchar(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS motliaison (
  id_motliaison integer NOT NULL PRIMARY KEY AUTOINCREMENT,
  mot varchar(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS synonymeDe (
  id_synonyme integer NOT NULL,
  id_mot integer NOT NULL
);

CREATE TABLE IF NOT EXISTS temps (
  id_temps integer NOT NULL PRIMARY KEY autoincrement,
  nom_temps varchar(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS terminaison (
  id_terminaison integer NOT NULL PRIMARY KEY autoincrement,
  nn1singulier varchar(255) NOT NULL,
  nn2singulier varchar(255) NOT NULL,
  nn3singulier varchar(255) NOT NULL,
  nn1pluriel varchar(255) NOT NULL,
  nn2pluriel varchar(255) NOT NULL,
  nn3pluriel varchar(255) NOT NULL
);

CREATE TABLE IF NOT EXISTS verbe (
  id_verbe integer NOT NULL PRIMARY KEY autoincrement,
  base varchar(255) NOT NULL,
  id_groupe integer NULL
);


/* ------------------------------------------------------------------------------------

          INSERT

--------------------------------------------------------------------------------------- */



/* -----------------------------------

          MOTLIAISON

-------------------------------------- */

INSERT into motliaison (mot)
VALUES ('la');

INSERT into motliaison (mot)
VALUES ('vous');

INSERT into motliaison (mot)
VALUES ('mais');

INSERT into motliaison (mot)
VALUES ('ça');

INSERT into motliaison (mot)
VALUES ('ce');

INSERT into motliaison (mot)
VALUES ('pour');

INSERT into motliaison (mot)
VALUES ('des');

INSERT into motliaison (mot)
VALUES ('comme');

INSERT into motliaison (mot)
VALUES ('qui');

INSERT into motliaison (mot)
VALUES ('le');

INSERT into motliaison (mot)
VALUES ('un');

INSERT into motliaison (mot)
VALUES ('les');

INSERT into motliaison (mot)
VALUES ('au');

INSERT into motliaison (mot)
VALUES ('ses');

INSERT into motliaison (mot)
VALUES ('et');

INSERT into motliaison (mot)
VALUES ('du');

INSERT into motliaison (mot)
VALUES ('ces');

INSERT into motliaison (mot)
VALUES ('que');

INSERT into motliaison (mot)
VALUES ('elles');

INSERT into motliaison (mot)
VALUES ('en');

INSERT into motliaison (mot)
VALUES ('aussi');

INSERT into motliaison (mot)
VALUES ('à');

INSERT into motliaison (mot)
VALUES ('avec');

INSERT into motliaison (mot)
VALUES ('une');

INSERT into motliaison (mot)
VALUES ('nous');

INSERT into motliaison (mot)
VALUES ('votre');

/* -----------------------------------

          MOT

-------------------------------------- */

INSERT into mot (mot)
VALUES ('programmation');

INSERT into mot (mot)
VALUES ('code');



INSERT into mot (mot)
VALUES ('trop');

INSERT into mot (mot)
VALUES ('beaucoup');

INSERT into mot (mot)
VALUES ('énormément');

INSERT into mot (mot)
VALUES ('fort');

-- Ajouter très



INSERT into mot (mot)
VALUES ('très');

-- Ajouter bien


INSERT into mot (mot)
VALUES ('bien');

INSERT into mot (mot)
VALUES ('bon');



INSERT into mot (mot)
VALUES ('cours');

INSERT into mot (mot)
VALUES ('leçon');




INSERT into mot (mot)
VALUES ('débutants');

INSERT into mot (mot)
VALUES ('apprentis');

INSERT into mot (mot)
VALUES ('novices');



INSERT into mot (mot)
VALUES ('jamais');

INSERT into mot (mot)
VALUES ('pas');

INSERT into mot (mot)
VALUES ('aucun');



INSERT into mot (mot)
VALUES ('langage');

INSERT into mot (mot)
VALUES ('dialecte');

INSERT into mot (mot)
VALUES ('jargon');

INSERT into mot (mot)
VALUES ('langue');



INSERT into mot (mot)
VALUES ('langages');

INSERT into mot (mot)
VALUES ('dialectes');

INSERT into mot (mot)
VALUES ('jargons');

INSERT into mot (mot)
VALUES ('langues');




INSERT into mot (mot)
VALUES ('plus');

INSERT into mot (mot)
VALUES ('davantage');

INSERT into mot (mot)
VALUES ('encore');

INSERT into mot (mot)
VALUES ('mieux');




INSERT into mot (mot)
VALUES ('célèbres');

INSERT into mot (mot)
VALUES ('connus');

INSERT into mot (mot)
VALUES ('fameux');

INSERT into mot (mot)
VALUES ('notoires');

INSERT into mot (mot)
VALUES ('réputés');




INSERT into mot (mot)
VALUES ('monde');

INSERT into mot (mot)
VALUES ('univers');

INSERT into mot (mot)
VALUES ('terre');

INSERT into mot (mot)
VALUES ('planète');

INSERT into mot (mot)
VALUES ('gens');

INSERT into mot (mot)
VALUES ('societé');




INSERT into mot (mot)
VALUES ('notamment');

INSERT into mot (mot)
VALUES ('spécialement');

INSERT into mot (mot)
VALUES ('particulièrement');

INSERT into mot (mot)
VALUES ('singulièrement');




INSERT into mot (mot)
VALUES ('secteur');

INSERT into mot (mot)
VALUES ('domaine');

INSERT into mot (mot)
VALUES ('emplacement');

INSERT into mot (mot)
VALUES ('zone');




INSERT into mot (mot)
VALUES ('performances');

INSERT into mot (mot)
VALUES ('exploits');

INSERT into mot (mot)
VALUES ('records');




INSERT into mot (mot)
VALUES ('possibilités');

INSERT into mot (mot)
VALUES ('capacités');

INSERT into mot (mot)
VALUES ('potentialité');

INSERT into mot (mot)
VALUES ('opportunités');




INSERT into mot (mot)
VALUES ('désormais');

INSERT into mot (mot)
VALUES ('dès');

INSERT into mot (mot)
VALUES ('dorénavant');

INSERT into mot (mot)
VALUES ('sitôt');




INSERT into mot (mot)
VALUES ('incontournable');

INSERT into mot (mot)
VALUES ('inéluctable');

INSERT into mot (mot)
VALUES ('inévitable');




INSERT into mot (mot)
VALUES ('développeurs');

INSERT into mot (mot)
VALUES ('concepteurs');

INSERT into mot (mot)
VALUES ('créateurs');

INSERT into mot (mot)
VALUES ('informaticiens');

INSERT into mot (mot)
VALUES ('programmeurs');




INSERT into mot (mot)
VALUES ('descendant');

INSERT into mot (mot)
VALUES ('baissant');

INSERT into mot (mot)
VALUES ('diminuant');

INSERT into mot (mot)
VALUES ('tombant');





INSERT into mot (mot)
VALUES ('semblables');

INSERT into mot (mot)
VALUES ('comparables');

INSERT into mot (mot)
VALUES ('ressemblants');

INSERT into mot (mot)
VALUES ('équivalents');

INSERT into mot (mot)
VALUES ('similaires');




INSERT into mot (mot)
VALUES ('premier');

INSERT into mot (mot)
VALUES ('initial');

INSERT into mot (mot)
VALUES ('originel');




INSERT into mot (mot)
VALUES ('abord');

INSERT into mot (mot)
VALUES ('auparavant');

INSERT into mot (mot)
VALUES ('premièrement');

INSERT into mot (mot)
VALUES ('contact');




INSERT into mot (mot)
VALUES ('néanmoins');

INSERT into mot (mot)
VALUES ('cependant');

INSERT into mot (mot)
VALUES ('malgré');

INSERT into mot (mot)
VALUES ('pourtant');




INSERT into mot (mot)
VALUES ('différents');

INSERT into mot (mot)
VALUES ('autres');

INSERT into mot (mot)
VALUES ('disparates');

INSERT into mot (mot)
VALUES ('divergents');



INSERT into mot (mot)
VALUES ('nouvelles');

INSERT into mot (mot)
VALUES ('neuves');

INSERT into mot (mot)
VALUES ('inédites');

INSERT into mot (mot)
VALUES ('inattendue');

INSERT into mot (mot)
VALUES ('originale');



INSERT into mot (mot)
VALUES ('fonctionnalités');

INSERT into mot (mot)
VALUES ('proprietés');

INSERT into mot (mot)
VALUES ('fonctions');




INSERT into mot (mot)
VALUES ('puissant');

INSERT into mot (mot)
VALUES ('dominant');

INSERT into mot (mot)
VALUES ('influent');

INSERT into mot (mot)
VALUES ('fort');




INSERT into mot (mot)
VALUES ('programmer');

INSERT into mot (mot)
VALUES ('coder');

INSERT into mot (mot)
VALUES ('développer');



INSERT into mot (mot)
VALUES ('apporche');

INSERT into mot (mot)
VALUES ('vision');

INSERT into mot (mot)
VALUES ('venue');



INSERT into mot (mot)
VALUES ('différente');

INSERT into mot (mot)
VALUES ('disparates');

INSERT into mot (mot)
VALUES ('divergentes');



INSERT into mot (mot)
VALUES ('bibliothèque');

INSERT into mot (mot)
VALUES ('librairie');




INSERT into mot (mot)
VALUES ('large');

INSERT into mot (mot)
VALUES ('ample');

INSERT into mot (mot)
VALUES ('étendu');

INSERT into mot (mot)
VALUES ('grand');

INSERT into mot (mot)
VALUES ('important');



INSERT into mot (mot)
VALUES ('éventail');

INSERT into mot (mot)
VALUES ('gamme');




INSERT into mot (mot)
VALUES ('créer');

INSERT into mot (mot)
VALUES ('construire');

INSERT into mot (mot)
VALUES ('élaborer');

INSERT into mot (mot)
VALUES ('réaliser');



INSERT into mot (mot)
VALUES ('fenêtres');

INSERT into mot (mot)
VALUES ('integererface');




INSERT into mot (mot)
VALUES ('menus');

INSERT into mot (mot)
VALUES ('options');

INSERT into mot (mot)
VALUES ('choix');



INSERT into mot (mot)
VALUES ('utiliser');

INSERT into mot (mot)
VALUES ('employer');

INSERT into mot (mot)
VALUES ('servir');

INSERT into mot (mot)
VALUES ('appliquer');




INSERT into mot (mot)
VALUES ('réseau');

INSERT into mot (mot)
VALUES ('chaîne');




INSERT into mot (mot)
VALUES ('ordinateur');

INSERT into mot (mot)
VALUES ('station');

INSERT into mot (mot)
VALUES ('appareil');

INSERT into mot (mot)
VALUES ('PC');



/* -----------------------------------

          SYNONYMEDE

-------------------------------------- */

INSERT into synonymeDe
VALUES (1, 2);

INSERT into synonymeDe
VALUES (3, 4);

INSERT into synonymeDe
VALUES (3, 5);

INSERT into synonymeDe
VALUES (3, 6);

INSERT into synonymeDe
VALUES (3, 7);

INSERT into synonymeDe
VALUES (7, 8);

INSERT into synonymeDe
VALUES (8, 9);

INSERT into synonymeDe
VALUES (10, 11); 

INSERT into synonymeDe
VALUES (12, 13);

INSERT into synonymeDe
VALUES (12, 14);

INSERT into synonymeDe
VALUES (15, 16);

INSERT into synonymeDe
VALUES (15, 17);

INSERT into synonymeDe
VALUES (18, 19);

INSERT into synonymeDe
VALUES (18, 20);

INSERT into synonymeDe
VALUES (19, 21);

INSERT into synonymeDe
VALUES (22, 23);

INSERT into synonymeDe
VALUES (22, 24);

INSERT into synonymeDe
VALUES (22, 25);

INSERT into synonymeDe
VALUES (26, 27);

INSERT into synonymeDe
VALUES (26, 28);

INSERT into synonymeDe
VALUES (26, 29);

INSERT into synonymeDe
VALUES (30, 31);

INSERT into synonymeDe
VALUES (30, 32);

INSERT into synonymeDe
VALUES (30, 33);

INSERT into synonymeDe
VALUES (30, 34);

INSERT into synonymeDe
VALUES (35, 36);

INSERT into synonymeDe
VALUES (35, 37);

INSERT into synonymeDe
VALUES (35, 38);

INSERT into synonymeDe
VALUES (35, 39);

INSERT into synonymeDe
VALUES (35, 40);

INSERT into synonymeDe
VALUES (41, 42);

INSERT into synonymeDe
VALUES (41, 43);

INSERT into synonymeDe
VALUES (41, 44);

INSERT into synonymeDe
VALUES (45, 46);

INSERT into synonymeDe
VALUES (45, 47);

INSERT into synonymeDe
VALUES (45, 48);

INSERT into synonymeDe
VALUES (49, 50);

INSERT into synonymeDe
VALUES (49, 51);

INSERT into synonymeDe
VALUES (52, 53);

INSERT into synonymeDe
VALUES (52, 54);

INSERT into synonymeDe
VALUES (52, 55);

INSERT into synonymeDe
VALUES (56, 57);

INSERT into synonymeDe
VALUES (56, 58);

INSERT into synonymeDe
VALUES (56, 59);

INSERT into synonymeDe
VALUES (60, 61);

INSERT into synonymeDe
VALUES (60, 62);

INSERT into synonymeDe
VALUES (63, 64);

INSERT into synonymeDe
VALUES (63, 65);

INSERT into synonymeDe
VALUES (63, 66);

INSERT into synonymeDe
VALUES (63, 67);

INSERT into synonymeDe
VALUES (68, 69);

INSERT into synonymeDe
VALUES (68, 70);

INSERT into synonymeDe
VALUES (68, 71);

INSERT into synonymeDe
VALUES (72, 73);

INSERT into synonymeDe
VALUES (72, 74);

INSERT into synonymeDe
VALUES (72, 75);

INSERT into synonymeDe
VALUES (72, 76);

INSERT into synonymeDe
VALUES (77, 78);

INSERT into synonymeDe
VALUES (77, 79);

INSERT into synonymeDe
VALUES (80, 81);

INSERT into synonymeDe
VALUES (80, 82);

INSERT into synonymeDe
VALUES (80, 83);

INSERT into synonymeDe
VALUES (84, 85);

INSERT into synonymeDe
VALUES (84, 86);

INSERT into synonymeDe
VALUES (84, 87);

INSERT into synonymeDe
VALUES (88, 89);

INSERT into synonymeDe
VALUES (88, 90);

INSERT into synonymeDe
VALUES (88, 91);

INSERT into synonymeDe
VALUES (92, 93);

INSERT into synonymeDe
VALUES (92, 94);

INSERT into synonymeDe
VALUES (92, 95);

INSERT into synonymeDe
VALUES (92, 96);

INSERT into synonymeDe
VALUES (97, 98);

INSERT into synonymeDe
VALUES (97, 99);

INSERT into synonymeDe
VALUES (100, 101);

INSERT into synonymeDe
VALUES (100, 102);

INSERT into synonymeDe
VALUES (100, 103);

INSERT into synonymeDe
VALUES (104, 105);

INSERT into synonymeDe
VALUES (104, 106);

INSERT into synonymeDe
VALUES (107, 108);

INSERT into synonymeDe
VALUES (107, 109);

INSERT into synonymeDe
VALUES (110, 111);

INSERT into synonymeDe
VALUES (110, 112);

INSERT into synonymeDe
VALUES (113, 114);

INSERT into synonymeDe
VALUES (115, 116);

INSERT into synonymeDe
VALUES (115, 117);

INSERT into synonymeDe
VALUES (115, 118);

INSERT into synonymeDe
VALUES (115, 119);

INSERT into synonymeDe
VALUES (120, 121);

INSERT into synonymeDe
VALUES (122, 123);

INSERT into synonymeDe
VALUES (122, 124);

INSERT into synonymeDe
VALUES (122, 125);

INSERT into synonymeDe
VALUES (126, 127);

INSERT into synonymeDe
VALUES (128, 129);

INSERT into synonymeDe
VALUES (128, 130);

INSERT into synonymeDe
VALUES (131, 132);

INSERT into synonymeDe
VALUES (131, 133);

INSERT into synonymeDe
VALUES (131, 134);

INSERT into synonymeDe
VALUES (135, 136);

INSERT into synonymeDe
VALUES (137, 138);

INSERT into synonymeDe
VALUES (137, 139);

INSERT into synonymeDe
VALUES (137, 140);




/* -----------------------------------

          GROUPE

-------------------------------------- */

INSERT into groupe (nom_groupe)
VALUES ('Premier groupe');

INSERT into groupe (nom_groupe)
VALUES ('Deuxième groupe');

INSERT into groupe (nom_groupe)
VALUES ('Troisième groupe');



/* -----------------------------------

          TEMPS

-------------------------------------- */

INSERT into temps (nom_temps)
VALUES ('présent');

INSERT into temps (nom_temps)
VALUES ('imparfait');

INSERT into temps (nom_temps)
VALUES ('futur simple');



/* -----------------------------------

          Terminaison

-------------------------------------- */

-- Présent / Premier groupe
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('e', 'es', 'e', 'ons', 'ez', 'ent');

-- Présent / Deuxième groupe
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('is', 'is', 'it', 'issons', 'issez', 'issent');

-- Présent / Troisième groupe
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('s', 's', 't', 'ons', 'ez', 'ent');



-- Imparfait / Premier groupe
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('ais', 'ais', 'ait', 'ions', 'iez', 'aient');

-- Imparfait / Deuxième groupe
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('ais', 'ais', 'ait', 'ions', 'iez', 'aient');

-- Imparfait / Troisième groupe
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('ais', 'ais', 'ait', 'ions', 'iez', 'aient');



-- Futur Simple / Premier groupe
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('erai', 'eras', 'era', 'erons', 'erez', 'eront');

-- Futur Simple / Deuxième groupe
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('irai', 'iras', 'ira', 'irons', 'irez', 'iront');

-- Futur Simple / Troisième groupe
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('rai', 'ras', 'ra', 'rons', 'rez', 'ront');



/* -----------------------------------

          GroupeTemps

-------------------------------------- */


INSERT into groupetemps
VALUES (1, 1, 1);

INSERT into groupetemps
VALUES (1, 2, 2);

INSERT into groupetemps
VALUES (1, 3, 3);

INSERT into groupetemps
VALUES (2, 1, 4);

INSERT into groupetemps
VALUES (2, 2, 5);

INSERT into groupetemps
VALUES (2, 3, 6);

INSERT into groupetemps
VALUES (3, 1, 7);

INSERT into groupetemps
VALUES (3, 2, 8);

INSERT into groupetemps
VALUES (3, 3, 9);



/* -----------------------------------

          Verbe

-------------------------------------- */

INSERT into verbe (base, id_groupe)
VALUES ('integereress', 1);

INSERT into verbe (base, id_groupe)
VALUES ('programm', 1);

INSERT into verbe (base, id_groupe)
VALUES ('utilis', 1);

INSERT into verbe (base, id_groupe)
VALUES ('propos', 1);

INSERT into verbe (base, id_groupe)
VALUES ('ajout', 1);

INSERT into verbe (base, id_groupe)
VALUES ('appréci', 1);

-- Irréguliers

INSERT into verbe (base, id_groupe)
VALUES ('paraitre', NULL);

INSERT into verbe (base, id_groupe)
VALUES ('etre', NULL);

INSERT into verbe (base, id_groupe)
VALUES ('faire', NULL);

INSERT into verbe (base, id_groupe)
VALUES ('avoir', NULL);

INSERT into verbe (base, id_groupe)
VALUES ('permettre', NULL);

INSERT into verbe (base, id_groupe)
VALUES ('découvrir', NULL);

INSERT into verbe (base, id_groupe)
VALUES ('appeller', NULL);

INSERT into verbe (base, id_groupe)
VALUES ('aller', NULL);


/* -----------------------------------

          Terminaison irréguliers

-------------------------------------- */

-- Présent / Paraitre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('parais', 'parais', 'paraît', 'paraissons', 'paraissez', 'paraissent');

-- Imparfait / Paraitre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('paraissais', 'paraissais', 'paraissait', 'paraissions', 'paraissiez', 'paraissaient');

-- Future Simple / Paraitre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('paraîtrai', 'paraîtras', 'paraîtra', 'paraîtrons', 'paraîtrez', 'paraîtront');



-- Présent / Etre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('suis', 'es', 'est', 'sommes', 'êtes', 'sont');

-- Imparfait / Etre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('étais', 'étais', 'était', 'étions', 'étiez', 'étaient');

-- Future Simple / Etre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('serai', 'seras', 'sera', 'serons', 'serez', 'seront');




-- Présent / Faire
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('fais', 'fais', 'fais', 'faisons', 'faites', 'font');

-- Imparfait / Faire
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('faisais', 'faisais', 'faisait', 'faisions', 'faisiez', 'faisaient');

-- Future Simple / Faire
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('ferai', 'feras', 'fera', 'ferons', 'ferez', 'feront');




-- Présent / Avoir
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('ai', 'as', 'a', 'avons', 'avez', 'ont');

-- Imparfait / Avoir
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('avais', 'avais', 'avait', 'avions', 'aviez', 'avaient');

-- Future Simple / Avoir
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('aurai', 'auras', 'aura', 'aurons', 'aurez', 'auront');




-- Présent / Permettre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('permets', 'permets', 'permet', 'permettons', 'permettez', 'permettent');

-- Imparfait / Permettre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('permettais', 'permettais', 'permettait', 'permettions', 'permettiez', 'permettaient');

-- Future Simple / Permettre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('permettrai', 'permettras', 'permettra', 'permettrons', 'permettrez', 'permettront');




-- Présent / Découvrir
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('découvre', 'découvres', 'découvre', 'découvrons', 'découvrez', 'découvrent');

-- Imparfait / Permettre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('découvrais', 'découvrais', 'découvrait', 'découvrions', 'découvriez', 'découvraient');

-- Future Simple / Permettre
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('découvrirai', 'découvriras', 'découvrira', 'découvrirons', 'découvrirez', 'découvriront');




-- Présent / Appeler
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('appelle', 'appelles', 'appelle', 'appelons', 'appelez', 'appellent');

-- Imparfait / Appeler
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('appelais', 'appelais', 'appelait', 'appelions', 'appeliez', 'appelaient');

-- Future Simple / Appeler
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('appellerai', 'appelleras', 'appellera', 'appellerons', 'appellerez', 'appelleront');




-- Présent / Aller
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('vais', 'vas', 'va', 'allons', 'allez', 'vont');

-- Imparfait / Aller
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('allais', 'allais', 'allait', 'allions', 'alliez', 'allaient');

-- Future Simple / Aller
INSERT into terminaison (n1singulier, n2singulier, n3singulier, n1pluriel, n2pluriel, n3pluriel)
VALUES ('irai', 'iras', 'ira', 'irons', 'irez', 'iront');



/* -----------------------------------

          Irregulier

-------------------------------------- */


INSERT into irregulier
VALUES (7, 1, 10);

INSERT into irregulier
VALUES (7, 2, 11);

INSERT into irregulier
VALUES (7, 3, 12);

INSERT into irregulier
VALUES (8, 1, 13);

INSERT into irregulier
VALUES (8, 2, 14);

INSERT into irregulier
VALUES (8, 3, 15);

INSERT into irregulier
VALUES (9, 1, 16);

INSERT into irregulier
VALUES (9, 2, 17);

INSERT into irregulier
VALUES (9, 3, 18);

INSERT into irregulier
VALUES (10, 1, 19);

INSERT into irregulier
VALUES (10, 2, 20);

INSERT into irregulier
VALUES (10, 3, 21);

INSERT into irregulier
VALUES (11, 1, 22);

INSERT into irregulier
VALUES (11, 2, 23);

INSERT into irregulier
VALUES (11, 3, 24);

INSERT into irregulier
VALUES (12, 1, 25);

INSERT into irregulier
VALUES (12, 2, 26);

INSERT into irregulier
VALUES (12, 3, 27);

INSERT into irregulier
VALUES (13, 1, 28);

INSERT into irregulier
VALUES (13, 2, 29);

INSERT into irregulier
VALUES (13, 3, 30);