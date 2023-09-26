#include "libs/cr.h"
#include <raylib.h>
#include <stdio.h>

CR_EXPORT int cr_main(struct cr_plugin *ctx, enum cr_op operation) {
  (void)ctx;
  (void)operation;

  static unsigned int CR_STATE frame_n = 0;
  frame_n++;

  BeginDrawing();
  ClearBackground(RAYWHITE);
  char buf[128];
  sprintf(buf, "%u\n", frame_n);
  DrawText(buf, 10, 10, 60, BLACK);
  EndDrawing();

  return 0;
}
