#include "header.h"

// Prosedur untuk Menu Awal
void menu_app ()
{
    int cari;
    char cari_plat[50];
    puts("...:: Welcome to Parking System ::...");
    puts("----- MENU -----"); // daftar menu program
    puts("1. Inputkan Data");
    puts("2. Tampilkan Data");
    puts("3. Urutkan Data");
    puts("4. Cari Data");
    puts("5. Hapus Data");
    puts("6. Rata-rata Data");
    puts("7. Exit");
    printf("Pilih Menu : "); scanf("%d",&cari);
    switch (cari)
    {
        case 1:
            system("cls"); /// berfungsi untuk membersihkan layar program
            input_data();
            break;
        case 2:
            system("cls");
            output_data();
            break;
        case 3:
            system("cls");
            urut_data();
            break;
        case 4:
            system("cls");
            cari_data();
            break;
        case 5:
            system("cls");
            hapus_data();
            break;
        case 6:
            system("cls");
            rata_rata();
            break;
        case 7:
            break;
        default:
            printf("Opsi tidak ditemukan\n");
            break;
    }
}

// prosedur untuk kembali ke menu awal program
void back_menu ()
{
    int cari;
    puts("1. Back");
    puts("2. Exit");
    printf("Pilih Menu : "); scanf("%d",&cari);
    switch (cari)
    {
        case 1:
            system("cls");
            menu_app();
            break;
        case 2:
            break;
    }
}

// prosedur untuk menginputkan data
void input_data ()
{
    int x;
    int banyak;
    char repeat; /// variabel untuk menanpung apakah user mau menginputkan data lagi atau tidak
    printf("Banyak data yg ingin diinputkan\t: "); scanf("%d",&banyak);
    for (x=0;x<banyak;x++) /// Looping untuk menginputkan data
    {
        jumlah+=1; /// variabel untuk menampung banyaknya data yg masuk, dan +=1 agar variabel jumlah selalu bertambah setiap data ditambahkan
        printf("-> Data-%d\n",x+1);
        printf("Masukkan Nomor Plat Kendaraan\t\t: "); fflush(stdin); gets(data_app[jumlah-1].plat); /// jumlah -1 berfungsi sebagai index, dan jumlah-1 karena index array dimulai dari angka 0
        printf("Masukkan Jenis Kendaraan (S / M)\t: "); scanf("%c",&data_app[jumlah-1].jenis);
        fflush(stdin);
        printf("Masukkan Waktu Masuk Kendaraan\t\t\n");
        printf("Jam\t: "); scanf("%d",&data_app[jumlah-1].waktu_awal.jam);
        printf("Menit\t: "); scanf("%d",&data_app[jumlah-1].waktu_awal.menit);
        printf("Detik\t: "); scanf("%d",&data_app[jumlah-1].waktu_awal.detik);
        printf("Masukkan Waktu Keluar Kendaraan\t\t\n");
        printf("Jam\t: "); scanf("%d",&data_app[jumlah-1].waktu_akhir.jam);
        printf("Menit\t: "); scanf("%d",&data_app[jumlah-1].waktu_akhir.menit);
        printf("Detik\t: "); scanf("%d",&data_app[jumlah-1].waktu_akhir.detik);
        printf("\n");
        /// Prosedur untuk menghitung durasi waktu awal masuk dan waktu akhir keluar parkir
        durasi_waktu();
        /// Prosedur untuk menghitung total biaya yang harus dikeluarkan
        biaya();
    }
    fflush(stdin);
    tanya: /// label untuk pertanyaan dibawah apakah user ingin input lagi atau tidak
        printf("Apakah anda ingin input lagi (y/n) ? "); fflush(stdin); scanf("%c",&repeat);
        if (repeat == 'y' || repeat == 'Y') /// kondisi untuk user ingin input lagi atau tidak
        {
            // jika y / Y maka kembali ke prosedur input_data
            input_data();
        }
        else if (repeat == 'n' || repeat == 'N')
        {
            // jika n / N maka kembali ke menu awal program
            system("cls");
            menu_app();
        }
        else
        {
            // jika selain yang diatas maka kembali ke label pertanyaan
            goto tanya;
        }
}

