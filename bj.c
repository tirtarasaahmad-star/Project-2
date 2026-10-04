#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void tampilkanKartu(int kartu) {
    if (kartu == 1)
        printf("A");
    else if (kartu >= 2 && kartu <= 10)
        printf("%d", kartu);
    else if (kartu == 11)
        printf("J");
    else if (kartu == 12)
        printf("Q");
    else if (kartu == 13)
        printf("K");
}

 int nilaikartu(int kartu) {
            if (kartu >= 11 && kartu <= 13)
                return 10;

            else if (kartu == 1)
                return 11;
            
            return kartu;
}

int main() {
    srand(time(NULL));
    int pilihan;
    int jumlahnilai = 0;
    int jumlahdealer = 0;

    int playerCard1 = rand() % 13 + 1;
    int playerCard2 = rand() % 13 + 1;
    int playerCard3 = rand() % 13 + 1;
    int playerCard4 = rand() % 13 + 1;

    int dealerCard1 = rand() % 13 + 1;
    int dealerCard2 = rand() % 13 + 1;
    int dealerCard3 = rand() % 13 + 1;

    printf("=== BLACKJACK ===\n\n");

    printf("Player:\n");

    printf("Kartu 1: ");
    tampilkanKartu(playerCard1);

    printf("\nKartu 2: ");
    tampilkanKartu(playerCard2);

    jumlahnilai = nilaikartu(playerCard1) + nilaikartu(playerCard2);
    printf("\nJumlah nilai kartu Anda: %d\n", jumlahnilai);

    printf("\n\nDealer:\n");

    printf("Kartu 1: ");
    tampilkanKartu(dealerCard1);

    printf("\nKartu 2: ?");

    printf("\n\nApakah Anda ingin menarik kartu lagi? (1 = Ya, 2 = Tidak): ");
    scanf("%d", &pilihan);
    if (pilihan == 1) {
        printf("\nKartu 1: ");
        tampilkanKartu(playerCard1);
        printf("\nKartu 2: ");
        tampilkanKartu(playerCard2);
        printf("\nKartu 3: ");
        tampilkanKartu(playerCard3);
        jumlahnilai = nilaikartu(playerCard1) + nilaikartu(playerCard2) + nilaikartu(playerCard3);
        printf("\nJumlah nilai kartu Anda: %d\n", jumlahnilai); 

        if (jumlahnilai > 21) {
            printf("\nAnda kalah! Jumlah nilai kartu Anda melebihi 21.");

        } else if (jumlahnilai == 21) {
            printf("\nSelamat! Anda menang!");

        } else if (jumlahnilai < 21){
            printf("Apakah Anda ingin menarik kartu lagi? (1 = Ya, 2 = Tidak): ");
            scanf("%d", &pilihan);
            if (pilihan == 1) {
                printf("\nKartu 1: ");
                tampilkanKartu(playerCard1);
                printf("\nKartu 2: ");
                tampilkanKartu(playerCard2);
                printf("\nKartu 3: ");
                tampilkanKartu(playerCard3);
                printf("\nKartu 4: ");
                tampilkanKartu(playerCard4);
                jumlahnilai = nilaikartu(playerCard1) + nilaikartu(playerCard2) + nilaikartu(playerCard3) + nilaikartu(playerCard4);
                printf("\nJumlah nilai kartu Anda: %d\n", jumlahnilai); 

                if (jumlahnilai > 21) {
                    printf("\nAnda kalah! Jumlah nilai kartu Anda melebihi 21.");
                } else if (jumlahnilai == 21) {
                    printf("\nSelamat! Anda menang!");
                } else {
                    printf("\nJumlah nilai kartu Anda: %d\n", jumlahnilai);
                    printf("\nDealer akan membuka kartu kedua.\n");
                    printf("Kartu 1: ");
                    tampilkanKartu(dealerCard1);
                    printf("\nKartu 2: ");
                    tampilkanKartu(dealerCard2);

                    jumlahdealer = nilaikartu(dealerCard1) + nilaikartu(dealerCard2);

                    if (jumlahdealer < 17) {
                        printf("\nHost membukakan kartu ketiga dealer: ");
                        printf("\nKartu 1: ");
                        tampilkanKartu(dealerCard1);
                        printf("\nKartu 2: ");
                        tampilkanKartu(dealerCard2);
                        printf("\nKartu 3: ");
                        tampilkanKartu(dealerCard3);
                        jumlahdealer = nilaikartu(dealerCard1) + nilaikartu(dealerCard2) + nilaikartu(dealerCard3);
                        printf("\nJumlah nilai kartu dealer: %d\n", jumlahdealer);

                        if (jumlahdealer > 21) {
                            printf("\nJumlah nilai kartu Anda: %d\n", jumlahnilai);
                            printf("\nSelamat! Anda menang!"); 
                            printf("\nDealer kalah! Jumlah nilai kartu dealer melebihi 21.");
                        } else {
                            printf("\nJumlah nilai kartu dealer: %d\n", jumlahdealer);
                            if (jumlahnilai > jumlahdealer) {
                                printf("\nSelamat! Anda menang!");
                            } else if (jumlahnilai < jumlahdealer) {
                                printf("\nMaaf, Anda kalah!");
                            } else {
                                printf("\nHasil seri!");
                            }
                        }
                    } else {
                        printf("\nJumlah nilai kartu dealer: %d\n", jumlahdealer);
                        if (jumlahnilai > jumlahdealer) {
                            printf("\nSelamat! Anda menang!");
                        } else if (jumlahnilai < jumlahdealer) {
                            printf("\nMaaf, Anda kalah!");
                        } else {
                            printf("\nHasil seri!");
                        }
                    }
                }
            } 
        }
    } else {
        printf("\nKartu 1: ");
        tampilkanKartu(dealerCard1);
        printf("\nKartu 2: ");
        tampilkanKartu(dealerCard2);

        jumlahdealer = nilaikartu(dealerCard1) + nilaikartu(dealerCard2);

        if (jumlahdealer < 17) {
            printf("\nHost membukakan kartu ketiga dealer: ");
            printf("\nKartu 1: ");
            tampilkanKartu(dealerCard1);
            printf("\nKartu 2: ");
            tampilkanKartu(dealerCard2);
            printf("\nKartu 3: ");
            tampilkanKartu(dealerCard3);
            jumlahdealer = nilaikartu(dealerCard1) + nilaikartu(dealerCard2) + nilaikartu(dealerCard3);
            printf("\nJumlah nilai kartu dealer: %d\n", jumlahdealer);
            if (jumlahnilai > jumlahdealer) {
                printf("\nSelamat! Anda menang!");
            } else if (jumlahnilai < jumlahdealer) {
                printf("\nMaaf, Anda kalah!");
            } else {
                printf("\nHasil seri!");
            }

            if (jumlahdealer > 21) {
                printf("\nJumlah nilai kartu Anda: %d\n", jumlahnilai);
                printf("\nSelamat! Anda menang!"); 
                printf("\nDealer kalah! Jumlah nilai kartu dealer melebihi 21.");
            }
        } else {
            printf("\nJumlah nilai kartu dealer: %d\n", jumlahdealer);
            if (jumlahnilai > jumlahdealer) {
                printf("\nSelamat! Anda menang!");
            } else if (jumlahnilai < jumlahdealer) {
                printf("\nMaaf, Anda kalah!");
            } else {
                printf("\nHasil seri!");
            }
        }
    }
    printf("\n\nTerima kasih telah bermain Blackjack!\n");
    return 0;
}