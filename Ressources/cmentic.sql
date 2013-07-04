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

CREATE TABLE IF NOT EXISTS synonyme (
  id_synonyme int(6) NOT NULL AUTO_INCREMENT,
  id_mot int(6) NOT NULL,
  synonyme varchar(255) NOT NULL,
  PRIMARY KEY (id_synonyme)
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
  id_groupe int(6) NOT NULL,
  PRIMARY KEY (id_verbe)
);
