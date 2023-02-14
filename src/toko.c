#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <stdbool.h>

// Outer function

int findIndex(int* arr, int x, int len) {
    int index;
    for (int i = 0; i < len; i++) {
        if (arr[i] == x) {
            index = i;
            return index;
        }
    }
}

// General variable

char* namaPelanggan[100];
char* menuDibeli[256];

int hargaMenu[256], totalMenu[256];
int jumlahTransaksi[100];
int jumlahPelanggan = 0;
int totalTransaksi = 0;
int daftarStok[] = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };


int main() {
    // initialize variable
    bool stok = true;

    char daftarMenu[10][20] = { "Sosis", "Cimol", "Cireng", "Goyobod", "Awug", "Cendol", "Cilor", "Cilung", "Bakso", "Cilok" },
        daftarKategori[10][10] = { "Makanan", "Makanan", "Makanan", "Minuman", "Makanan" , "Minuman", "Makanan" , "Makanan" , "Makanan" , "Makanan" };

    int daftarID[] = { 11001, 11002, 11003, 11004, 11005, 11006, 11007, 11008, 11009, 11010 },
        daftarHarga[] = { 3000, 3500, 5000, 4000, 3000, 4500, 4000, 5000, 3500, 3500 };

    int tutupBuka, act = 1, jumlahPembeli = 0;

    printf("----- Halo! -----\n");
    Sleep(1000);
    printf("Ingin menutup toko (1) atau pelanggan masuk (2): ");
    scanf_s("%d", &tutupBuka);
    Sleep(1000);

    if (tutupBuka == 1) {
        if (jumlahPelanggan == 0) {
            printf("Tidak ada penjualan.");
        }
        else {
            printf("Daftar Transaksi:\n");
            printf("Nama\tMenu\tJumlah\tTotal\n");
            int temp = 0;
            for (int i = 0; i < jumlahPelanggan; i++) {
                if (i != 0) {
                    temp += jumlahTransaksi[i - 1];
                }

                printf("%s\t", namaPelanggan[i]);
                for (int j = temp; j < (temp + jumlahTransaksi[i]); j++) {
                    if (j == temp) {
                        printf("%s\t%d\t%d\n", menuDibeli[j], totalMenu[j], hargaMenu[j]);
                    }
                    else {
                        printf("\t%s\t%d\t%d\n", menuDibeli[j], totalMenu[j], hargaMenu[j]);
                    }
                }
            }
        }
    }
    else if (tutupBuka == 2) {
        for (int i = 0; i < 4; i++) {
            system("cls");
            char dot1[100] = "";
            for (int j = 0; j <= i; j++) {
                strcat_s(dot1, 100, ".");
            }
            printf("Beralih ke layar pelanggan%s\n", dot1);
            Sleep(750);
        }
        system("cls");
        char nama[30];
        printf("Masukkan nama panggilan: ");
        scanf("%s", &nama);
        system("cls");
        printf("Selamat datang %s!\n", nama);
        namaPelanggan[jumlahPelanggan] = nama;
        jumlahPelanggan += 1;

        while (act == 1 || act == 2) {
            printf("Pilih:\n");
            printf("1. Melihat Menu;\n2. Membeli Menu; atau\n3. Keluar.\n\nPilihan: ");
            scanf_s("%d", &act);

            if (act == 2) {
                int setuju = 0;
                while (setuju != 1) {
                    int idPilihan = 0, jumlahPilihan = 0;
                    while (stok) {
                        system("cls");
                        
                        printf("Masukkan ID menu: ");
                        scanf_s("%d", &idPilihan);
                        printf("Masukkan jumlah yang dibeli: ");
                        scanf_s("%d", &jumlahPilihan);
                        system("cls");

                        if (jumlahPilihan > daftarStok[findIndex(daftarID, idPilihan, 10)]) {
                            printf("Maaf pesanan melebihi stok, silakan ulangi.");
                            Sleep(3000);
                        }
                        else {
                            stok = false;
                        }
                    }
                    int totalHarga = jumlahPilihan * daftarHarga[findIndex(daftarID, idPilihan, 10)];
                    printf("Anda membeli %s sebanyak %d dengan total harga %d.\n\n",
                        daftarMenu[findIndex(daftarID, idPilihan, 10)], jumlahPilihan, totalHarga);

                    printf("Masukkan '1' jika setuju atau apa pun jika tidak: ");
                    scanf_s("%d", &setuju);

                    hargaMenu[totalTransaksi] = totalHarga;
                    totalMenu[totalTransaksi] = jumlahPilihan;
                    menuDibeli[totalTransaksi] = daftarMenu[findIndex(daftarID, idPilihan, 10)];
                    daftarStok[findIndex(daftarID, idPilihan, 10)] -= jumlahPilihan;
                    stok = true;
                }
                system("cls");
                setuju = 0;
                jumlahTransaksi[jumlahPelanggan - 1] += 1;
                totalTransaksi += 1;
            }
            else if (act == 1) {
                system("cls");
                printf("Daftar Menu:\n\n");
                printf("ID\tMenu\t\tKategori\tHarga\t\tStok\n\n");
                for (int i = 0; i < 10; i++) {
                    printf("%d\t%s\t\t%s\t\t%d\t\t%d\n", daftarID[i], daftarMenu[i], daftarKategori[i], daftarHarga[i], daftarStok[i]);
                }
                printf("\n\n\nMasukkan apa pun jika selesai.\n");

                char* w;
                scanf("%s", &w);
                system("cls");
            }
        }

        if (act == 3) {
            Sleep(1000);
            system("cls");
            for (int i = 0; i < 4; i++) {
                system("cls");
                char dot1[100] = "";
                for (int j = 0; j <= i; j++) {
                    strcat_s(dot1, 100, ".");
                }
                printf("Beralih ke layar pemilik%s\n", dot1);
                Sleep(750);
            }
            system("cls");
            main();
        }
    }

    return 0;
}
