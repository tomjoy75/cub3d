#!/bin/bash

# Répertoire contenant les fichiers .cub
MAPS_DIR="tests/maps"
# Fichier exécutable
EXECUTABLE="./a.out"

# Vérifier que le répertoire existe
if [ ! -d "$MAPS_DIR" ]; then
  echo "Directory $MAPS_DIR does not exist."
  exit 1
fi

# Vérifier que l'exécutable existe
if [ ! -f "$EXECUTABLE" ]; then
  echo "Executable $EXECUTABLE does not exist."
  exit 1
fi

# Parcourir chaque fichier .cub dans le répertoire
for map in "$MAPS_DIR"/*.cub; do
  echo "Checking $map..."

  # Exécuter le programme et capturer la sortie d'erreur
  program_output=$("$EXECUTABLE" "$map" 2>&1)
  exit_status=$?

  # Afficher le message d'erreur si le programme a échoué
  if [ $exit_status -ne 0 ]; then
    echo "Error detected for $map"
    echo "Program error output:"
    echo "$program_output"
  else
    echo "No errors detected for $map"
  fi

  echo "--------------------------------------"
done

