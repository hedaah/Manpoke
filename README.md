MANPOKE

Manpoke est un jeu de plateforme 2D , inspiré de l’univers de la célèbre licence pokémon , vous incarnerez un dresseur et irez capturer les pokémons !


Installation
Prérequis :
    • Système d'exploitation Windows 10
    • Carte graphique NVIDIA ou AMD avec au moins 2 Go de mémoire vidéo
    • Processeur Intel Core i5 ou équivalent
    • 8 Go de mémoire vive

Installation :

Récupérer le dossier Manpoke sur le site web tommus , vous y trouverez tous les fichier nécessaire au lancement du jeu , compiler , lancez l’exécutable ./bin/sdl ,puis partez à l’aventure !




Comment jouer ?
	
Manpoke est un jeu 2D de type RPG, dans ce jeu vous incarnez un dresseur qui devra attraper tous les pokémons de la map afin de débloquer une porte qui lui permettra d’accéder à la prochaine map qui est le prochain niveau !
Voici les commandes du jeu :
-Touche gauche : déplacer le personnage vers la gauche.
-Touche droite : déplacer le personnage vers la droite.
-Touche haut : déplacer le personnage vers le haut.
-Touche bas : déplacer le personnage vers le bas.
-espace : attaquer


Problèmes connus et résolution
- Premier problème rencontré, les mouvements des entités héritantes de la classe Personne n’étaient pas lisses, ils se déplaçaient de case en case et le mouvement ne contenait aucunes animations.
Pour régler cela, nous avons lissé les mouvements de tel sorte que l’on se déplace de O.05x20=1 au lieu de 1 directement, ces déplacements pas à pas se produisent à chaque frames, ce qui fait que notre déplacement dure 1/3 secondes, pendant ce laps de temps on joue l’animation de mouvement, avec les différentes étapes de déplacements qui figurent sur nos images qui contiennent le dresseur ou les monstres avec toutes les directions et les étapes de mouvements.

- Deuxième problème rencontré, les collisions, en effet il fallait synchroniser la position du personnage par rapport au terrain afin de pouvoir gérer au mieux les collisions (est-ce que la tuile d’en face est un mur?), le terrain est un tableau 2D de char, mais la position du personnage est un Vect2D de double x et double y, il fallait donc faire la conversion des doubles vers les int pour ensuite accéder aux cases du terrain (exemple : ter[x][y]) , en effet, il arrivait qu’on avait des soucis de précisions ou de conversions (exemple : 7.9999 qui se transformait en 7 après la conversion en int, or, dans ce cas nous préférons avoir 8 donc il fallait constamment faire des conversions et des arrondies car les doubles n’ont pas une précision à 100 %, il pouvait arriver par moment que la position du dresseur était de 5.000000001 par exemple, il faut donc faire les corrections en temps réels.

- Troisième problème rencontré, l’utilisation d’un tableau dynamique pour gérer les monstres, en effet comme les monstres doivent disparaîtres il est judicieux d’utiliser un tableau dynamique pour les effacer complètement, et ne plus rendre leur image à l’écran ou bien calculer leur position à chaque frames.
Au départ, on voulait utiliser la classe TableauDynamique créée en LIFAPSD mais le soucis c’était les chaînes d’inclusions qui menaient à certaines erreurs comme certaines classes héritent d’autre classe, il se produisait certaines erreurs dans lesquels le compilateur n’arrivait pas à savoir que certaines classes étaient déclarées. Nous avons donc utiliser directement la classe vector dans la classe Jeu pour éviter ces soucis d’inclusions.

Autres précisions

	Si vous souhaitez générer la documentation doxygen des fonctions, dirigez-vous vers le dossier doc en exécutant la commande cd doc, puis exécutez la commande doxygen manpoke.doxy