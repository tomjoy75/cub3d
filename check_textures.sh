#!/bin/bash

# Répertoire contenant les fichiers de texture
TEXTURES_DIR="textures"
# Liste des fichiers de texture à vérifier
TEXTURE_FILES=("sprite.xpm" "texture1.xpm" "texture2.xpm" "E.xpm")  # Ajoutez les noms des fichiers de texture que vous souhaitez vérifier

echo -e "\n------------CHECK TEXTURES-----------\n"

# Vérifier chaque fichier de texture
for texture in "${TEXTURE_FILES[@]}"; do
  TEXTURE_PATH="$TEXTURES_DIR/$texture"

  echo "Checking $TEXTURE_PATH..."

  # Vérifier que le fichier existe
  if [ ! -f "$TEXTURE_PATH" ]; then
    echo "Texture file $TEXTURE_PATH does not exist."
    continue
  fi

  # Vérifier que le fichier a les droits d'accès en lecture
  if [ ! -r "$TEXTURE_PATH" ]; then
    echo "Texture file $TEXTURE_PATH is not readable."
    continue
  fi

  # Vérifier que le fichier a les droits d'accès en écriture
  if [ ! -w "$TEXTURE_PATH" ]; then
    echo "Texture file $TEXTURE_PATH is not writable."
    continue
  fi

  # Vérifier que le fichier est bien un fichier .xpm
  file_output=$(file "$TEXTURE_PATH")
  if [[ "$file_output" != *"X pixmap image"* ]]; then
    echo "Texture file $TEXTURE_PATH is not a valid XPM file."
    continue
  fi

  # Vérifier que le fichier n'est pas vide
  if [ ! -s "$TEXTURE_PATH" ]; then
    echo "Texture file $TEXTURE_PATH is empty."
    continue
  fi

  echo "Texture file $TEXTURE_PATH is valid."
  echo "--------------------------------------"
done

echo -e "\n------------CHECK COMPLETED-----------\n"