// prosedur output sebuah data yang diinputkan
void output_data ()
{
    int x;
    puts("\t\t---- Data Kendaraan -----\n");
    for (x=0;x<jumlah;x++)
    {
        printf("Nomor Plat Kendaraan\t: %s\n",data_app[x].plat);
        printf("Jenis Kendaraan (S / M)\t: %c\n",data_app[x].jenis);
        printf("Waktu Masuk Kendaraan\t: %2d:%2d:%2d\n",data_app[x].waktu_awal.jam,data_app[x].waktu_awal.menit,data_app[x].waktu_awal.detik);
        printf("Waktu Keluar Kendaraan\t: %2d:%2d:%2d\n",data_app[x].waktu_akhir.jam,data_app[x].waktu_akhir.menit,data_app[x].waktu_akhir.detik);
        printf("Lama Parkir Kendaraan\t: %2d:%2d:%2d\n",data_app[x].durasi.jam,data_app[x].durasi.menit,data_app[x].durasi.detik);
        printf("Biaya Parkir Kendaraan\t: %d\n",data_app[x].biaya);
        printf("\n");
    }
    back_menu(); // prosedur kembali ke menu awal
}

// prosedur menghitung durasi waktu
void durasi_waktu ()
{
    int to_second; // variabel untuk menampung hasil dari waktu awal - waktu akhir, hasil berupa detik
    // kondisi jika jam awal lebih besar dari jam akhir
    if (data_app[jumlah-1].waktu_awal.jam > data_app[jumlah-1].waktu_akhir.jam)
    {
        data_app[jumlah-1].waktu_akhir.jam+=24; // misal jika jam awal 22 dan jam akhir 3 maka jam akhir ditambahkan 24 jam
    }
    // konversi waktu ke detik dan hitung jam akhir - jam awal
    to_second = ((data_app[jumlah-1].waktu_akhir.jam*3600 + data_app[jumlah-1].waktu_akhir.menit*60 + data_app[jumlah-1].waktu_akhir.detik) - (data_app[jumlah-1].waktu_awal.jam*3600 + data_app[jumlah-1].waktu_awal.menit*60 + data_app[jumlah-1].waktu_awal.detik));
    // menghitung lama parkir
    data_app[jumlah-1].durasi.jam = to_second / 3600;
    data_app[jumlah-1].durasi.menit = (to_second % 3600) / 60;
    data_app[jumlah-1].durasi.detik = (to_second % 3600) % 60;
}

// prosedur menghitung biaya parkir
void biaya ()
{
    // kondisi jika jenis kendaraan s / S
    if (data_app[jumlah-1].jenis == 's' || data_app[jumlah-1].jenis == 'S')
    {
        // biaya = durasi jam * 2000
        data_app[jumlah-1].biaya = data_app[jumlah-1].durasi.jam * 2000;
        // kondisi jika menit lebih dari nol
        if (data_app[jumlah-1].durasi.menit > 0)
        {
            // biaya bertambah 1000
            data_app[jumlah-1].biaya+=1000;
        }
    }
    // kondisi jika jenis kendaraan m / M
    else if (data_app[jumlah-1].jenis == 'm' || data_app[jumlah-1].jenis == 'M')
    {
        // biaya = durasi jam * 5000
        data_app[jumlah-1].biaya = data_app[jumlah-1].durasi.jam * 5000;
        // kondisi jika menit lebih dari nol
        if (data_app[jumlah-1].durasi.menit > 0)
        {
            // biaya bertambah 2000
            data_app[jumlah-1].biaya+=2000;
        }
    }
    // kondisi jika tidak keduanya
    else
    {
        // biaya = nol
        data_app[jumlah-1].biaya=0;
    }
}

// prosedur menu pengurutan data
void urut_data ()
{
    int cari;
    puts("Urutkan Data Berdasarkan");
    puts("1. Plat");
    puts("2. Biaya");
    puts("3. Lama Parkir");
    printf("Pilih Menu : "); scanf("%d",&cari);
    system("cls");
    switch (cari)
    {
        case 1:
            puts("-> Ascending");
            urut_platASC();
            puts("\n-> Descending");
            urut_platDSC();
            printf("\n");
            back_menu();
            break;
        case 2:
            puts("-> Ascending");
            urut_biayaASC();
            puts("\n-> Descending");
            urut_biayaDSC();
            printf("\n");
            back_menu();
            break;
        case 3:
            puts("-> Ascending");
            urut_lamaASC();
            puts("\n-> Descending");
            urut_lamaDSC();
            printf("\n");
            back_menu();
            break;
        default:
            printf("Menu tidak ditemukan\n");
            back_menu();
            break;
    }
}

