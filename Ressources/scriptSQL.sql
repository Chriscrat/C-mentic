CREATE DATABASE IF NOT EXISTS cmentic;

USE cmentic;

CREATE TABLE IF NOT EXISTS groupe (
  id_groupe int(6) NOT NULL AUTO_INCREMENT,
  nom_groupe varchar(255) NOT NULL,
  PRIMARY KEY (id_groupe)
);

CREATE TABLE IF NOT EXISTS groupetemps (
  id_temps int(6) NOT NULL,
  id_groupe int(6) NOT NULL,
  id_terminaison int(6) NOT NULL,
  PRIMARY KEY (id_temps,id_groupe)
);

CREATE TABLE IF NOT EXISTS irregulier (
  id_verbe int(6) NOT NULL,
  id_temps int(6) NOT NULL,
  id_terminaison int(6) NOT NULL,
  PRIMARY KEY (id_verbe,id_temps)
);

CREATE TABLE IF NOT EXISTS mot (
  id_mot int(6) NOT NULL AUTO_INCREMENT,
  mot varchar(255) NOT NULL,
  PRIMARY KEY (id_mot)
);

CREATE TABLE IF NOT EXISTS motliaison (
  id_motliaison int(6) NOT NULL AUTO_INCREMENT,
  mot varchar(255) NOT NULL,
  PRIMARY KEY (id_motliaison)
);

CREATE TABLE IF NOT EXISTS synonymeDe (
  id_synonyme int(6) NOT NULL,
  id_mot int(6) NOT NULL,
  PRIMARY KEY (id_synonyme, id_mot)
);

CREATE TABLE IF NOT EXISTS temps (
  id_temps int(6) NOT NULL AUTO_INCREMENT,
  nom_temps varchar(255) NOT NULL,
  PRIMARY KEY (id_temps)
);

CREATE TABLE IF NOT EXISTS terminaison (
  id_terminaison int(6) NOT NULL AUTO_INCREMENT,
  1Singulier varchar(255) NOT NULL,
  2Singulier varchar(255) NOT NULL,
  3Singulier varchar(255) NOT NULL,
  1Pluriel varchar(255) NOT NULL,
  2Pluriel varchar(255) NOT NULL,
  3Pluriel varchar(255) NOT NULL,
  PRIMARY KEY (id_terminaison)
);

CREATE TABLE IF NOT EXISTS verbe (
  id_verbe int(6) NOT NULL AUTO_INCREMENT,
  base varchar(255) NOT NULL,
  id_groupe int(6) NULL,
  PRIMARY KEY (id_verbe)
);


/* ------------------------------------------------------------------------------------

          INSERT

--------------------------------------------------------------------------------------- */



/* -----------------------------------

          MOTLIAISON

-------------------------------------- */

INSERT INTO motliaison (mot)
VALUES ('la');

INSERT INTO motliaison (mot)
VALUES ('vous');

INSERT INTO motliaison (mot)
VALUES ('mais');

INSERT INTO motliaison (mot)
VALUES ('ça');

INSERT INTO motliaison (mot)
VALUES ('ce');

INSERT INTO motliaison (mot)
VALUES ('pour');

INSERT INTO motliaison (mot)
VALUES ('des');

INSERT INTO motliaison (mot)
VALUES ('comme');

INSERT INTO motliaison (mot)
VALUES ('qui');

INSERT INTO motliaison (mot)
VALUES ('le');

INSERT INTO motliaison (mot)
VALUES ('un');

INSERT INTO motliaison (mot)
VALUES ('les');

INSERT INTO motliaison (mot)
VALUES ('au');

INSERT INTO motliaison (mot)
VALUES ('ses');

INSERT INTO motliaison (mot)
VALUES ('et');

INSERT INTO motliaison (mot)
VALUES ('du');

INSERT INTO motliaison (mot)
VALUES ('ces');

INSERT INTO motliaison (mot)
VALUES ('que');

INSERT INTO motliaison (mot)
VALUES ('elles');

INSERT INTO motliaison (mot)
VALUES ('en');

