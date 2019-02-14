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
  clear_screen(s);

  struct matrix * edges = new_matrix(4, 4);

  add_edge(edges, 100, 100, 0, 250, 300, 0);
  add_edge(edges, 250, 300, 0, 400, 100, 0);
  add_edge(edges, 400, 100, 0, 100, 100, 0);
  add_edge(edges, 175, 200, 0, 250, 225, 0);
  add_edge(edges, 325, 200, 0, 250, 225, 0);

  add_edge(edges, 175, 200, 0, 250, 175, 0);
  add_edge(edges, 325, 200, 0, 250, 175, 0);

  add_edge(edges, 250, 175, 0, 225, 200, 0);
  add_edge(edges, 250, 225, 0, 225, 200, 0);
  add_edge(edges, 250, 175, 0, 275, 200, 0);
  add_edge(edges, 250, 225, 0, 275, 200, 0);


  struct matrix * iden = new_matrix(4, 4);
  ident(iden);
  printf("Printing 4 x 4 identity matrix...\n");
  print_matrix(iden);

  printf("Printing edge matrix...\n");
  print_matrix(edges);

  printf("Multiplying identity matrix by edge matrix...(should have no effect)\n");
  matrix_mult(iden, edges); // Should have no effect

  printf("Printing new edge matrix...\n");
  print_matrix(edges);
  draw_lines(edges, s, c);

  printf("Drawing lines from edge matrix...\n");
  save_extension(s, "lines.png");
  printf("Image saved to lines.png\n");

  free_matrix( edges );
}