// prosedur pengurutan plat nomor secara ascending
void urut_platASC ()
{
    int x,y;
    int i;
    char temp_jenis,temp[20];
    int temp_biaya;
    waktu temp_waktuawal;  // ADT waktu dibuat menjadi variable temporary waktu awal
    waktu temp_waktuakhir;  // ADT waktu dibuat menjadi variable temporary waktu akhir
    waktu temp_durasi;  // ADT waktu dibuat menjadi variable temporary durasi
    for (x=0;x<jumlah-1;x++)
    {
        for (y=0;y<jumlah-x-1;y++)
        {
            if (strcmpi(data_app[y].plat,data_app[y+1].plat) > 0) // kondisi jika data_app[i].plat lebih besar dari jika data_app[i+1].plat
            {
                // swap plat
                strcpy(temp,data_app[y].plat);
                strcpy(data_app[y].plat,data_app[y+1].plat);
                strcpy(data_app[y+1].plat,temp);
                // swap jenis
                temp_jenis=data_app[y].jenis;
                data_app[y].jenis=data_app[y+1].jenis;
                data_app[y+1].jenis=temp_jenis;
                // swap waktu awal
                temp_waktuawal=data_app[y].waktu_awal;
                data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                data_app[y+1].waktu_awal=temp_waktuawal;
                // swap waktu akhir
                temp_waktuakhir=data_app[y].waktu_akhir;
                data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                data_app[y+1].waktu_akhir=temp_waktuakhir;
                // swap durasi
                temp_durasi=data_app[y].durasi;
                data_app[y].durasi=data_app[y+1].durasi;
                data_app[y+1].durasi=temp_durasi;
                // swap biaya
                temp_biaya=data_app[y].biaya;
                data_app[y].biaya=data_app[y+1].biaya;
                data_app[y+1].biaya=temp_biaya;
            }
        }
    }
    for (i=0;i<jumlah;i++)
    {
        printf("Nomor Plat Kendaraan\t: %s\n",data_app[i].plat);
    }
}

// prosedur pengurutan plat nomor secara descending
void urut_platDSC ()
{
    int x,y;
    int i;
    char temp_jenis,temp[20];
    int temp_biaya;
    waktu temp_waktuawal;  // ADT waktu dibuat menjadi variable temporary waktu awal
    waktu temp_waktuakhir;  // ADT waktu dibuat menjadi variable temporary waktu akhir
    waktu temp_durasi;  // ADT waktu dibuat menjadi variable temporary durasi
    for (x=0;x<jumlah-1;x++)
    {
        for (y=0;y<jumlah-x-1;y++)
        {
            if (strcmpi(data_app[y].plat,data_app[y+1].plat) < 0) // kondisi jika data_app[i].plat lebih kecil dari jika data_app[i+1].plat
            {
                // swap plat
                strcpy(temp,data_app[y].plat);
                strcpy(data_app[y].plat,data_app[y+1].plat);
                strcpy(data_app[y+1].plat,temp);
                // swap jenis
                temp_jenis=data_app[y].jenis;
                data_app[y].jenis=data_app[y+1].jenis;
                data_app[y+1].jenis=temp_jenis;
                // swap waktu awal
                temp_waktuawal=data_app[y].waktu_awal;
                data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                data_app[y+1].waktu_awal=temp_waktuawal;
                // swap waktu akhir
                temp_waktuakhir=data_app[y].waktu_akhir;
                data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                data_app[y+1].waktu_akhir=temp_waktuakhir;
                // swap durasi
                temp_durasi=data_app[y].durasi;
                data_app[y].durasi=data_app[y+1].durasi;
                data_app[y+1].durasi=temp_durasi;
                // swap biaya
                temp_biaya=data_app[y].biaya;
                data_app[y].biaya=data_app[y+1].biaya;
                data_app[y+1].biaya=temp_biaya;
            }
        }
    }
    for (i=0;i<jumlah;i++)
    {
        printf("Nomor Plat Kendaraan\t: %s\n",data_app[i].plat);
    }
}