INSERT INTO motliaison (mot)
VALUES ('aussi');

INSERT INTO motliaison (mot)
VALUES ('à');

INSERT INTO motliaison (mot)
VALUES ('avec');

INSERT INTO motliaison (mot)
VALUES ('une');

INSERT INTO motliaison (mot)
VALUES ('nous');

INSERT INTO motliaison (mot)
VALUES ('votre');

/* -----------------------------------

          MOT

-------------------------------------- */

INSERT INTO mot (mot)
VALUES ('programmation');

INSERT INTO mot (mot)
VALUES ('code');



INSERT INTO mot (mot)
VALUES ('trop');

INSERT INTO mot (mot)
VALUES ('beaucoup');

INSERT INTO mot (mot)
VALUES ('énormément');

INSERT INTO mot (mot)
VALUES ('fort');

-- Ajouter très



INSERT INTO mot (mot)
VALUES ('très');

-- Ajouter bien


INSERT INTO mot (mot)
VALUES ('bien');

INSERT INTO mot (mot)
VALUES ('bon');



INSERT INTO mot (mot)
VALUES ('cours');

INSERT INTO mot (mot)
VALUES ('leçon');




INSERT INTO mot (mot)
VALUES ('débutants');

INSERT INTO mot (mot)
VALUES ('apprentis');

INSERT INTO mot (mot)
VALUES ('novices');



INSERT INTO mot (mot)
VALUES ('jamais');

INSERT INTO mot (mot)
VALUES ('pas');

INSERT INTO mot (mot)
VALUES ('aucun');



INSERT INTO mot (mot)
VALUES ('langage');

INSERT INTO mot (mot)
VALUES ('dialecte');

INSERT INTO mot (mot)
VALUES ('jargon');

INSERT INTO mot (mot)
VALUES ('langue');



INSERT INTO mot (mot)
VALUES ('langages');

INSERT INTO mot (mot)
VALUES ('dialectes');

INSERT INTO mot (mot)
VALUES ('jargons');

INSERT INTO mot (mot)
VALUES ('langues');




INSERT INTO mot (mot)
VALUES ('plus');

INSERT INTO mot (mot)
VALUES ('davantage');

INSERT INTO mot (mot)
VALUES ('encore');

INSERT INTO mot (mot)
VALUES ('mieux');




INSERT INTO mot (mot)
VALUES ('célèbres');

INSERT INTO mot (mot)
VALUES ('connus');

INSERT INTO mot (mot)
VALUES ('fameux');

INSERT INTO mot (mot)
VALUES ('notoires');

INSERT INTO mot (mot)
VALUES ('réputés');




INSERT INTO mot (mot)
VALUES ('monde');

INSERT INTO mot (mot)
VALUES ('univers');

INSERT INTO mot (mot)
VALUES ('terre');

INSERT INTO mot (mot)
VALUES ('planète');

INSERT INTO mot (mot)
VALUES ('gens');

INSERT INTO mot (mot)
VALUES ('societé');




INSERT INTO mot (mot)
VALUES ('notamment');

INSERT INTO mot (mot)
VALUES ('spécialement');

INSERT INTO mot (mot)
VALUES ('particulièrement');

INSERT INTO mot (mot)
VALUES ('singulièrement');




INSERT INTO mot (mot)
VALUES ('secteur');

INSERT INTO mot (mot)
VALUES ('domaine');

INSERT INTO mot (mot)
VALUES ('emplacement');

INSERT INTO mot (mot)
VALUES ('zone');




INSERT INTO mot (mot)
VALUES ('performances');

INSERT INTO mot (mot)
VALUES ('exploits');

INSERT INTO mot (mot)
VALUES ('records');




INSERT INTO mot (mot)
VALUES ('possibilités');

INSERT INTO mot (mot)
VALUES ('capacités');

INSERT INTO mot (mot)
VALUES ('potentialité');

INSERT INTO mot (mot)
VALUES ('opportunités');




INSERT INTO mot (mot)
VALUES ('désormais');

