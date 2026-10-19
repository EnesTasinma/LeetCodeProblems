#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left;
    int right;
    int height;
} Building;

typedef struct {
    int x;
    int h;
} Point;

typedef struct {
    Point *pts;   // key point dizisi
    int size;     // kullanılan eleman sayısı
} Skyline;

/* ---------- Yardımcı: qsort için karşılaştırma ---------- */
int cmpBuilding(const void *a, const void *b) {
    const Building *ba = (const Building *)a;
    const Building *bb = (const Building *)b;
    if (ba->left != bb->left)
        return ba->left - bb->left;
    return ba->right - bb->right;
}

/* ---------- İki skyline'ı birleştirme (conquer kısmı) ---------- */
Skyline mergeSkylines(Skyline A, Skyline B) {
    Skyline res;
    res.pts = (Point *)malloc((A.size + B.size) * sizeof(Point));
    res.size = 0;

    int i = 0, j = 0;
    int h1 = 0, h2 = 0;   // sol ve sağ aktif yükseklikler
    int currH = 0;        // şu anki skyline yüksekliği

    while (i < A.size && j < B.size) {
        int x;
        if (A.pts[i].x < B.pts[j].x) {
            x = A.pts[i].x;
            h1 = A.pts[i].h;
            i++;
        } else if (B.pts[j].x < A.pts[i].x) {
            x = B.pts[j].x;
            h2 = B.pts[j].h;
            j++;
        } else { // aynı x
            x = A.pts[i].x;
            h1 = A.pts[i].h;
            h2 = B.pts[j].h;
            i++;
            j++;
        }

        int maxH = (h1 > h2) ? h1 : h2;
        if (maxH != currH) {
            res.pts[res.size].x = x;
            res.pts[res.size].h = maxH;
            res.size++;
            currH = maxH;
        }
    }

    // A'da kalanlar
    while (i < A.size) {
        int x = A.pts[i].x;
        h1 = A.pts[i].h;
        int maxH = (h1 > h2) ? h1 : h2;
        if (maxH != currH) {
            res.pts[res.size].x = x;
            res.pts[res.size].h = maxH;
            res.size++;
            currH = maxH;
        }
        i++;
    }

    // B'de kalanlar
    while (j < B.size) {
        int x = B.pts[j].x;
        h2 = B.pts[j].h;
        int maxH = (h1 > h2) ? h1 : h2;
        if (maxH != currH) {
            res.pts[res.size].x = x;
            res.pts[res.size].h = maxH;
            res.size++;
            currH = maxH;
        }
        j++;
    }

    // Artık A ve B kullanılmayacak
    free(A.pts);
    free(B.pts);

    return res;
}

/* ---------- Divide & Conquer Skyline ---------- */
Skyline skylineRec(Building *b, int l, int r) {
    Skyline res;

    if (l > r) {
        res.pts = NULL;
        res.size = 0;
        return res;
    }

    if (l == r) {
        // Tek bina: (left, height), (right, 0)
        res.pts = (Point *)malloc(2 * sizeof(Point));
        res.size = 2;
        res.pts[0].x = b[l].left;
        res.pts[0].h = b[l].height;
        res.pts[1].x = b[l].right;
        res.pts[1].h = 0;
        return res;
    }

    int mid = (l + r) / 2;
    Skyline leftSky  = skylineRec(b, l, mid);
    Skyline rightSky = skylineRec(b, mid + 1, r);

    return mergeSkylines(leftSky, rightSky);
}

/* ---------- Kullanımı kolay ana fonksiyon ---------- */
Skyline computeSkyline(Building *buildings, int n) {
    Skyline res;

    if (n <= 0) {
        res.pts = NULL;
        res.size = 0;
        return res;
    }

    // Binaları left koordinatına göre sırala
    qsort(buildings, n, sizeof(Building), cmpBuilding);

    // Divide & conquer ile skyline hesapla
    res = skylineRec(buildings, 0, n - 1);
    return res;
}

/* ---------- Örnek kullanım ---------- */
int main(void) {
    int n;
    printf("Bina sayisini girin: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Gecersiz sayi.\n");
        return 1;
    }

    Building *buildings = (Building *)malloc(n * sizeof(Building));
    if (!buildings) {
        printf("Bellek hatasi.\n");
        return 1;
    }

    printf("Her bina icin left right height degerlerini girin:\n");
    for (int i = 0; i < n; i++) {
        printf("Bina %d: ", i + 1);
        scanf("%d %d %d", &buildings[i].left,
                          &buildings[i].right,
                          &buildings[i].height);
    }

    Skyline sky = computeSkyline(buildings, n);

    printf("\nSkyline key point'leri (x, h):\n");
    for (int i = 0; i < sky.size; i++) {
        printf("(%d, %d)\n", sky.pts[i].x, sky.pts[i].h);
    }

    free(buildings);
    free(sky.pts);
    return 0;
}
