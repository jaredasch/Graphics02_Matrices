#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  color c;
  c.red = 255;
  struct matrix *edges;


  
  edges = new_matrix(4, 4);
  add_edge(edges, 100, 100, 0, 250, 250, 0);
  add_edge(edges, 250, 250, 0, 400, 100, 0);
  add_edge(edges, 400, 100, 0, 100, 100, 0);

  draw_lines(edges, s, c);
  
  save_extension(s, "lines.png");

  print_matrix(edges);
  free_matrix( edges );
}  
