#include <raylib.h>
#include <stdio.h>

#define CR_HOST CR_UNSAFE
#include "./libs/cr.h"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  cr_plugin ctx;
  cr_plugin_open(ctx, "./built/plugin.dll");

  InitWindow(1920, 1080, "Hot reload with raylib example");
  while (!WindowShouldClose()) {
    cr_plugin_update(ctx);
  }
  CloseWindow();

  cr_plugin_close(ctx);
  return EXIT_SUCCESS;
}