INSERT INTO mot (mot)
VALUES ('dès');

INSERT INTO mot (mot)
VALUES ('dorénavant');

INSERT INTO mot (mot)
VALUES ('sitôt');




INSERT INTO mot (mot)
VALUES ('incontournable');

INSERT INTO mot (mot)
VALUES ('inéluctable');

INSERT INTO mot (mot)
VALUES ('inévitable');




INSERT INTO mot (mot)
VALUES ('développeurs');

INSERT INTO mot (mot)
VALUES ('concepteurs');

INSERT INTO mot (mot)
VALUES ('créateurs');

INSERT INTO mot (mot)
VALUES ('informaticiens');

INSERT INTO mot (mot)
VALUES ('programmeurs');




INSERT INTO mot (mot)
VALUES ('descendant');

INSERT INTO mot (mot)
VALUES ('baissant');

INSERT INTO mot (mot)
VALUES ('diminuant');

INSERT INTO mot (mot)
VALUES ('tombant');





INSERT INTO mot (mot)
VALUES ('semblables');

INSERT INTO mot (mot)
VALUES ('comparables');

INSERT INTO mot (mot)
VALUES ('ressemblants');

INSERT INTO mot (mot)
VALUES ('équivalents');

INSERT INTO mot (mot)
VALUES ('similaires');




INSERT INTO mot (mot)
VALUES ('premier');

INSERT INTO mot (mot)
VALUES ('initial');

INSERT INTO mot (mot)
VALUES ('originel');




INSERT INTO mot (mot)
VALUES ('abord');

INSERT INTO mot (mot)
VALUES ('auparavant');

INSERT INTO mot (mot)
VALUES ('premièrement');

INSERT INTO mot (mot)
VALUES ('contact');




INSERT INTO mot (mot)
VALUES ('néanmoins');

INSERT INTO mot (mot)
VALUES ('cependant');

INSERT INTO mot (mot)
VALUES ('malgré');

INSERT INTO mot (mot)
VALUES ('pourtant');




INSERT INTO mot (mot)
VALUES ('différents');

INSERT INTO mot (mot)
VALUES ('autres');

INSERT INTO mot (mot)
VALUES ('disparates');

INSERT INTO mot (mot)
VALUES ('divergents');



INSERT INTO mot (mot)
VALUES ('nouvelles');

INSERT INTO mot (mot)
VALUES ('neuves');

INSERT INTO mot (mot)
VALUES ('inédites');

INSERT INTO mot (mot)
VALUES ('inattendue');

INSERT INTO mot (mot)
VALUES ('originale');



INSERT INTO mot (mot)
VALUES ('fonctionnalités');

INSERT INTO mot (mot)
VALUES ('proprietés');

INSERT INTO mot (mot)
VALUES ('fonctions');




INSERT INTO mot (mot)
VALUES ('puissant');

INSERT INTO mot (mot)
VALUES ('dominant');

INSERT INTO mot (mot)
VALUES ('influent');

INSERT INTO mot (mot)
VALUES ('fort');




INSERT INTO mot (mot)
VALUES ('programmer');

INSERT INTO mot (mot)
VALUES ('coder');

INSERT INTO mot (mot)
VALUES ('développer');



INSERT INTO mot (mot)
VALUES ('apporche');

INSERT INTO mot (mot)
VALUES ('vision');

INSERT INTO mot (mot)
VALUES ('venue');



INSERT INTO mot (mot)
VALUES ('différente');

INSERT INTO mot (mot)
VALUES ('disparates');

INSERT INTO mot (mot)
VALUES ('divergentes');



INSERT INTO mot (mot)
VALUES ('bibliothèque');

INSERT INTO mot (mot)
VALUES ('librairie');




INSERT INTO mot (mot)
VALUES ('large');

INSERT INTO mot (mot)
VALUES ('ample');

INSERT INTO mot (mot)
VALUES ('étendu');

INSERT INTO mot (mot)
VALUES ('grand');

INSERT INTO mot (mot)
VALUES ('important');



