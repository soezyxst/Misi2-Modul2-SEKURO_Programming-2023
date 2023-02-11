#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

int main() {
    char namaNama[100] = {};

    int jumlahTransaksi[100] = {0};

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
        printf("Daftar Transaksi: ");
    }
    else if (tutupBuka == 2) {
        for (int i = 0; i < 4; i++) {
            system("cls");
            char dot1[100] = "";
            for (int j = 0; j <= i; j++) {
                strcat_s(dot1, ".");
            }
            printf("Beralih ke layar pelanggan%s\n", dot1);
            Sleep(750);
        }
        system("cls");
        char namaPelanggan[30];
        printf("Masukkan nama: ");
        scanf("%s", &namaPelanggan);
        printf("Selamat datang %s!\n", namaPelanggan);

        while (act == 1 || act == 2) {
            printf("Pilih:\n");
            printf("1. Melihat Menu;\n2. Membeli Menu; atau\n3. Keluar.\n\nPilihan: ");
            scanf_s("%d", &act);

            if (act == 2) {
                system("cls");
                int idPilihan, jumlahPilihan;
                printf("Masukkan ID menu: ");
                scanf_s("%d", &idPilihan);
                printf("Masukkan jumlah yang dibeli: ");
                scanf_s("%d", &jumlahPilihan);
                system("cls");
            }
            else if (act == 1) {
                system("cls");
                printf("Daftar Menu:\n");
                for (int i = 0; i < 10; i++) {
                    printf("%d\t%s\t\t%s\t\t%d\n", daftarID[i], daftarMenu[i], daftarKategori[i], daftarHarga[i]);
                }
                printf("\n\n\nAnda punya waktu 10 detik untuk melihat-lihat.");
                Sleep(10000);
                system("cls");
            }
        }

        if (act == 3) {
            system("cls");
            for (int i = 0; i < 4; i++) {
                system("cls");
                char dot1[100] = "";
                for (int j = 0; j <= i; j++) {
                    strcat_s(dot1, ".");
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
