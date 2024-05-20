#include <stdio.h>
#include <stdlib.h>

struct OGRENCI {
    int id;
    float vize;
    float final;
    float ortalama;
    struct OGRENCI* sonraki;
};

struct OGRENCI* ogrenciOlustur(int id) {
    struct OGRENCI* yeniOgrenci = (struct OGRENCI*)malloc(sizeof(struct OGRENCI));
    yeniOgrenci->id = id;
    yeniOgrenci->vize = 0.0;
    yeniOgrenci->final = 0.0;
    yeniOgrenci->ortalama = 0.0;
    yeniOgrenci->sonraki = NULL;
    return yeniOgrenci;
}

void ogrenciEkle(struct OGRENCI** bas, int id) {
    struct OGRENCI* yeni = ogrenciOlustur(id);
    yeni->sonraki = *bas;
    *bas = yeni;
}

void ortalamaNotlar(struct OGRENCI* bas) {
    struct OGRENCI* temp = bas;
    while (temp != NULL) {
        temp->ortalama = (temp->vize*(0.4) + temp->final*(0.6));
        temp = temp->sonraki;
    }
}

void listeYazdir(struct OGRENCI* bas) {
    printf("ID\tVize\tFinal\tOrtalama\n");
    while (bas != NULL) {
        printf("%d\t%.1f\t%.1f\t%.1f\n", bas->id, bas->vize, bas->final, bas->ortalama);
        bas = bas->sonraki;
    }
}

int main() {
    struct OGRENCI* bas = NULL;
    int id;
    char devam;

    do {
        printf(" grenci ID'sini giriniz: ");
        scanf("%d", &id);
        ogrenciEkle(&bas, id);

        printf("Vize notunu giriniz: ");
        scanf("%f", &bas->vize);

        printf("Final notunu giriniz: ");
        scanf("%f", &bas->final);

        printf("Devam etmek istiyor musunuz? (E/H): ");
        scanf(" %c", &devam);
    } while (devam == 'E' || devam == 'e');

    ortalamaNotlar(bas);

    listeYazdir(bas);

    return 0;
}