INSERT INTO mot (mot)
VALUES ('éventail');

INSERT INTO mot (mot)
VALUES ('gamme');




INSERT INTO mot (mot)
VALUES ('créer');

INSERT INTO mot (mot)
VALUES ('construire');

INSERT INTO mot (mot)
VALUES ('élaborer');

INSERT INTO mot (mot)
VALUES ('réaliser');



INSERT INTO mot (mot)
VALUES ('fenêtres');

INSERT INTO mot (mot)
VALUES ('interface');




INSERT INTO mot (mot)
VALUES ('menus');

INSERT INTO mot (mot)
VALUES ('options');

INSERT INTO mot (mot)
VALUES ('choix');



INSERT INTO mot (mot)
VALUES ('utiliser');

INSERT INTO mot (mot)
VALUES ('employer');

INSERT INTO mot (mot)
VALUES ('servir');

INSERT INTO mot (mot)
VALUES ('appliquer');




INSERT INTO mot (mot)
VALUES ('réseau');

INSERT INTO mot (mot)
VALUES ('chaîne');




INSERT INTO mot (mot)
VALUES ('ordinateur');

INSERT INTO mot (mot)
VALUES ('station');

INSERT INTO mot (mot)
VALUES ('appareil');

INSERT INTO mot (mot)
VALUES ('PC');



/* -----------------------------------

          SYNONYMEDE

-------------------------------------- */

INSERT INTO synonymeDe
VALUES (1, 2);

INSERT INTO synonymeDe
VALUES (3, 4);

INSERT INTO synonymeDe
VALUES (3, 5);

INSERT INTO synonymeDe
VALUES (3, 6);

INSERT INTO synonymeDe
VALUES (3, 7);

INSERT INTO synonymeDe
VALUES (7, 8);

INSERT INTO synonymeDe
VALUES (8, 9);

INSERT INTO synonymeDe
VALUES (10, 11); 

INSERT INTO synonymeDe
VALUES (12, 13);

INSERT INTO synonymeDe
VALUES (12, 14);

INSERT INTO synonymeDe
VALUES (15, 16);

INSERT INTO synonymeDe
VALUES (15, 17);

INSERT INTO synonymeDe
VALUES (18, 19);

INSERT INTO synonymeDe
VALUES (18, 20);

INSERT INTO synonymeDe
VALUES (19, 21);

INSERT INTO synonymeDe
VALUES (22, 23);

INSERT INTO synonymeDe
VALUES (22, 24);

INSERT INTO synonymeDe
VALUES (22, 25);

INSERT INTO synonymeDe
VALUES (26, 27);

INSERT INTO synonymeDe
VALUES (26, 28);

INSERT INTO synonymeDe
VALUES (26, 29);

INSERT INTO synonymeDe
VALUES (30, 31);

INSERT INTO synonymeDe
VALUES (30, 32);

INSERT INTO synonymeDe
VALUES (30, 33);

INSERT INTO synonymeDe
VALUES (30, 34);

INSERT INTO synonymeDe
VALUES (35, 36);

INSERT INTO synonymeDe
VALUES (35, 37);

INSERT INTO synonymeDe
VALUES (35, 38);

INSERT INTO synonymeDe
VALUES (35, 39);

INSERT INTO synonymeDe
VALUES (35, 40);

INSERT INTO synonymeDe
VALUES (41, 42);

INSERT INTO synonymeDe
VALUES (41, 43);

INSERT INTO synonymeDe
VALUES (41, 44);

INSERT INTO synonymeDe
VALUES (45, 46);

INSERT INTO synonymeDe
VALUES (45, 47);

INSERT INTO synonymeDe
VALUES (45, 48);

INSERT INTO synonymeDe
VALUES (49, 50);

INSERT INTO synonymeDe
VALUES (49, 51);

INSERT INTO synonymeDe
VALUES (52, 53);

INSERT INTO synonymeDe
VALUES (52, 54);

INSERT INTO synonymeDe
VALUES (52, 55);

INSERT INTO synonymeDe
VALUES (56, 57);

