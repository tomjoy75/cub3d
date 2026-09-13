# cub3D

A first-person raycasting engine in C, in the style of Wolfenstein 3D: a plain-text map file is
read from disk and drawn as a textured 3D world the player walks around in. A 42 project, built
on MiniLibX for the window and the pixel buffer, and nothing else.

There is no 3D geometry anywhere in it. Every frame casts one ray per screen column, finds the
first wall that ray meets, and draws a single vertical strip of texture whose height falls out
of the distance. Eight hundred columns, eight hundred rays.

## The map file

A `.cub` file is the entire input: four wall textures, a floor colour, a ceiling colour, and a
grid.

```
NO ./data/metal1.xpm
SO ./data/metal2.xpm
WE ./data/metal3.xpm
EA ./data/metal4.xpm

C 60, 70, 80
F 24, 34, 46

        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
111111111011000001110000000000001
100000000011000001110111111011111
11110111111111011100000010001
11000000110101011100000010001
10000000000000001100000010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111
```

`1` is wall, `0` is floor, a space is outside the map, and `N` is where the player starts and
which way they face.

The grid is not required to be rectangular, and that is most of why reading one is harder than
it looks. The map has to be proven **closed** — no walkable tile may touch the void — on a shape
with ragged edges, interior holes and lines of differing length. Getting that wrong is not a
cosmetic bug: a ray that escapes the map runs until it segfaults.

`maps/` holds 35 `invalid_*.cub` files. They exist to be rejected, and they are the more
interesting half of the directory: unclosed maps, duplicate identifiers, colours out of range,
missing textures, bad characters, empty files. `check_error_msg.sh`, `check_bonus_error_msg.sh`,
`check_textures.sh` and `check_memory_leaks.sh` run the binary against all of them and against
valgrind.

## Controls

| | |
|---|---|
| `W` `A` `S` `D` | strafe |
| `←` `→` | turn |
| mouse | turn |
| `Esc` | quit |
| `space` | open or close a door *(bonus)* |
| `M` | toggle the minimap *(bonus)* |

## Building

```sh
make          # walls, movement, textures
make bonus    # adds doors, animated sprites, the minimap and mouse look
./cub3D maps/metal.cub
```

MiniLibX is X11-based, so this wants Linux.

## Branches

| branch | what it is |
|---|---|
| `main` | the development history — 73 commits, June to July 2024 — plus the test scripts, the invalid-map fixtures and the subject PDFs. None of that was part of the hand-in. |
| `submitted` | the tree exactly as it was graded. It diverges from `main`: the last fixes (wall texture orientation, sprite timing, minimap redraw) never got pushed here, and the headers moved into `includes/`. |
| `wasm` | a WebAssembly port, in progress, so the engine runs in a browser. |

`main` is kept as the default because the history is the more useful thing to land on. The
graded artifact is on `submitted` and is not edited.

## Who wrote what

Two people, and the work divided cleanly:

- **Me** — all of the parsing and the map layer. Reading and validating the `.cub` file, the
  special cases, the linked list and the grid, allocation and deallocation, the error messages,
  the leak hunting, and the test scripts and fixtures above.
- **My teammate** — the raycasting. The mathematics of turning that grid into a view.

Code moved in both directions afterwards and neither half stayed sealed, but that is the shape
of it.

**The history on `main` is the evidence, and it is worth more than the file headers.** 47 of the
64 non-merge commits are mine, running continuously from 17 June: `Preparation de
l'environnement pour le parsing`, `Check des lignes du .cub valide`, `Creation of linked list`,
`allocate and implement the map`, `Implemented the check of the map`, `color parsing
normalisation`, `Correction of error messages`, `No more leaks`, `script valgrind over each
maps`. My teammate's 17 are the other side: `raycasting`, `hook`, `player direction fix`,
`fix ray int`, `fix texture orientation`, `Merge branch 'raycasting'`. One of my own commits
names the seam — `Adjustment to correspond to Jeremy's part of the prog`.

Two things in this repository will tell you otherwise, and both are artifacts rather than
records:

- **The 42 header banners** attribute 30 of 35 files to my teammate. The banner follows whoever
  created or last *saved* a file, so a pass that renames variables moves the name. Several files
  whose logic is mine carry his for that reason.
- **Raw line counts** favour him on `srcs/` for the same reason: his merge of the raycasting
  branch and the `cb_` prefix rename re-added moved code under his name.

Neither has been edited. They are left as they are, with this note, rather than tidied — the
commit log is checkable and that is the point.
