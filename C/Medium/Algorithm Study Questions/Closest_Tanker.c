#include <stdio.h>
#include <math.h>

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    int index;      // tanker indeksini tutacağız (0..n-1)
    double dist2;   // pilotla arasındaki mesafenin karesi
} Result;

// İki nokta arasındaki uzaklığın karesi (sqrt almaya gerek yok)
double distance_squared(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return dx * dx + dy * dy;
}

// Divide & Conquer: tankers[l..r] aralığında pilota en yakın tankeri bul
Result closest_tanker_rec(Point tankers[], int l, int r, Point pilot) {
    if (l == r) {
        // Tek tanker varsa, cevap odur
        Result res;
        res.index = l;
        res.dist2 = distance_squared(tankers[l], pilot);
        return res;
    }

    int mid = (l + r) / 2;

    // Sol yarıda en yakın tanker
    Result leftRes = closest_tanker_rec(tankers, l, mid, pilot);
    // Sağ yarıda en yakın tanker
    Result rightRes = closest_tanker_rec(tankers, mid + 1, r, pilot);

    // Hangisi daha yakınsa onu döndür
    if (leftRes.dist2 <= rightRes.dist2) {
        return leftRes;
    } else {
        return rightRes;
    }
}

// Kullanımı kolay olsun diye wrapper fonksiyon
Result closest_tanker(Point tankers[], int n, Point pilot) {
    if (n <= 0) {
        Result res = {-1, -1.0};
        return res; // geçersiz
    }
    return closest_tanker_rec(tankers, 0, n - 1, pilot);
}

int main() {
    int n;
    Point pilot;

    printf("Tanker sayisini girin: ");
    scanf("%d", &n);

    printf("Pilotun konumunu girin (px py): ");
    scanf("%lf %lf", &pilot.x, &pilot.y);

    Point tankers[1000]; // maks 1000 dedim, ihtiyaca göre arttir
    if (n > 1000) {
        printf("Cok fazla tanker sayisi!\n");
        return 1;
    }

    printf("%d tanker icin konumlari girin (x y):\n", n);
    for (int i = 0; i < n; i++) {
        printf("Tanker %d: ", i + 1);
        scanf("%lf %lf", &tankers[i].x, &tankers[i].y);
    }

    Result ans = closest_tanker(tankers, n, pilot);

    if (ans.index == -1) {
        printf("Gecerli tanker yok.\n");
    } else {
        double dist = sqrt(ans.dist2); // istersek gercek mesafeyi de hesaplayabiliriz
        printf("Pilota en yakin tanker: %d\n", ans.index + 1);
        printf("Konumu: (%.2f, %.2f)\n", tankers[ans.index].x, tankers[ans.index].y);
        printf("Mesafe: %.4f\n", dist);
    }

    return 0;
}