// prosedur pengurutan biaya secara ascending
void urut_biayaASC ()
{
    int x,y;
    int i;
    char temp_jenis,temp[20];
    int temp_biaya;
    waktu temp_waktuawal;  // ADT waktu dibuat menjadi variable temporary waktu awal
    waktu temp_waktuakhir;  // ADT waktu dibuat menjadi variable temporary waktu akhir
    waktu temp_durasi;  // ADT waktu dibuat menjadi variable temporary durasi
    for (x=0;x<jumlah-1;x++)
    {
        for (y=0;y<jumlah-x-1;y++)
        {
            if (data_app[y].biaya > data_app[y+1].biaya) // kondisi jika data_app[i].biaya lebih besar dari jika data_app[i+1].biaya
            {
                // swap plat
                strcpy(temp,data_app[y].plat);
                strcpy(data_app[y].plat,data_app[y+1].plat);
                strcpy(data_app[y+1].plat,temp);
                // swap jenis
                temp_jenis=data_app[y].jenis;
                data_app[y].jenis=data_app[y+1].jenis;
                data_app[y+1].jenis=temp_jenis;
                // swap waktu awal
                temp_waktuawal=data_app[y].waktu_awal;
                data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                data_app[y+1].waktu_awal=temp_waktuawal;
                // swap waktu akhir
                temp_waktuakhir=data_app[y].waktu_akhir;
                data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                data_app[y+1].waktu_akhir=temp_waktuakhir;
                // swap durasi
                temp_durasi=data_app[y].durasi;
                data_app[y].durasi=data_app[y+1].durasi;
                data_app[y+1].durasi=temp_durasi;
                // swap biaya
                temp_biaya=data_app[y].biaya;
                data_app[y].biaya=data_app[y+1].biaya;
                data_app[y+1].biaya=temp_biaya;
            }
        }
    }
    for (i=0;i<jumlah;i++)
    {
        printf("Biaya Parkir Kendaraan\t: %d\n",data_app[i].biaya);
    }
}

// prosedur pengurutan biaya secara descending
void urut_biayaDSC()
{
    int x,y;
    int i;
    char temp_jenis,temp[20];
    int temp_biaya;
    waktu temp_waktuawal;  // ADT waktu dibuat menjadi variable temporary waktu awal
    waktu temp_waktuakhir;  // ADT waktu dibuat menjadi variable temporary waktu akhir
    waktu temp_durasi;  // ADT waktu dibuat menjadi variable temporary durasi
    for (x=0;x<jumlah-1;x++)
    {
        for (y=0;y<jumlah-x-1;y++)
        {
            if (data_app[y].biaya < data_app[y+1].biaya) // kondisi jika data_app[i].biaya lebih kecil dari jika data_app[i+1].biaya
            {
                // swap plat
                strcpy(temp,data_app[y].plat);
                strcpy(data_app[y].plat,data_app[y+1].plat);
                strcpy(data_app[y+1].plat,temp);
                // swap jenis
                temp_jenis=data_app[y].jenis;
                data_app[y].jenis=data_app[y+1].jenis;
                data_app[y+1].jenis=temp_jenis;
                // swap waktu awal
                temp_waktuawal=data_app[y].waktu_awal;
                data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                data_app[y+1].waktu_awal=temp_waktuawal;
                // swap waktu akhir
                temp_waktuakhir=data_app[y].waktu_akhir;
                data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                data_app[y+1].waktu_akhir=temp_waktuakhir;
                // swap durasi
                temp_durasi=data_app[y].durasi;
                data_app[y].durasi=data_app[y+1].durasi;
                data_app[y+1].durasi=temp_durasi;
                // swap biaya
                temp_biaya=data_app[y].biaya;
                data_app[y].biaya=data_app[y+1].biaya;
                data_app[y+1].biaya=temp_biaya;
            }
        }
    }
    for (i=0;i<jumlah;i++)
    {
        printf("Biaya Parkir Kendaraan\t: %d\n",data_app[i].biaya);
    }
}

