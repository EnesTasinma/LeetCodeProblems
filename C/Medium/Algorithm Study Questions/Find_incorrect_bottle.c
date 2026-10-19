#include <stdio.h>

// bottles[left..right] araliginda bir tane HAFIF (hatalı) şişe var
// Hatalı şişenin indeksini döndürür.
int find_incorrect_bottle(double bottles[], int left, int right) {
    int n = right - left + 1;

    // Taban durum: tek şişe kaldıysa, o hatalıdır
    if (n == 1) {
        return left;
    }

    // İki gruba ayır (mümkün olduğunca eşit)
    int k = n / 2;  // her gruptaki eleman sayısı
    int leftStart  = left;
    int leftEnd    = left + k - 1;
    int rightStart = left + k;
    int rightEnd   = left + 2 * k - 1; // ikinci grup

    // 1 veya 2 grup dışı şişe olabilir (n tekse 1 tane)
    int extraIndex = -1;
    if (2 * k < n) {
        extraIndex = left + 2 * k; // dışarıda kalan tek şişe
    }

    // İki grubun ağırlık toplamlarını hesapla (tartma simülasyonu)
    double sumLeft = 0.0, sumRight = 0.0;
    for (int i = leftStart; i <= leftEnd; i++) {
        sumLeft += bottles[i];
    }
    for (int i = rightStart; i <= rightEnd; i++) {
        sumRight += bottles[i];
    }

    // Karşılaştır
    if (sumLeft == sumRight) {
        // Hatalı şişe gruplarda değil; dışarıda kalan tek şişe
        return extraIndex;
    } else if (sumLeft < sumRight) {
        // Hatalı (daha hafif) şişe sol grupta
        return find_incorrect_bottle(bottles, leftStart, leftEnd);
    } else {
        // Hatalı şişe sağ grupta
        return find_incorrect_bottle(bottles, rightStart, rightEnd);
    }
}

int main() {
    int n;

    printf("Sise sayisini girin: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Gecersiz sayi.\n");
        return 1;
    }

    double bottles[1000]; // ornek icin max 1000
    if (n > 1000) {
        printf("Cok fazla sise, limiti arttirmaniz gerekir.\n");
        return 1;
    }

    printf("%d siseye ait agirliklari girin:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Sise %d agirligi: ", i + 1);
        scanf("%lf", &bottles[i]);
    }

    int idx = find_incorrect_bottle(bottles, 0, n - 1);

    if (idx >= 0) {
        printf("\nHatalı sise indexi: %d (1-based: %d)\n", idx, idx + 1);
        printf("Agirligi: %.4f\n", bottles[idx]);
    } else {
        printf("Hatalı sise bulunamadi.\n");
    }

    return 0;
}
