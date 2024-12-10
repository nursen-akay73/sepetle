
#include <stdio.h>
#include <string.h>

#define MAX_URUN_SAYISI 10

// Ürün bilgilerini tutacak yapı
typedef struct {
    char urunAdi[50];
    int miktar;
    double fiyat;
} Urun;

void sepetiGoruntule(Urun sepet[], int urunSayisi) {
    printf("\nSepetiniz:\n");
    printf("-------------------------------------------------\n");
    double toplamFiyat = 0;
    for (int i = 0; i < urunSayisi; i++) {
        printf("Ürün Adı: %s | Miktar: %d | Fiyat: %.2f TL | Toplam: %.2f TL\n", 
            sepet[i].urunAdi, sepet[i].miktar, sepet[i].fiyat, sepet[i].miktar * sepet[i].fiyat);
        toplamFiyat += sepet[i].miktar * sepet[i].fiyat;
    }
    printf("-------------------------------------------------\n");
    printf("Toplam Tutar: %.2f TL\n", toplamFiyat);
}

int main() {
    Urun sepet[MAX_URUN_SAYISI];  // Sepet için maksimum ürün sayısı
    int urunSayisi = 0;
    int secim;
    
    do {
        printf("\nSepet Uygulamasına Hoşgeldiniz!\n");
        printf("1. Ürün Ekle\n");
        printf("2. Sepeti Görüntüle\n");
        printf("3. Çıkış\n");
        printf("Seçiminizi yapın (1-3): ");
        scanf("%d", &secim);
        
        switch(secim) {
            case 1: {
                if (urunSayisi >= MAX_URUN_SAYISI) {
                    printf("Sepetinizde maksimum ürün sayısına ulaştınız.\n");
                } else {
                    // Yeni ürün ekleme
                    printf("Ürün adını girin: ");
                    getchar();  // getchar() ile önceki enter'ı temizler
                    fgets(sepet[urunSayisi].urunAdi, sizeof(sepet[urunSayisi].urunAdi), stdin);
                    sepet[urunSayisi].urunAdi[strcspn(sepet[urunSayisi].urunAdi, "\n")] = 0;  // Yeni satır karakterini temizle

                    printf("Miktarını girin: ");
                    scanf("%d", &sepet[urunSayisi].miktar);

                    printf("Birim fiyatını girin: ");
                    scanf("%lf", &sepet[urunSayisi].fiyat);

                    urunSayisi++;
                    printf("Ürün sepete eklendi!\n");
                }
                break;
            }
            case 2:
                // Sepeti görüntüleme
                if (urunSayisi == 0) {
                    printf("Sepetinizde ürün bulunmamaktadır.\n");
                } else {
                    sepetiGoruntule(sepet, urunSayisi);
                }
                break;
            case 3:
                printf("Çıkılıyor...\n");
                break;
            default:
                printf("Geçersiz seçim, lütfen tekrar deneyin.\n");
        }
    } while (secim != 3);

    return 0;
}
