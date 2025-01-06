#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
typedef long long f_t;
#define N(args) void args(f_t*o, f_t b, f_t a, f_t t, f_t s, f_t r, f_t d, f_t i)
#define EE o, b, a, t, s, r, d, i
typedef N((*n_t));
#include "Dependencies/Raylib/include/raylib.h"
#include<stdlib.h>

static N(Draw_0) { DrawRectangle(3, 3, 94, 34, o[t-5] ? *((Color*)&o[t-5]) : RAYWHITE ); }
static N(Draw_1) { Draw_0(EE); }
static N(Draw_2) { Draw_0(EE); DrawText(TextFormat("%s",   o[t+1]), 5, 5, 25, BLACK); }
static N(Draw_3) { Draw_0(EE); DrawText(TextFormat("%lld", o[t+1]), 5, 5, 25, BLACK); }
static N(Draw_4) { Draw_0(EE); DrawText(TextFormat("."),            5, 5, 25, BLACK); }
static N(Draw_5) { Draw_0(EE); DrawText(TextFormat("prn"),          5, 5, 25, BLACK); }
static float X(f_t t) { f_t x = ((t % (1 << 8)) / 11); return (float)x; }
static float Y(f_t t) { f_t y = (t / (1 << 8)); return (float)y; }
static N(Draw_Begin) {
  f_t selected = t;
  while(1) {
    BeginDrawing();
    ClearBackground(GRAY);
    for(t = 0; t < s; ) {
      Camera2D camera = { .target = {0, 0}, .rotation = 0, .zoom = 1, .offset = {X(t) * 100, Y(t) * 40}};
      BeginMode2D(camera);

      static n_t nars[] = { Draw_0, Draw_1, Draw_2, Draw_3, Draw_4, Draw_5, };
      nars[o[t]](EE);

      EndMode2D();

      if (o[t += 11] == 0)
        t = ((t >> 8) + 1) << 8; 
    } 
    DrawRectangleLinesEx((Rectangle){X(selected)*100, Y(selected)*40, 100, 40}, 4,  BLACK);
    EndDrawing();
    int key = GetCharPressed();
    if(WindowShouldClose())
      CloseWindow(), exit(0);
    else if(key == 'n')
      return;
  }
}
N(Blue_ti   ) { *((Color*)&o[t-5]) = (Color) { 000, 000, 255, 255 }, Draw_Begin(EE); }
N(Green_ti  ) { *((Color*)&o[t-5]) = (Color) { 000, 128, 000, 255 }, Draw_Begin(EE); }
N(Yellow_ti ) { *((Color*)&o[t-5]) = (Color) { 255, 255, 000, 255 }, Draw_Begin(EE); }
N(Red_ti    ) { *((Color*)&o[t-5]) = (Color) { 255, 000, 000, 255 }, Draw_Begin(EE); }
N(Purple_ti ) { *((Color*)&o[t-5]) = (Color) { 128, 000, 128, 255 }, Draw_Begin(EE); }
N(Navy_ti   ) { *((Color*)&o[t-5]) = (Color) { 000, 000, 128, 255 }, Draw_Begin(EE); }
//
void init_ti() {
  SetTraceLogLevel(LOG_ERROR);
	InitWindow(720, 480, "Sophis Debugger");
}