// prosedur pengurutan lama waktu secara ascending
void urut_lamaASC ()
{
    int x,y;
    int i;
    char temp_jenis,temp[20];
    int temp_biaya;
    waktu temp_waktuawal;  // ADT waktu dibuat menjadi variable temporary waktu awal
    waktu temp_waktuakhir;  // ADT waktu dibuat menjadi variable temporary waktu akhir
    waktu temp_durasi;  // ADT waktu dibuat menjadi variable temporary durasi
    for (x=0;x<jumlah-1;x++)
    {
        for (y=0;y<jumlah-x-1;y++)
        {
            if (data_app[x].durasi.jam > data_app[x+1].durasi.jam) // kondisi jika data_app[i].durasi.jam lebih besar dari data_app[i+1].durasi.jam
            {
                // swap plat
                strcpy(temp,data_app[y].plat);
                strcpy(data_app[y].plat,data_app[y+1].plat);
                strcpy(data_app[y+1].plat,temp);
                // swap jenis
                temp_jenis=data_app[y].jenis;
                data_app[y].jenis=data_app[y+1].jenis;
                data_app[y+1].jenis=temp_jenis;
                // swap waktu awal
                temp_waktuawal=data_app[y].waktu_awal;
                data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                data_app[y+1].waktu_awal=temp_waktuawal;
                // swap waktu akhir
                temp_waktuakhir=data_app[y].waktu_akhir;
                data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                data_app[y+1].waktu_akhir=temp_waktuakhir;
                // swap durasi
                temp_durasi=data_app[y].durasi;
                data_app[y].durasi=data_app[y+1].durasi;
                data_app[y+1].durasi=temp_durasi;
                // swap biaya
                temp_biaya=data_app[y].biaya;
                data_app[y].biaya=data_app[y+1].biaya;
                data_app[y+1].biaya=temp_biaya;
            }
            if (data_app[x].durasi.jam == data_app[x+1].durasi.jam) // kondisi jika data_app[i].durasi.jam sama dengan data_app[i+1].durasi.jam
                {
                    if (data_app[x].durasi.menit > data_app[x+1].durasi.menit) // kondisi jika data_app[i].durasi.menit lebih besar dari data_app[i+1].durasi.menit
                    {
                        // swap plat
                        strcpy(temp,data_app[y].plat);
                        strcpy(data_app[y].plat,data_app[y+1].plat);
                        strcpy(data_app[y+1].plat,temp);
                        // swap jenis
                        temp_jenis=data_app[y].jenis;
                        data_app[y].jenis=data_app[y+1].jenis;
                        data_app[y+1].jenis=temp_jenis;
                        // swap waktu awal
                        temp_waktuawal=data_app[y].waktu_awal;
                        data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                        data_app[y+1].waktu_awal=temp_waktuawal;
                        // swap waktu akhir
                        temp_waktuakhir=data_app[y].waktu_akhir;
                        data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                        data_app[y+1].waktu_akhir=temp_waktuakhir;
                        // swap durasi
                        temp_durasi=data_app[y].durasi;
                        data_app[y].durasi=data_app[y+1].durasi;
                        data_app[y+1].durasi=temp_durasi;
                        // swap biaya
                        temp_biaya=data_app[y].biaya;
                        data_app[y].biaya=data_app[y+1].biaya;
                        data_app[y+1].biaya=temp_biaya;
                    }
                    if (data_app[x].durasi.menit == data_app[x+1].durasi.menit) // kondisi jika data_app[i].durasi.menit sama dengan data_app[i+1].durasi.menit
                    {
                        if (data_app[x].durasi.detik > data_app[x+1].durasi.detik) // kondisi jika data_app[i].durasi.detik lebih besar dari data_app[i+1].durasi.detik
                        {
                            // swap plat
                            strcpy(temp,data_app[y].plat);
                            strcpy(data_app[y].plat,data_app[y+1].plat);
                            strcpy(data_app[y+1].plat,temp);
                            // swap jenis
                            temp_jenis=data_app[y].jenis;
                            data_app[y].jenis=data_app[y+1].jenis;
                            data_app[y+1].jenis=temp_jenis;
                            // swap waktu awal
                            temp_waktuawal=data_app[y].waktu_awal;
                            data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                            data_app[y+1].waktu_awal=temp_waktuawal;
                            // swap waktu akhir
                            temp_waktuakhir=data_app[y].waktu_akhir;
                            data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                            data_app[y+1].waktu_akhir=temp_waktuakhir;
                            // swap durasi
                            temp_durasi=data_app[y].durasi;
                            data_app[y].durasi=data_app[y+1].durasi;
                            data_app[y+1].durasi=temp_durasi;
                            // swap biaya
                            temp_biaya=data_app[y].biaya;
                            data_app[y].biaya=data_app[y+1].biaya;
                            data_app[y+1].biaya=temp_biaya;
                        }
                    }
                }
        }
    }
    for (i=0;i<jumlah;i++)
    {
        printf("Lama Parkir Kendaraan\t: %2d:%2d:%2d\n",data_app[i].durasi.jam,data_app[i].durasi.menit,data_app[i].durasi.detik);
    }
}