INSERT INTO synonymeDe
VALUES (56, 58);

INSERT INTO synonymeDe
VALUES (56, 59);

INSERT INTO synonymeDe
VALUES (60, 61);

INSERT INTO synonymeDe
VALUES (60, 62);

INSERT INTO synonymeDe
VALUES (63, 64);

INSERT INTO synonymeDe
VALUES (63, 65);

INSERT INTO synonymeDe
VALUES (63, 66);

INSERT INTO synonymeDe
VALUES (63, 67);

INSERT INTO synonymeDe
VALUES (68, 69);

INSERT INTO synonymeDe
VALUES (68, 70);

INSERT INTO synonymeDe
VALUES (68, 71);

INSERT INTO synonymeDe
VALUES (72, 73);

INSERT INTO synonymeDe
VALUES (72, 74);

INSERT INTO synonymeDe
VALUES (72, 75);

INSERT INTO synonymeDe
VALUES (72, 76);

INSERT INTO synonymeDe
VALUES (77, 78);

INSERT INTO synonymeDe
VALUES (77, 79);

INSERT INTO synonymeDe
VALUES (80, 81);

INSERT INTO synonymeDe
VALUES (80, 82);

INSERT INTO synonymeDe
VALUES (80, 83);

INSERT INTO synonymeDe
VALUES (84, 85);

INSERT INTO synonymeDe
VALUES (84, 86);

INSERT INTO synonymeDe
VALUES (84, 87);

INSERT INTO synonymeDe
VALUES (88, 89);

INSERT INTO synonymeDe
VALUES (88, 90);

INSERT INTO synonymeDe
VALUES (88, 91);

INSERT INTO synonymeDe
VALUES (92, 93);

INSERT INTO synonymeDe
VALUES (92, 94);

INSERT INTO synonymeDe
VALUES (92, 95);

INSERT INTO synonymeDe
VALUES (92, 96);

INSERT INTO synonymeDe
VALUES (97, 98);

INSERT INTO synonymeDe
VALUES (97, 99);

INSERT INTO synonymeDe
VALUES (100, 101);

INSERT INTO synonymeDe
VALUES (100, 102);

INSERT INTO synonymeDe
VALUES (100, 103);

INSERT INTO synonymeDe
VALUES (104, 105);

INSERT INTO synonymeDe
VALUES (104, 106);

INSERT INTO synonymeDe
VALUES (107, 108);

INSERT INTO synonymeDe
VALUES (107, 109);

INSERT INTO synonymeDe
VALUES (110, 111);

INSERT INTO synonymeDe
VALUES (110, 112);

INSERT INTO synonymeDe
VALUES (113, 114);

INSERT INTO synonymeDe
VALUES (115, 116);

INSERT INTO synonymeDe
VALUES (115, 117);

INSERT INTO synonymeDe
VALUES (115, 118);

INSERT INTO synonymeDe
VALUES (115, 119);

INSERT INTO synonymeDe
VALUES (120, 121);

INSERT INTO synonymeDe
VALUES (122, 123);

INSERT INTO synonymeDe
VALUES (122, 124);

INSERT INTO synonymeDe
VALUES (122, 125);

INSERT INTO synonymeDe
VALUES (126, 127);

INSERT INTO synonymeDe
VALUES (128, 129);

INSERT INTO synonymeDe
VALUES (128, 130);

INSERT INTO synonymeDe
VALUES (131, 132);

INSERT INTO synonymeDe
VALUES (131, 133);

INSERT INTO synonymeDe
VALUES (131, 134);

INSERT INTO synonymeDe
VALUES (135, 136);

INSERT INTO synonymeDe
VALUES (137, 138);

INSERT INTO synonymeDe
VALUES (137, 139);

INSERT INTO synonymeDe
VALUES (137, 140);




/* -----------------------------------

          GROUPE

-------------------------------------- */

INSERT INTO groupe (nom_groupe)
VALUES ('Premier groupe');

INSERT INTO groupe (nom_groupe)
VALUES ('Deuxième groupe');

