#include <stdio.h>
#include <stdlib.h>


int sirala(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}


int BinarySearch(int dizi[], int dusuk, int yuksek, int aranan) {
    while (dusuk <= yuksek) {
        int ort = dusuk + (yuksek - dusuk) / 2;

        if (dizi[ort] == aranan)
            return ort;
        else if (dizi[ort] < aranan)
            dusuk = ort + 1;
        else
            yuksek = ort - 1;
    }

    return -1;
}

int main() {
    int dizi[] = {4, 8, 3, 84, 47, 76, 9, 24, 68};
    int n = sizeof(dizi) / sizeof(dizi[0]);
    int aranan;

    printf("Aranacak hedef elemani girin: ");
    scanf("%d", &aranan);

    
    qsort(dizi, n, sizeof(int), sirala);

    int sonuc = BinarySearch(dizi, 0, n - 1, aranan);

  
    if (sonuc == -1)
        printf("Hedef eleman bulunamadi.\n");
    else
        printf("Hedef eleman %d. indekste bulundu.\n", sonuc);

    return 0;
}