// prosedur pengurutan lama waktu secara descending
void urut_lamaDSC ()
{
    int x,y;
    int i;
    char temp_jenis,temp[20];
    int temp_biaya;
    waktu temp_waktuawal;  // ADT waktu dibuat menjadi variable temporary waktu awal
    waktu temp_waktuakhir;  // ADT waktu dibuat menjadi variable temporary waktu akhir
    waktu temp_durasi;  // ADT waktu dibuat menjadi variable temporary durasi
    for (x=0;x<jumlah-1;x++)
    {
        for (y=0;y<jumlah-x-1;y++)
        {
            if (data_app[x].durasi.jam < data_app[x+1].durasi.jam) // kondisi jika data_app[i].durasi.jam lebih kecil dari data_app[i+1].durasi.jam
            {
                // swap plat
                strcpy(temp,data_app[y].plat);
                strcpy(data_app[y].plat,data_app[y+1].plat);
                strcpy(data_app[y+1].plat,temp);
                // swap jenis
                temp_jenis=data_app[y].jenis;
                data_app[y].jenis=data_app[y+1].jenis;
                data_app[y+1].jenis=temp_jenis;
                // swap waktu awal
                temp_waktuawal=data_app[y].waktu_awal;
                data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                data_app[y+1].waktu_awal=temp_waktuawal;
                // swap waktu akhir
                temp_waktuakhir=data_app[y].waktu_akhir;
                data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                data_app[y+1].waktu_akhir=temp_waktuakhir;
                // swap durasi
                temp_durasi=data_app[y].durasi;
                data_app[y].durasi=data_app[y+1].durasi;
                data_app[y+1].durasi=temp_durasi;
                // swap biaya
                temp_biaya=data_app[y].biaya;
                data_app[y].biaya=data_app[y+1].biaya;
                data_app[y+1].biaya=temp_biaya;
            }
            if (data_app[x].durasi.jam == data_app[x+1].durasi.jam) // kondisi jika data_app[i].durasi.jam sama dengan data_app[i+1].durasi.jam
                {
                    if (data_app[x].durasi.menit < data_app[x+1].durasi.menit) // kondisi jika data_app[i].durasi.menit lebih kecil dari data_app[i+1].durasi.menit
                    {
                        // swap plat
                        strcpy(temp,data_app[y].plat);
                        strcpy(data_app[y].plat,data_app[y+1].plat);
                        strcpy(data_app[y+1].plat,temp);
                        // swap jenis
                        temp_jenis=data_app[y].jenis;
                        data_app[y].jenis=data_app[y+1].jenis;
                        data_app[y+1].jenis=temp_jenis;
                        // swap waktu awal
                        temp_waktuawal=data_app[y].waktu_awal;
                        data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                        data_app[y+1].waktu_awal=temp_waktuawal;
                        // swap waktu akhir
                        temp_waktuakhir=data_app[y].waktu_akhir;
                        data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                        data_app[y+1].waktu_akhir=temp_waktuakhir;
                        // swap durasi
                        temp_durasi=data_app[y].durasi;
                        data_app[y].durasi=data_app[y+1].durasi;
                        data_app[y+1].durasi=temp_durasi;
                        // swap biaya
                        temp_biaya=data_app[y].biaya;
                        data_app[y].biaya=data_app[y+1].biaya;
                        data_app[y+1].biaya=temp_biaya;
                    }
                    if (data_app[x].durasi.menit == data_app[x+1].durasi.menit) // kondisi jika data_app[i].durasi.menit sama dengan data_app[i+1].durasi.menit
                    {
                        if (data_app[x].durasi.detik < data_app[x+1].durasi.detik) // kondisi jika data_app[i].durasi.detik lebih kecil dari data_app[i+1].durasi.detik
                        {
                            // swap plat
                            strcpy(temp,data_app[y].plat);
                            strcpy(data_app[y].plat,data_app[y+1].plat);
                            strcpy(data_app[y+1].plat,temp);
                            // swap jenis
                            temp_jenis=data_app[y].jenis;
                            data_app[y].jenis=data_app[y+1].jenis;
                            data_app[y+1].jenis=temp_jenis;
                            // swap waktu awal
                            temp_waktuawal=data_app[y].waktu_awal;
                            data_app[y].waktu_awal=data_app[y+1].waktu_awal;
                            data_app[y+1].waktu_awal=temp_waktuawal;
                            // swap waktu akhir
                            temp_waktuakhir=data_app[y].waktu_akhir;
                            data_app[y].waktu_akhir=data_app[y+1].waktu_akhir;
                            data_app[y+1].waktu_akhir=temp_waktuakhir;
                            // swap durasi
                            temp_durasi=data_app[y].durasi;
                            data_app[y].durasi=data_app[y+1].durasi;
                            data_app[y+1].durasi=temp_durasi;
                            // swap biaya
                            temp_biaya=data_app[y].biaya;
                            data_app[y].biaya=data_app[y+1].biaya;
                            data_app[y+1].biaya=temp_biaya;
                        }
                    }
                }
        }
    }
    for (i=0;i<jumlah;i++)
    {
        printf("Lama Parkir Kendaraan\t: %2d:%2d:%2d\n",data_app[i].durasi.jam,data_app[i].durasi.menit,data_app[i].durasi.detik);
    }
}

