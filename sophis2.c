// clang-format off
#pragma GCC diagnostic ignored "-Wint-conversion"
#pragma GCC diagnostic ignored "-Wint-to-pointer-cast"
typedef long long f_t;
#define N(args) void args(f_t*ο, f_t β, f_t α, f_t τ, f_t σ, f_t ρ, f_t δ, f_t ι)
#define EE ο, β, α, τ, σ, ρ, δ, ι
typedef N((*n_t));

#define ob0(β)  ο[--ρ] = β,      \
                ο[ρ-1] = ο[β+3], \
                ο[ρ-2] = ο[β+2], \
                ο[ρ-3] = ο[β+1], \
                ο[ρ-4] = ρ+1,    \
                β = (ρ -= 4)
#define ob1(β)  ο[--ρ] = β,      \
                ο[ρ-1] = ο[β+3], \
                ο[ρ-2] = ο[β+2], \
                ο[ρ-3] = ρ+1,    \
                ο[ρ-4] = ο[β+0], \
                β = (ρ -= 4)
#define ob2(β)  ο[--ρ] = β,      \
                ο[ρ-1] = ο[β+3], \
                ο[ρ-2] = ρ+1,    \
                ο[ρ-3] = ο[β+1], \
                ο[ρ-4] = ο[β+0], \
                β = (ρ -= 4)
#define ob3(β)  ο[--ρ] = β,      \
                ο[ρ-1] = ρ+1,    \
                ο[ρ-2] = ο[β+2], \
                ο[ρ-3] = ο[β+1], \
                ο[ρ-4] = ο[β+0], \
                β = (ρ -= 4)
#define bo(...) {  f_t v[] = {__VA_ARGS__}, len = sizeof(v) / sizeof(*v); while (len) ο[--ρ] = v[--len]; }
#define οRed(...)   bo(__VA_ARGS__); ob3(β)
#define οYellow(...)bo(__VA_ARGS__); ob2(β)
#define οGreen(...) bo(__VA_ARGS__); ob1(β)
#define οBlue(...)  bo(__VA_ARGS__); ob0(β)

#define οMaroon(...)bo(__VA_ARGS__); ob3(α)
#define οOlive(...) bo(__VA_ARGS__); ob2(α)
#define οLime(...)  bo(__VA_ARGS__); ob1(α)
#define οNavy(...)  bo(__VA_ARGS__); ob0(α)

#define ΔRed(n)    ο[ο[β+3]+n]
#define ΔYellow(n) ο[ο[β+2]+n]
#define ΔGreen(n)  ο[ο[β+1]+n]
#define ΔBlue(n)   ο[ο[β+0]+n]

#define ΔMaroon(n) ο[ο[α+3]+n]
#define ιMaroon(n) ο[ο[ι+3]+n]
#define ΔOlive(n)  ο[ο[α+2]+n]
#define ΔLime(n)   ο[ο[α+1]+n]
#define ιLime(n)   ο[ο[ι+1]+n]
#define ΔNavy(n)   ο[ο[α+0]+n]

#define P printf("%9s (%lld,%lld) %lld %lld %lld %9s %lld %lld\n", __func__, (τ/(1<<8)), (τ%(1<<8))/11, α, β, ρ, (char*)ΔBlue(1), ΔBlue(2), ΔBlue(3))
#include<stdio.h>

N(Red     ) { n_t n = ΔRed(   0); β = ΔRed(   -1); n(EE); }
N(Yellow  ) { n_t n = ΔYellow(0); β = ΔYellow(-1); n(EE); }
N(Green   ) { n_t n = ΔGreen( 0); β = ΔGreen( -1); n(EE); }
N(Blue    ) { n_t n = ΔBlue(  0); β = ΔBlue(  -1); n(EE); }

N(Maroon  ) { n_t n = ΔMaroon(0); α = ΔMaroon(-1); n(EE); }
N(Maroonι ) { n_t n = ιMaroon(0); ι = ιMaroon(-1); n(EE); }
N(Olive   ) { n_t n = ΔOlive( 0); α = ΔOlive( -1); n(EE); }
N(Lime    ) { n_t n = ΔLime(  0); α = ΔLime(  -1); n(EE); }
N(Navy    ) { n_t n = ΔNavy(  0); α = ΔNavy(  -1); n(EE); }

#define one       ο[σ] = 1,               σ += 11,
#define two(a)    ο[σ] = 2, ο[σ + 1] = a, σ += 11,
#define three(a)  ο[σ] = 3, ο[σ + 1] = a, σ += 11,
#define four      ο[σ] = 4,               σ += 11,
#define five      ο[σ] = 5,               σ += 11,
#define align     ο[σ] = 0,               σ  = ((σ >> 8) + 1) << 8

N(Green_book);
enum names { S = 9, A, T, K, E, };
N(programS) {
  one three(S) five align;

  three(S) align;
  one two("b") four align;
  one three(S) two("a") four align;
  one three(S) two("t") four two("!") four align;
  οBlue(Blue, "bat!", 4, 0), Green_book(EE);
}
N(programE) {

  one three(E) five align;
  three(E) align;
  one three(E) two("+") three(E) four align;
//  one three(E) two("-") three(E) four align;
  one three(E) two("*") three(E) four align;
//  one three(E) two("/") three(E) four align;
//  one two("(") three(E) two(")") four align;
  one two("2") four align;
//  one two("3") four align;
  οBlue(Blue, "2+2*2", 5, 0), Green_book(EE);
}

N(dodo) { P; }
N(halted) { Yellow(EE); }

