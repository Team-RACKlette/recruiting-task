/*
 * ================================================================
 *  RACKlette Recruiting Task  --  Team RACKlette, ETH Zurich
 * ================================================================
 *
 *  Welcome! This small task is our way of getting to know you
 *  before the interview. It should take about 10-20 minutes.
 *  No prior HPC knowledge is required -- just curiosity and the
 *  ability to follow these instructions. :)
 *
 * ----------------------------------------------------------------
 *  What this program does
 * ----------------------------------------------------------------
 *  It multiplies two 64x64 matrices (A x B = C) using a technique
 *  called *tiled* (or blocked) matrix multiplication. Instead of
 *  iterating naively over every element, the computation is split
 *  into small square tiles that fit better in the CPU cache --
 *  a fundamental trick in High-Performance Computing.
 *
 *  After the multiplication it computes a checksum over the result
 *  and compares it to a magic value. When they match, you win!
 *
 * ----------------------------------------------------------------
 *  Your task
 * ----------------------------------------------------------------
 *  Find the correct value for TILE_SIZE (marked TODO below) and
 *  set it so the program prints the interview sign-up link.
 *
 *  Hint: A typical CPU cache line is 64 bytes wide.
 *        A double-precision floating-point number is 8 bytes.
 *        How many doubles fit in one cache line?
 *        That number is your TILE_SIZE.
 *
 *  Options to try: 1, 2, 4, 8, 16, 32, 64
 *
 * ----------------------------------------------------------------
 *  Steps
 * ----------------------------------------------------------------
 *  1. Clone the repo and open this file in a text editor.
 *  2. Change TILE_SIZE (see the TODO line below).
 *  3. Save, then run:  make
 *  4. Run:             ./task
 *  5. Repeat until the link appears!
 *
 * ================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdint.h>

#define N 64

/* ---------------------------------------------------------------
   TODO: Set TILE_SIZE to the correct value!
   --------------------------------------------------------------- */
#define TILE_SIZE 1     /* <-- change this */

static double A[N][N];
static double B[N][N];
static double C[N][N];

static void init_matrices(void)
{
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            A[i][j] = (double)(i + j + 1);
            B[i][j] = (double)(i * j + 1) / (N + 1);
        }
    memset(C, 0, sizeof(C));
}

/* Tiled matrix multiplication: C = A x B */
static void tiled_matmul(void)
{
    for (int ii = 0; ii < N; ii += TILE_SIZE)
        for (int kk = 0; kk < N; kk += TILE_SIZE)
            for (int jj = 0; jj < N; jj += TILE_SIZE)
                for (int i = ii; i < ii + TILE_SIZE; i++)
                    for (int k = kk; k < kk + TILE_SIZE; k++)
                        for (int j = jj; j < jj + TILE_SIZE; j++)
                            C[i][j] += A[i][k] * B[k][j];
}

static uint32_t compute_checksum(void)
{
    uint32_t cs = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int64_t val = (int64_t)(C[i][j] + 0.5);
            cs ^= (uint32_t)(val & 0xFFFFFFFFu);
            cs  = (cs << 5) | (cs >> 27);
        }
    /* The tile size is baked into the checksum -- choose wisely! */
    cs ^= (uint32_t)(TILE_SIZE * 0xDEADBEEFu);
    return cs;
}

#define MAGIC 0x3AED3326u

static const uint8_t ENCODED_LINK[] = {
    0x32, 0x2E, 0x2E, 0x2A, 0x29, 0x60, 0x75, 0x75,
    0x2D, 0x2D, 0x2D, 0x74, 0x29, 0x32, 0x33, 0x2C,
    0x33, 0x74, 0x33, 0x35, 0x75, 0x36, 0x75, 0x28,
    0x39, 0x31, 0x36, 0x2E, 0x2E, 0x68, 0x6C
};

#define LINK_LEN  (sizeof(ENCODED_LINK))
#define LINK_KEY  0x5A

static void print_link(void)
{
    char buf[LINK_LEN + 1];
    for (size_t i = 0; i < LINK_LEN; i++)
        buf[i] = (char)(ENCODED_LINK[i] ^ LINK_KEY);
    buf[LINK_LEN] = '\0';
    printf("    %s\n", buf);
}

int main(void)
{
    printf("======================================\n");
    printf("  RACKlette Recruiting Task\n");
    printf("  Team RACKlette -- ETH Zurich\n");
    printf("======================================\n\n");
    printf("Matrix size : %d x %d\n", N, N);
    printf("Tile size   : %d\n\n", TILE_SIZE);

    init_matrices();
    tiled_matmul();

    uint32_t cs = compute_checksum();
    printf("Your checksum : 0x%08X\n", cs);
    printf("Magic value   : 0x%08X\n\n", MAGIC);

    if (cs == MAGIC) {
        printf("Checksum matches -- well done!\n\n");
        printf("Sign up for your interview here:\n\n");
        print_link();
        printf("\nWe look forward to meeting you!\n");
    } else {
        printf("Not quite yet.\n");
        printf("Re-read the hint at the top of task.c,\n");
        printf("adjust TILE_SIZE, and try again.\n\n");
    }

    return 0;
}
