# Filler

Filler is an algorithmic game which consists in filling a grid of a known size in advance with random-sized and random-shaped pieces. The pieces must overlap one or more of each other without exceeding the grid.

## Getting Started
```
git clone https://github.com/arkim42/filler.git
```
Build it by run `make` command where you cloned  

Run!
```
./resources/filler_vm -p1 [player1_name] -p2 [player2_name] -f [map_file_name]
```
> *Caution* <br>
> You should always put directory of where your player is. Otherwise, it gets error message.  
Do like this: `./arkim_filler` or `Your_directory/arkim_filler`

Sample maps are in `./resources/maps/` directory  
Sample players are in `./resources/players/` directory

➜ try `./resources/filler_vm -p1 ./arkim.filler -p2 resources/players/abanlin.filler  -f resources/maps/map00`