#define PS 5000
static f_t ram[PS + 1 + PS] = {0};
void init_ti();
int main() {
  init_ti();
  if (sizeof(f_t) != sizeof(void*))
    return printf("text member fingers are not sizeof(void*)!\n");
  f_t *ο = ram + PS;
  f_t β = 0;
  f_t α = 0;
  f_t τ = 0;
  f_t σ = 0;
  f_t ρ = PS;
  f_t δ = 1;
  f_t ι = 0;

  ο[--ρ] = 0;   ο[--ρ] = dodo; f_t ray = ρ; ο[--ρ] = 0;
  ο[--ρ] = ray; ο[--ρ] = ray;  ο[--ρ] = ray; ο[--ρ] = ray;
  β = α = ρ;
  οNavy(halted), programE(EE);
}

N(Yellow_book);
N(Blue_book);
N(Green_book);
N(Red_book);
N(Purple_book);
N(Navy_book);
#define CM(nar) nar
//(σ + (1 << 8) < ρ ? (nar) : Navy)
N(Yellow_31);
N(Purple_31);
N(Navy_3      ) { (ΔLime(1) == ο[τ + 1] ? Green       : Navy_book )(EE); }
N(clr_top     ) { (ιLime(1) == ο[τ + 1] ? Yellow      : Yellow_31 )(EE); }
N(clr         ) { (ιLime(1) == ο[τ + 1] ? Yellow      : Maroonι   )(EE); }
N(clr_top_Red ) { (ιLime(1) == ο[τ + 1] ? Green_book  : Purple_31 )(EE); }
N(clr_Red     ) { (ιLime(1) == ο[τ + 1] ? Yellow      : Maroonι   )(EE); }
N(search      ) { τ = σ, Navy_book(EE); }
N(re_tau      ) { τ = ΔLime(2), Lime(EE); }
N(Navy_name   ) { οNavy(Navy, τ), Blue_book(EE); }
N(Purple_31   ) {P; οLime(Green_book, ο[τ + 1], τ); οMaroon(clr_Red); οOlive(re_tau); οGreen(Red_book),  CM(search)(EE); }
N(Yellow_31   ) {P; οLime(Green_book, ο[τ + 1], τ); οMaroon(clr);     οOlive(re_tau); οGreen(Navy_name), CM(search)(EE); }
N(Green_3     ) {P; οLime(Green_book, ο[τ + 1], τ); οMaroon(clr_top); οOlive(re_tau); οGreen(Navy_name), CM(search)(EE); }

N(Yellow_3    ) {P; ι = α, Maroonι(EE); }
N(Purple_3    ) {P; ι = α, Maroonι(EE); }

N(cursor      ) { τ = ΔGreen(1),
                  α = ΔGreen(2),
                  ρ = ΔGreen(3),
                  Green(EE); }
N(Blue_1      ) {P; οGreen(Blue_book,   τ,        α, ρ); οYellow(cursor); CM(Yellow_book)(EE); }
N(Red_1       ) {P; οGreen(Red_book,    τ,        α, ρ); οYellow(cursor); CM(Purple_book)(EE); }
N(Green_4     ) {P; //οGreen(Green_book,  τ,        α, ρ); οYellow(cursor);
                  οMaroon(clr_top_Red);
                  οGreen(Red_book,    ΔNavy(1), α, ρ); οYellow(cursor); CM(Olive)(EE); }

//N(Green_2     ) { οRed(Red, ο[τ + 1]), CM(Green_book)(EE); }
N(Green_5     ) {P; f_t bo = β;
                  printf("\n");
                  while (ΔRed(1)) printf("%s", (char*)ΔRed(1)), β = ΔRed(-1);
                  printf("\n"), β = bo, Green_book(EE); }

N(Green_2     ) {P;
                  const char *t = ο[τ + 1];
                  const char *s = ΔBlue(1);
                  f_t length    = ΔBlue(2);
                  f_t pos       = ΔBlue(3);
                  if (pos < length && s[pos] == t[0]) {
                    οRed(Red, t);
                    οBlue(Blue, s, length, pos + 1);
                    static char buff[100]={0};
                    snprintf(buff, pos + 2, "%s", s);
                    printf("[%s] %s\n", buff, t);
                    Green_book(EE);
                  } else {
                    printf(" x %s\n", t);
                    Yellow(EE);
                  } }
N(Yellow_ti);
N(Yellow_book) {
  static n_t narg[5] = {
    [2] = Green_2,
    [3] = Yellow_3,
    [4] = Green_4,
  }; τ += 11,
             Yellow_ti(EE),
             narg[ο[τ]](EE);
}
N(Blue_ti);
N(Blue_book) {
  static n_t narg[5] = {
    [1] = Blue_1,
    [3] = Yellow,
    [0] = Yellow,
  }; τ += 1 << 8,
             Blue_ti(EE),
             narg[ο[τ]](EE);
}
N(Green_ti);
N(Green_book) {
  static n_t narg[6] = {
    [2] = Green_2,
    [4] = Green_4,
    [3] = Green_3,
    [5] = Green_5,
    [0] = Yellow,
  }; τ += 11,
             Green_ti(EE),
             narg[ο[τ]](EE);
}
N(Red_ti);
N(Red_book) {
  static n_t narg[5] = {
    [1] = Red_1,
    [3] = Yellow,
    [0] = Yellow,
  }; τ += 1 << 8, 
             Red_ti(EE),
             narg[ο[τ]](EE);
}
N(Purple_ti);
N(Purple_book) {
  static n_t narg[5] = {
    [3] = Purple_3,
    [2] = Yellow,
    [4] = Yellow,
  }; τ += 11, 
             Purple_ti(EE),
             narg[ο[τ]](EE);
}
N(Navy_ti);
N(Navy_book) {
  static n_t narg[5] = {
    [0] = Navy,
    [3] = Navy_3,
    [1] = Navy_book,
  }; τ -= 1 << 8,
             Navy_ti(EE),
             narg[ο[τ]](EE);
}
