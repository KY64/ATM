#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void errorInput()
{
        system("clear");
        printf("\n\n\n                   Maaf Pilihan Tidak Tersedia\n\n");
}

int menu(),cekSaldo();
void konfirmasi(),errorInput(),welcomeError(),welcome(),keluar(),inputRekening();
void akun(char *user[], char *name[]);
void verifikasi(int p, int *inputPin);
void saldoATM(unsigned long long int *saldoAkun, unsigned long long int saldoSisa);
void noRekening(unsigned long long int *noRek, unsigned long long int rekeningSaldo);
void temp(unsigned long long int *tmp, unsigned long long int temp);

char *akunATM, akun1[]="Excel Daris Fadhillah", akun2[]="M Daffa Geraldine";
int pin, pin1 = 100200, pin2 = 111000;
unsigned long long int saldo = 0, saldo1 = 250000, saldo2 = 500000;
unsigned long long int rek = 0, rek1 = 2210171040, rek2 = 2210171045, tmp = 0;


void verifikasi(int p, int *inputPin)
{
        char **akunAktif;
        if(p == pin1)
        {
                *inputPin = p;

                akunAktif = &akunATM;
                *akunAktif = (char*) malloc(100 * sizeof(char));
                strcpy(*akunAktif, akun1);
                saldoATM(&saldo,saldo1);
                noRekening(&rek, rek1);
                menu();
        }

        else if(p == pin2)
        {
                *inputPin = p;

                akunAktif = &akunATM;
                *akunAktif = (char*) malloc(100 * sizeof(char));
                strcpy(*akunAktif, akun2);
                saldoATM(&saldo,saldo2);
                noRekening(&rek, rek2);
                menu();
        }
        else
        {
                system("clear");
                welcomeError();
        }
}

void keluar()
{
        if(pin == pin1)
                saldoATM(&saldo1, saldo);
        if(pin == pin2)
                saldoATM(&saldo2, saldo);

        welcome();
}

void saldoATM(unsigned long long int *saldoAkun, unsigned long long int saldoSisa)
{
        *saldoAkun = saldoSisa;
}

void noRekening(unsigned long long int *noRek, unsigned long long int rekeningSaldo)
{
        *noRek = rekeningSaldo;
}

void temp(unsigned long long int *tmp, unsigned long long int temp)
{
        *tmp = temp;
}


int cekSaldo()
{
        int input;
        system("clear");
        printf("\n\n                              SISA SALDO ANDA\n\n");
        printf("                                "); printf("Rp %llu",saldo);
        printf("\n\n\n                APAKAH ANDA INGIN MELAKUKAN TRANSAKSI LAIN?\n\n");
        printf("                          1. YA\n\n                          2. TIDAK\n\n");
        printf("Pilihan : "); scanf("%d", &input);
        switch (input) {
        case 1:
                menu(); break;
        case 2:
                keluar(); break;
        default:
                errorInput();
                cekSaldo();
        }

        return 0;
}

int penarikan()
{
        system("clear");
        unsigned long long int nominal;
        int input;
        printf("\n\n                   MASUKKAN NOMINAL KELIPATAN RP 50000\n\n");
        printf("                           Rp "); scanf("%llu", &nominal);
        printf("\n\n                  1. BENAR\n\n                  2.KELUAR\n\n                  3.KEMBALI KE MENU");
        printf("\n\n\tPILIHAN : "); scanf("%d",&input);
        switch (input) {
        case 1:
                if((nominal%50000 == 0) && saldo > nominal)
                {
                        saldo = saldo - nominal;
                        cekSaldo();
                        break;
                }
                else
                {

                        printf("\t\t                    MAAF");
                        cekSaldo();

                        break;
                }
        case 2:
                keluar();

        default:

                menu();
                break;

        }
        return 0;
}

void transfer()
{
        system("clear");
        int input;
        unsigned long long int nominal;
        printf("\n\n                  MASUKKAN NOMINAL MINIMAL Rp 50.000\n\n");
        printf("                             Rp "); scanf("%llu",&nominal);
        printf("\n\n                  1. BENAR\n\n                  2.KELUAR\n\n                  3.KEMBALI KE MENU");
        printf("\n\n\tPILIHAN : "); scanf("%d",&input);
        switch (input) {
        case 1:
                if((nominal%50000 == 0) && saldo > nominal)
                {
                        temp(&tmp, nominal);
                        inputRekening();
                }
                else
                {

                        printf("\t\t                    MAAF");
                        cekSaldo();

                        break;
                }
                break;
        case 2:
                keluar();

        default:

                menu();
                break;
        }
}

void inputRekening()
{
        int input;
        unsigned long long int rekening;
        system("clear");
        printf("\n\n                    MASUKKAN NOMOR REKENING\n\n");
        printf("                         "); scanf("%llu",&rekening);
        printf("\n\n                  1. BENAR\n\n                  2.KELUAR\n\n                  3.KEMBALI KE MENU");
        printf("\n\n\tPILIHAN : "); scanf("%d",&input);

        //TODO
        switch (input) {
        case 1:
                if(rekening != rek)
                {
                        if(rek == rek1)
                                konfirmasi();
                        else if(rek == rek2)
                                konfirmasi();
                        else transfer();


                        break;
                }
                else
                {

                        printf("\t\t                    MAAF");
                        cekSaldo();

                        break;
                }
                break;
        case 2:
                keluar();
                break;

        default:

                menu();
                break;

        }

}

void konfirmasi()
{

        system("clear");
        int input;
        if(strcmp(akunATM, akun1) == 0)
        {
                printf("\n\n\t\tTUJUAN TRANSFER\n\n");
                printf("\t\tNAMA      : %s\n\n",akun2);
                printf("\t\tREKENING  : %llu\n\n", rek2);
        }
        if(strcmp(akunATM, akun2) == 0)
        {
                printf("\t\tTUJUAN TRANSFER\n\n");
                printf("\t\tNAMA      : %s\n\n",akun1);
                printf("\t\tREKENING  : %llu\n\n", rek1);
        }

        printf("\n\n                  1. BENAR\n\n                  2.KELUAR\n\n                  3.KEMBALI KE MENU");
        printf("\n\n\tPILIHAN : "); scanf("%d",&input);
        switch (input) {
        case 1:
                if(strcmp(akunATM, akun1) == 0)
                {
                        saldo = saldo - tmp;
                        saldo2 = saldo2 + tmp;
                }
                if(strcmp(akunATM, akun2) == 0)
                {
                        saldo = saldo - tmp;
                        saldo1 = saldo1 + tmp;
                }
                break;
        case 2:
                keluar();
                break;

        default:

                menu();
                break;
        }
        printf("                          TRANSAKSI BERHASIL!");
        cekSaldo();


}
