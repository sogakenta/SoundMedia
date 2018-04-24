#include <stdio.h>
#include <stdlib.h>
#include "wave.h"

int main(void)
{
    /* 音データのための構造体 */
    MONO_PCM pcm0, pcm1;
    int n;

    wave_read_16bit_mono(&pcm0, "sample_ja.wav"); /* 音データの入力 */

    /* コピー： pcm0 -> pcm1 */
    pcm1.fs = pcm0.fs; /* 標本化周波数 */
    pcm1.bits = pcm0.bits; /* 量子化精度 */
    pcm1.length = pcm0.length; /* 音データの長さ */
    pcm1.s = calloc(pcm1.length, sizeof(double)); /* 音データ */
    for (n = 0; n < pcm1.length; n++) {
        pcm1.s[n] = pcm0.s[n]; /* 音データのコピー */
    }

    wave_write_16bit_mono(&pcm1, "out.wav"); /* 音データの出力 */

    /* メモリの開放 */
    free(pcm0.s);
    free(pcm1.s);

    return 0;
}