INSERT INTO groupe (nom_groupe)
VALUES ('Troisième groupe');



/* -----------------------------------

          TEMPS

-------------------------------------- */

INSERT INTO temps (nom_temps)
VALUES ('présent');

INSERT INTO temps (nom_temps)
VALUES ('imparfait');

INSERT INTO temps (nom_temps)
VALUES ('futur simple');



/* -----------------------------------

          Terminaison

-------------------------------------- */

-- Présent / Premier groupe
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('e', 'es', 'e', 'ons', 'ez', 'ent');

-- Présent / Deuxième groupe
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('is', 'is', 'it', 'issons', 'issez', 'issent');

-- Présent / Troisième groupe
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('s', 's', 't', 'ons', 'ez', 'ent');



-- Imparfait / Premier groupe
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('ais', 'ais', 'ait', 'ions', 'iez', 'aient');

-- Imparfait / Deuxième groupe
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('ais', 'ais', 'ait', 'ions', 'iez', 'aient');

-- Imparfait / Troisième groupe
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('ais', 'ais', 'ait', 'ions', 'iez', 'aient');



-- Futur Simple / Premier groupe
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('erai', 'eras', 'era', 'erons', 'erez', 'eront');

-- Futur Simple / Deuxième groupe
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('irai', 'iras', 'ira', 'irons', 'irez', 'iront');

-- Futur Simple / Troisième groupe
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('rai', 'ras', 'ra', 'rons', 'rez', 'ront');



/* -----------------------------------

          GroupeTemps

-------------------------------------- */


INSERT INTO groupetemps
VALUES (1, 1, 1);

INSERT INTO groupetemps
VALUES (1, 2, 2);

INSERT INTO groupetemps
VALUES (1, 3, 3);

INSERT INTO groupetemps
VALUES (2, 1, 4);

INSERT INTO groupetemps
VALUES (2, 2, 5);

INSERT INTO groupetemps
VALUES (2, 3, 6);

INSERT INTO groupetemps
VALUES (3, 1, 7);

INSERT INTO groupetemps
VALUES (3, 2, 8);

INSERT INTO groupetemps
VALUES (3, 3, 9);



/* -----------------------------------

          Verbe

-------------------------------------- */

INSERT INTO verbe (base, id_groupe)
VALUES ('interess', 1);

INSERT INTO verbe (base, id_groupe)
VALUES ('programm', 1);

INSERT INTO verbe (base, id_groupe)
VALUES ('utilis', 1);

INSERT INTO verbe (base, id_groupe)
VALUES ('propos', 1);

INSERT INTO verbe (base, id_groupe)
VALUES ('ajout', 1);

INSERT INTO verbe (base, id_groupe)
VALUES ('appréci', 1);

-- Irréguliers

INSERT INTO verbe (base, id_groupe)
VALUES ('paraitre', NULL);

INSERT INTO verbe (base, id_groupe)
VALUES ('etre', NULL);

INSERT INTO verbe (base, id_groupe)
VALUES ('faire', NULL);

INSERT INTO verbe (base, id_groupe)
VALUES ('avoir', NULL);

INSERT INTO verbe (base, id_groupe)
VALUES ('permettre', NULL);

INSERT INTO verbe (base, id_groupe)
VALUES ('découvrir', NULL);

INSERT INTO verbe (base, id_groupe)
VALUES ('appeller', NULL);

INSERT INTO verbe (base, id_groupe)
VALUES ('aller', NULL);


/* -----------------------------------

          Terminaison irréguliers

-------------------------------------- */

-- Présent / Paraitre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('parais', 'parais', 'paraît', 'paraissons', 'paraissez', 'paraissent');

-- Imparfait / Paraitre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('paraissais', 'paraissais', 'paraissait', 'paraissions', 'paraissiez', 'paraissaient');

-- Future Simple / Paraitre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('paraîtrai', 'paraîtras', 'paraîtra', 'paraîtrons', 'paraîtrez', 'paraîtront');



-- Présent / Etre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('suis', 'es', 'est', 'sommes', 'êtes', 'sont');

