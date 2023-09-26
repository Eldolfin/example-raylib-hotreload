#include "libs/cr.h"
#include <assert.h>
#include <raylib.h>
#include <stdio.h>
#include <stdlib.h>

#define ARRAY_LEN(A) (sizeof(A) / sizeof(A[0]))

int on_update(struct cr_plugin *ctx);

CR_EXPORT int cr_main(struct cr_plugin *ctx, enum cr_op operation) {
  (void)operation;
  assert(ctx);

  return on_update(ctx);
}

int on_update(struct cr_plugin *ctx) {
  (void)ctx;
  char buf[128];

  static unsigned int CR_STATE frame_n = 0;
  frame_n++;

  BeginDrawing();
  ClearBackground(RAYWHITE);
  sprintf(buf, "%u\n", frame_n);
  DrawText(buf, 10, 10, 60, BLACK);
  EndDrawing();

  return 0;
}
