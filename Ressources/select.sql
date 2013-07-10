-- Renvoi la liste des terminaison possibles
-- Si aucunes terminaisons ne corresponds, essayer le mot entier en tant que verbe irrégulier

SELECT terminaison.1singulier, terminaison.2singulier, terminaison.3singulier, terminaison.1pluriel, terminaison.2pluriel, terminaison.3pluriel
FROM groupetemps, terminaison
WHERE groupetemps.id_terminaison = terminaison.id_terminaison


-- Renvoi les conjugaison pour un verbe irrégulier
-- Si retourne 0 enregistrement, alors ce n'est pas un verbe

SELECT irregulier.id_temps, terminaison.1singulier, terminaison.2singulier, terminaison.3singulier, terminaison.1pluriel, terminaison.2pluriel, terminaison.3pluriel
FROM irregulier, terminaison
WHERE irregulier.id_terminaison = terminaison.id_terminaison
AND irregulier.id_verbe = (SELECT DISTINCT irregulier.id_verbe
						   FROM irregulier
						   WHERE irregulier.id_terminaison in (SELECT id_terminaison
															   FROM terminaison
															   WHERE
															   (1singulier = 'verbeirregulier'
															   OR 2singulier = 'verbeirregulier'
															   OR 3singulier = 'verbeirregulier'
															   OR 1pluriel = 'verbeirregulier'
															   OR 2pluriel = 'verbeirregulier'
															   OR 3pluriel = 'verbeirregulier')))


-- Renvoi les conjugaisons pour une base donnée

SELECT groupetemps.id_temps, terminaison.1singulier, terminaison.2singulier, terminaison.3singulier, terminaison.1pluriel, terminaison.2pluriel, terminaison.3pluriel
FROM verbe, groupetemps, terminaison
WHERE verbe.id_groupe = groupetemps.id_groupe
AND groupetemps.id_terminaison = terminaison.id_terminaison
AND verbe.base = 'mabasedeverbe'


-- Renvoi les mot de liaisons à eliminer du texte

SELECT mot
FROM motliaison


-- Renvoi les synonymes d'un mot
-- Si retourne 0 réponses, il n'y a pas de synonymes

SELECT mot
FROM mot, synonymede
WHERE mot.id_mot = synonymede.id_mot
AND synonymede.id_synonyme = (SELECT id_mot
							  FROM mot
							  WHERE mot = 'monmot')
UNION DISTINCT
SELECT mot
FROM mot, synonymede
WHERE mot.id_mot = synonymede.id_synonyme
AND synonymede.id_mot = (SELECT id_mot
						 FROM mot
						 WHERE mot = 'monmot')