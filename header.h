#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int jam;
    int menit;
    int detik;
}waktu;

typedef struct
{
    char plat[50];
    char jenis;
    waktu waktu_awal;
    waktu waktu_akhir;
    waktu durasi;
    int biaya;
}data;
data data_app[];

int jumlah;
void menu_app ();
void back_menu ();
void input_data ();
void output_data ();
void durasi_waktu ();
void biaya ();
void urut_data ();
void urut_platASC ();
void urut_platDSC ();
void urut_biayaASC ();
void urut_biayaDSC ();
void urut_lamaASC ();
void urut_lamaDSC ();
void cari_data ();
void cari_plat ();
void cari_lama ();
void cari_waktumasuk ();
void cari_biaya ();
void data_ketemu (int idx_ketemu);
void hapus_data ();
void rata_rata ();

#endif // HEADER_H_INCLUDED
