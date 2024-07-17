#!/bin/bash

# Répertoire contenant les fichiers .cub
MAPS_DIR="maps"
#MAPS_DIR="maps"
# Fichier exécutable
EXECUTABLE="./cub3D"

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
  # Exécuter valgrind sur le fichier actuel
  valgrind_output=$(valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s "$EXECUTABLE" "$map" 2>&1)

  # Vérifier la présence du message "All heap blocks were freed -- no leaks are possible"
  if echo "$valgrind_output" | grep -q "All heap blocks were freed -- no leaks are possible"; then
    echo "No leaks detected for $map: SUCCESS"
  else
    echo "Leaks detected for $map: ERROR"
    echo "Valgrind output:"
    echo "$valgrind_output"
  fi
done