// prosedur menu pencarian data
void cari_data ()
{
    int cari;
    puts("Cari Data Berdasarkan");
    puts("1. Plat");
    puts("2. Lama Parkir");
    puts("3. Waktu Masuk");
    puts("4. Biaya Termahal");
    printf("Pilih Menu : "); scanf("%d",&cari);
    system("cls");
    switch (cari)
    {
        case 1:
            cari_plat();
            back_menu();
            break;
        case 2:
            cari_lama();
            back_menu();
            break;
        case 3:
            cari_waktumasuk();
            back_menu();
        case 4:
            cari_biaya();
            back_menu();
            break;
        default:
            printf("Menu tidak ditemukan\n");
            back_menu();
            break;
    }
}

// prosedur pencarian data berdasarkan plat secara sequential
void cari_plat ()
{
    int i;
    int counter=0;
    char cariplat[20];
    printf("Masukkan Nomor Plat Kendaraan\t\t: "); fflush(stdin); gets(cariplat);
    for (i=0;i<jumlah;i++)
    {
        if (strcmpi(data_app[i].plat,cariplat) == 0) // kondisi jika data_app[i].plat sama dengan cari plat
        {
            puts("-> Data ditemukan\n");
            data_ketemu(i); // panggil prosedur data_ketemu diisi dengan parameter iteratornya
            counter=1; // counter = 1
        }
    }
    if (counter == 0) // kondisi jika counter == 0
    {
        printf("-> Data tidak ditemukan\n");
    }
}

// prosedur pencarian data berdasarkan lama waktu secara sequential
void cari_lama ()
{
    int lama=0,x;
    for (x=1;x<jumlah;x++)
    {
        if (data_app[x].durasi.jam > data_app[lama].durasi.jam) //kondisi jika data[x].durasi.jam lebih besar dari data_app[lama].durasi.jam
        {
            lama=x; // variabel lama sama dengan iterator
        }
        if (data_app[x].durasi.jam == data_app[lama].durasi.jam) //kondisi jika data[x].durasi.jam sama dengan data_app[lama].durasi.jam
        {
            if (data_app[x].durasi.menit > data_app[lama].durasi.menit) //kondisi jika data[x].durasi.menit lebih besar dari data_app[lama].durasi.menit
            {
                lama=x; // variabel lama sama dengan iterator
            }
            if (data_app[x].durasi.menit == data_app[lama].durasi.menit) //kondisi jika data[x].durasi.menit sama dengan data_app[lama].durasi.menit
            {
                if (data_app[x].durasi.detik > data_app[lama].durasi.detik) //kondisi jika data[x].durasi.detik lebih besar dari data_app[lama].durasi.detik
                {
                    lama=x; // variabel lama sama dengan iterator
                }
            }
        }
    }
    puts("-> Data ditemukan");
    data_ketemu(lama); // panggil prosedur data_ketemu dengan parameter lama
}

// prosedur pencarian data berdasarkan waktu masuk secara sequential
void cari_waktumasuk ()
{
    waktu cari; // ADT waktu diubah menjadi variabel cari
    int i, counter=0;
    printf("Masukkan Waktu Masuk Kendaraan\t\t\n");
    printf("Jam\t: "); scanf("%d",&cari.jam);
    printf("Menit\t: "); scanf("%d",&cari.menit);
    printf("Detik\t: "); scanf("%d",&cari.detik);
    for (i=0;i<jumlah;i++)
    {
        if (data_app[i].waktu_awal.jam == cari.jam) // kondisi jika data_app[i].waktu_awal.jam sama dengan cari.jam
        {
            if (data_app[i].waktu_awal.menit == cari.menit) // kondisi jika data_app[i].waktu_awal.menit sama dengan cari.menit
            {
                if (data_app[i].waktu_awal.detik == cari.detik) // kondisi jika data_app[i].waktu_awal.detik sama dengan cari.detik
                {
                    puts("-> Data ditemukan");
                    data_ketemu(i); // panggil prosedur data_ketemu disertai parameter iterator
                    counter=1; // counter = 1
                }
            }
        }
    }
    if (counter == 0) // kondisi jika counter = 1
    {
        puts("-> Data tidak ditemukan");
    }
}

// prosedur pencarian data berdasarkan biaya termahal secara sequential
void cari_biaya ()
{
    int i, counter=0;
    int idx=0; // index awal sebuah array
    for (i=0;i<jumlah;i++)
    {
        if (data_app[i].biaya > data_app[idx].biaya) // kondisi jika data_app[i].biaya > data_app[idx].biaya
        {
            idx=i; // variabel idx = i
        }
    }
    puts("-> Data ditemukan\n");
    data_ketemu(idx); // panggil prosedur data_ketemu disertai parameter idx
}

