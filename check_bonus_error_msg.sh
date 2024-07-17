#!/bin/bash

# Répertoire contenant les fichiers .cub
MAPS_DIR="maps"
# Fichier texture du sprite 
SPRITE="./textures/sprite.xpm"
# Fichier exécutable
EXECUTABLE="./cub3D"
# Fichier sans permission
NO_PERM_FILE="invalid_permission.cub"


echo -e "\n------------ONLY FOR BONUS-----------\n"
echo -e "\n------------INIT CHECKING-----------\n"
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

# Vérifier s'il n'y a pas d'argument
echo "Checking if no arg"
program_output=$("$EXECUTABLE" 2>&1)
exit_status=$?
if [ $exit_status -ne 0 ]; then
  echo "Error detected for $map"
  echo "Program error output:"
  echo "$program_output"
else
  echo "No errors detected for $map"
fi
echo "--------------------------------------"

# Vérifier s'il y a trop d'arguments
echo "Checking if too many args"
program_output=$("$EXECUTABLE" "$MAPS_DIR/valid_minimal.cub" "$MAPS_DIR/valid_smallest.cub" 2>&1)
exit_status=$?
if [ $exit_status -ne 0 ]; then
  echo "Error detected for $map"
  echo "Program error output:"
  echo "$program_output"
else
  echo "No errors detected for $map"
fi
echo "--------------------------------------"

# Vérifier s'il le fichier existe 
echo "Checking if file don't exist"
program_output=$("$EXECUTABLE" "$MAPS_DIR/valid_minimall.cub" 2>&1)
exit_status=$?
if [ $exit_status -ne 0 ]; then
  echo "Error detected for $map"
  echo "Program error output:"
  echo "$program_output"
else
  echo "No errors detected for $map"
fi
echo "--------------------------------------"

# Vérifier si on a les authorisations 
chmod 200 $MAPS_DIR/$NO_PERM_FILE 
echo "Checking if file is not accessible due to permissions"
program_output=$("$EXECUTABLE" "$MAPS_DIR/invalid_permission.cub" 2>&1)
exit_status=$?
if [ $exit_status -ne 0 ]; then
  echo "Error detected for $map"
  echo "Program error output:"
  echo "$program_output"
else
  echo "No errors detected for $map"
fi
chmod 644 $MAPS_DIR/$NO_PERM_FILE 
echo "--------------------------------------"

# Vérifier si l'extension est valide 
echo "Checking if file extension is not correct"
program_output=$("$EXECUTABLE" "$MAPS_DIR/valid_minimal.cube" 2>&1)
exit_status=$?
if [ $exit_status -ne 0 ]; then
  echo "Error detected for $map"
  echo "Program error output:"
  echo "$program_output"
else
  echo "No errors detected for $map"
fi
echo "--------------------------------------"
echo -e "\n----------CHECK SPRITE_TEXTURE-----------\n"

# Vérifier que le fichier sprite existe
if [ ! -f "$SPRITE" ]; then
  echo "Executable $SPRITE does not exist."
  exit 1
fi

# Vérifier que le fichier sprite a les droits d'acces
echo "Checking sprite file permissions"
if [ ! -r "$SPRITE" ]; then
  echo "Sprite file $SPRITE is not readable."
  exit 1
fi
if [ ! -w "$SPRITE" ]; then
  echo "Sprite file $SPRITE is not writable."
  exit 1
fi
if [ ! -x "$SPRITE" ]; then
  echo "Sprite file $SPRITE is not executable."
  exit 1
fi
echo "Sprite file permissions are correct."
echo "--------------------------------------"

# Vérifier que le fichier est bien un fichier .xpm
file_output=$(file "$TEXTURE_PATH")
if [[ "$file_output" != *"X pixmap image"* ]]; then
  echo "Texture file $TEXTURE_PATH is not a valid XPM file."
  continue
fi

# Vérifier que le fichier xpm du sprite est conforme

echo -e "\n------------CHECK ALL THE MAP-----------\n"

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

