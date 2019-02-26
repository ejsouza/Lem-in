# Lem-in
`Lem-in` is a project where I had to implement **data structures** and create an algorithm 
for **traversing or searching** a tree or graph.

My algorithm is based on the [Breadth-first search (BFS) algorithm.](https://en.wikipedia.org/wiki/Breadth-first_search) <br />
First I created a two dimensional matrix for storing all the connections from point A to B, next the program start running <br />
and storing the shortest connection (path) in a `queue` (First In First Out), once the program is done doing so <br />
I only need to go backward in the `queue` to print the quickest way from point A to B.

## Goal
The goal of this project is to find the quickest way to get **N** ants across the farm.
Obviously, there are some basic constraints. To be the first to arrive, ants will need
to take the shortest path (and that isn’t necessarily the simplest). They will also
need to avoid traffic jams as well as walking all over their fellow ants.

At the beginning of the game, all the ants are in the room `start`. The goal is
to bring them to the room `end` with as few turns as possible. Each room can
only contain one ant at a time. (except at `start` and `end` which can contain
as many ants as necessary.)

## Output
I must display my results on the standard output in the following format: <br />
`number_of_ants`  <br />
`the_rooms`  <br />
`the_links`  <br />
`Lx-y Lz-w Lr-o ...`  <br />
x, z, r represents the ants numbers (going from 1 to number_of_ants) and y, <br />
w, o represents the rooms names. <br />
<pre>
  [0] <br />
  / \<br />
[1] [2]  <br />
|     | <br />
|   [3] <br />
 \   / <br />
  [4]
  
./lem-in < example.map
3
1 0 2
##start
0 2 0
##end
4 2 6
2 4 2
3 4 4
0-1
0-2
2-3
3-4
4-1

L1-1 L2-2
L1-4 L3-1 L2-3
L3-4 L2-4
</pre>