-- Imparfait / Etre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('étais', 'étais', 'était', 'étions', 'étiez', 'étaient');

-- Future Simple / Etre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('serai', 'seras', 'sera', 'serons', 'serez', 'seront');




-- Présent / Faire
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('fais', 'fais', 'fais', 'faisons', 'faites', 'font');

-- Imparfait / Faire
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('faisais', 'faisais', 'faisait', 'faisions', 'faisiez', 'faisaient');

-- Future Simple / Faire
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('ferai', 'feras', 'fera', 'ferons', 'ferez', 'feront');




-- Présent / Avoir
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('ai', 'as', 'a', 'avons', 'avez', 'ont');

-- Imparfait / Avoir
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('avais', 'avais', 'avait', 'avions', 'aviez', 'avaient');

-- Future Simple / Avoir
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('aurai', 'auras', 'aura', 'aurons', 'aurez', 'auront');




-- Présent / Permettre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('permets', 'permets', 'permet', 'permettons', 'permettez', 'permettent');

-- Imparfait / Permettre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('permettais', 'permettais', 'permettait', 'permettions', 'permettiez', 'permettaient');

-- Future Simple / Permettre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('permettrai', 'permettras', 'permettra', 'permettrons', 'permettrez', 'permettront');




-- Présent / Découvrir
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('découvre', 'découvres', 'découvre', 'découvrons', 'découvrez', 'découvrent');

-- Imparfait / Permettre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('découvrais', 'découvrais', 'découvrait', 'découvrions', 'découvriez', 'découvraient');

-- Future Simple / Permettre
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('découvrirai', 'découvriras', 'découvrira', 'découvrirons', 'découvrirez', 'découvriront');




-- Présent / Appeler
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('appelle', 'appelles', 'appelle', 'appelons', 'appelez', 'appellent');

-- Imparfait / Appeler
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('appelais', 'appelais', 'appelait', 'appelions', 'appeliez', 'appelaient');

-- Future Simple / Appeler
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('appellerai', 'appelleras', 'appellera', 'appellerons', 'appellerez', 'appelleront');




-- Présent / Aller
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('vais', 'vas', 'va', 'allons', 'allez', 'vont');

-- Imparfait / Aller
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('allais', 'allais', 'allait', 'allions', 'alliez', 'allaient');

-- Future Simple / Aller
INSERT INTO terminaison (1singulier, 2singulier, 3singulier, 1pluriel, 2pluriel, 3pluriel)
VALUES ('irai', 'iras', 'ira', 'irons', 'irez', 'iront');



/* -----------------------------------

          Irregulier

-------------------------------------- */


INSERT INTO irregulier
VALUES (7, 1, 10);

INSERT INTO irregulier
VALUES (7, 2, 11);

INSERT INTO irregulier
VALUES (7, 3, 12);

INSERT INTO irregulier
VALUES (8, 1, 13);

INSERT INTO irregulier
VALUES (8, 2, 14);

INSERT INTO irregulier
VALUES (8, 3, 15);

INSERT INTO irregulier
VALUES (9, 1, 16);

INSERT INTO irregulier
VALUES (9, 2, 17);

INSERT INTO irregulier
VALUES (9, 3, 18);

INSERT INTO irregulier
VALUES (10, 1, 19);

INSERT INTO irregulier
VALUES (10, 2, 20);

INSERT INTO irregulier
VALUES (10, 3, 21);

INSERT INTO irregulier
VALUES (11, 1, 22);

INSERT INTO irregulier
VALUES (11, 2, 23);

INSERT INTO irregulier
VALUES (11, 3, 24);

INSERT INTO irregulier
VALUES (12, 1, 25);

INSERT INTO irregulier
VALUES (12, 2, 26);

INSERT INTO irregulier
VALUES (12, 3, 27);

INSERT INTO irregulier
VALUES (13, 1, 28);

INSERT INTO irregulier
VALUES (13, 2, 29);

INSERT INTO irregulier
VALUES (13, 3, 30);