// prosedur jika data yang dicari ditemukan
void data_ketemu (int idx_ketemu)
{
    printf("Nomor Plat Kendaraan\t: %s\n",data_app[idx_ketemu].plat);
    printf("Jenis Kendaraan (S / M)\t: %c\n",data_app[idx_ketemu].jenis);
    printf("Waktu Masuk Kendaraan\t: %2d:%2d:%2d\n",data_app[idx_ketemu].waktu_awal.jam,data_app[idx_ketemu].waktu_awal.menit,data_app[idx_ketemu].waktu_awal.detik);
    printf("Waktu Keluar Kendaraan\t: %2d:%2d:%2d\n",data_app[idx_ketemu].waktu_akhir.jam,data_app[idx_ketemu].waktu_akhir.menit,data_app[idx_ketemu].waktu_akhir.detik);
    printf("Lama Parkir Kendaraan\t: %2d:%2d:%2d\n",data_app[idx_ketemu].durasi.jam,data_app[idx_ketemu].durasi.menit,data_app[idx_ketemu].durasi.detik);
    printf("Biaya Parkir Kendaraan\t: %d\n",data_app[idx_ketemu].biaya);
    printf("\n");
}

// prosedur untuk menghapus data
void hapus_data ()
{
    int i;
    int hapus; // variabel untuk menampung data ke berapa yg ingin dihapus
    printf("Data yang ingin dihapus (Data ke-?) : "); scanf("%d",&hapus);
    // looping mencari data
    for (i=0;i<jumlah;i++)
    {
        if (i == hapus-1) // kondisi jika iterator sama dengan hapus
        {
            // ubah semua nilai datanya menjadi NULL
            strcpy(data_app[i].plat,"");
            data_app[i].jenis=NULL;
            data_app[i].waktu_awal.jam=NULL;
            data_app[i].waktu_awal.menit=NULL;
            data_app[i].waktu_awal.detik=NULL;
            data_app[i].waktu_akhir.jam=NULL;
            data_app[i].waktu_akhir.menit=NULL;
            data_app[i].waktu_akhir.detik=NULL;
            data_app[i].durasi.jam=NULL;
            data_app[i].durasi.menit=NULL;
            data_app[i].durasi.detik=NULL;
            data_app[i].biaya=NULL;
        }
    }
    printf("Data berhasil dihapus\n\n");
    back_menu();
}

// Prosedur untuk menghitung rata-rata kendaraan dan total biaya kendaraan
void rata_rata ()
{
    int i;
    // inisialkan semua nilai total biaya dan total kendaraan menjadi nol
    float totalbiaya=0,totalbiaya_motor=0,totalbiaya_mobil=0;
    float totalmotor=0,totalmobil=0,totaldata=0;
    for (i=0;i<jumlah;i++)
    {
        totaldata+=1; // total data kendaraan bertambah 1
        totalbiaya+=data_app[i].biaya; // kondisi total biaya = total biaya + semua biaya kendaraan
        if (data_app[i].jenis == 's' || data_app[i].jenis == 'S') // kondisi jika jenis kendaraan sama dengan s atau S
        {
            totalmotor+=1; // total motor bertambah 1
            totalbiaya_motor+=data_app[i].biaya; // total biaya motor = total biaya motor + biaya kendaraan yang hanya motor
        }
        else if (data_app[i].jenis == 'm' || data_app[i].jenis == 'M')
        {
            totalmobil+=1; // total mobil bertambah 1
            totalbiaya_mobil+=data_app[i].biaya; // total biaya mobil = total biaya mobil + biaya kendaraan yang hanya mobil
        }
    }
    printf("-> Total Biaya : %.0f\n",totalbiaya);
    printf("-> -> Motor : %.0f\n",totalbiaya_motor);
    printf("-> -> Mobil : %.0f\n\n",totalbiaya_mobil);
    printf("-> Total Kendaraan : %.0f\n",totaldata);
    printf("-> Rata-rata Kendaraan\n");
    printf("- Motor : %.0f\n",totalmotor);
    printf("- Mobil : %.0f\n\n",totalmobil);
    printf("-> Rata rata Biaya : %.2f\n",totalbiaya/totaldata);
    printf("- Motor : %.2f\n",totalbiaya_motor/totalbiaya_motor);
    printf("- Mobil : %.2f\n\n",totalbiaya_mobil/totalbiaya_mobil);
    back_menu();
}
