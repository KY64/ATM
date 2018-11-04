#include "fungsi.h"

int main()
{
        welcome();
}

void welcome()
{
        int inputPin;
        system("clear");
        printf("                          SELAMAT DATANG\n");
        printf("                                DI\n");
        printf("                           BANK BERSAMA\n\n");
        printf("                      SILAHKAN MASUKKAN PIN");
        printf("\n\n\t\t\t      "); scanf("%d", &inputPin);
        verifikasi(inputPin, &pin);
}

void welcomeError()
{
        int inputPin;
        system("clear");
        printf("                          SELAMAT DATANG\n");
        printf("                                DI\n");
        printf("                           BANK BERSAMA\n\n");
        printf("                            PIN SALAH\n\n");
        printf("                      SILAHKAN MASUKKAN PIN");
        printf("\n\n\t\t\t      "); scanf("%d", &inputPin);
        verifikasi(inputPin, &pin);

}

int menu()
{
        int input;
        system("clear");

        printf("                              MENU UTAMA\n");
        printf("                        PECAHAN UANG RP 50.000\n");
        printf("                    ===============================\n");
        printf("                         TEKAN <0> UNTUK BATAL\n\n");
        printf("  1- 100.000                                               5. 1.000.000\n\n\n");
        printf("  2- 300.000                                               6. 500.000\n\n\n");
        printf("  3- PENARIKAN JUMLAH LAIN                                 7. TRANSFER\n\n\n");
        printf("  4- CEK SALDO");

        printf("\n\nPILIHAN : "); scanf("%d", &input);
        switch(input)
        {
        case 1:
                if(saldo > 100000)
                {
                        saldo = saldo - 100000;
                        cekSaldo();
                }
                else
                {
                        printf("\t\t                    MAAF");
                        cekSaldo();
                }
                break;
        case 2:
                if(saldo > 300000)
                {
                        saldo = saldo - 300000;
                        cekSaldo();
                }
                else
                {
                        printf("\t\t                    MAAF");
                        cekSaldo();
                }
                break;
        case 3:
                penarikan();
                break;
        case 4:
                cekSaldo();
                break;
        case 5:
                if(saldo > 1000000)
                {
                        saldo = saldo - 1000000;
                        cekSaldo();
                }
                else
                {
                        printf("\t\t                    MAAF");
                        cekSaldo();
                }
                break;
        case 6:
                if(saldo > 500000)
                {
                        saldo = saldo - 500000;
                        cekSaldo();
                }
                else
                {
                        printf("\t\t                    MAAF");
                        cekSaldo();
                }
                break;
        case 7:
                transfer();
                break;
        case 0:
                keluar();
                break;
        default:
                errorInput();
                menu();
        }
        return 0;
}
