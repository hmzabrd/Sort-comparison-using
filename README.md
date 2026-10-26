# Comparaison d'algorithmes de tri

## Description

Projet pédagogique d'analyse expérimentale des algorithmes de tri. Il mesure et compare le temps d'exécution de six méthodes de tri sur des tableaux d'entiers aléatoires de tailles croissantes, puis génère des fichiers de résultats CSV et des graphiques pour visualiser leur complexité et leurs performances.

Ce projet compare les performances de six algorithmes de tri implémentés en C :

- tri à bulles ;
- tri par insertion ;
- tri par sélection ;
- tri rapide (*quick sort*) ;
- tri fusion (*merge sort*) ;
- tri par tas (*heap sort*).

Le programme génère des tableaux d'entiers aléatoires, mesure le temps d'exécution de chaque algorithme et produit des fichiers de données ainsi que des graphiques avec Gnuplot.

## Prérequis

- [GCC](https://gcc.gnu.org/) ;
- `make` ;
- [Gnuplot](http://www.gnuplot.info/) dans le `PATH` pour générer les graphiques.

Le projet utilise le standard C11 et est compilé avec les options `-O2 -Wall`.

## Compilation

Depuis la racine du projet :

```powershell
make
```

Cette commande produit l'exécutable `benchmark.exe` ainsi que les fichiers objets intermédiaires.

## Exécution

```powershell
.\benchmark.exe
```

L'exécution peut prendre plusieurs minutes, en particulier pour les algorithmes en `O(n²)`. Le programme :

1. génère progressivement des tableaux aléatoires ;
2. exécute chaque tri trois fois pour chaque taille applicable ;
3. vérifie que le tableau est correctement trié ;
4. écrit les temps moyens en millisecondes ;
5. lance `gnuplot plot.gnu` pour créer les graphiques.

Si Gnuplot n'est pas installé ou n'est pas disponible dans le `PATH`, les mesures sont tout de même conservées, mais les graphiques ne sont pas générés.

## Tailles testées

Les tailles utilisées sont :

```text
10000, 20000, 30000, 50000, 75000, 100000,
250000, 500000, 750000, 1000000, 2500000,
5000000, 7500000, 10000000
```

Pour éviter des temps d'exécution excessifs, les tris à bulles, par insertion et par sélection sont limités à `n <= 100000`. Les tris rapide, fusion et par tas peuvent être testés jusqu'à `n = 10000000`.

## Résultats produits

Après l'exécution, les fichiers suivants sont créés :

- `data/results.csv` : résultats regroupés au format `algorithm,n,time_ms` ;
- `data/<algorithme>.dat` : mesures propres à chaque algorithme ;
- `graphs/graph_<algorithme>.png` : graphique individuel ;
- `graphs/graph_slow_sorts.png` : comparaison des tris en `O(n²)` ;
- `graphs/graph_fast_sorts.png` : comparaison des tris en `O(n log n)` ;
- `graphs/graph_all_sorts.png` : comparaison des six tris en échelle logarithmique.

Les répertoires `data/` et `graphs/`, ainsi que les fichiers compilés, sont ignorés par Git. Ils sont donc générés localement et ne sont pas nécessaires pour compiler le projet.

## Complexité théorique

| Algorithme | Meilleur cas | Cas moyen | Pire cas | Mémoire supplémentaire |
|---|---:|---:|---:|---:|
| Tri à bulles | `O(n²)` | `O(n²)` | `O(n²)` | `O(1)` |
| Tri par insertion | `O(n)` | `O(n²)` | `O(n²)` | `O(1)` |
| Tri par sélection | `O(n²)` | `O(n²)` | `O(n²)` | `O(1)` |
| Tri rapide | `O(n log n)` | `O(n log n)` | `O(n²)` | `O(log n)` en moyenne |
| Tri fusion | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(n)` |
| Tri par tas | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(1)` |

Les temps observés dépendent de la machine, du compilateur et de la charge du système. Ils servent principalement à comparer les tendances de croissance entre les algorithmes.

## Organisation du projet

```text
.
├── benchmark.c   # Programme de mesure et de génération des résultats
├── generate.c    # Génération et agrandissement des tableaux aléatoires
├── generate.h
├── sort.c        # Implémentation des six tris
├── sort.h
├── plot.gnu      # Scripts Gnuplot
├── Makefile
├── data/         # Résultats générés localement
└── graphs/       # Graphiques générés localement
```

## Licence

Aucune licence n'est actuellement spécifiée pour ce projet.
