
#include <stdio.h>
struct
{
    char name[50], kategori[50];
    int qty;
} a;

int i, n;
void main()
{
    FILE *Barang;
    Barang = fopen("List barang.dat", "ab"); //(A). Tentukan mode untuk write
    printf("Banyak barang : ");
    scanf("%d", &n);
    getchar();
    for (i = 1; i <= n; i++)
    {
        printf("%d.\tNama Barang\t: ", i);
        gets(a.name);
        printf("\tKategori\t: ");
        gets(a.kategori);
        printf("\tKuantitas\t\t: ");
        scanf("%d", &a.qty); printf("\n");
        getchar();
        fwrite(&a, sizeof(a), 1, Barang); //(B). Tentukan sintaksnya dan (C)Lengkapi
    }
    fclose(Barang); //(C). Lengkapi sintaksnya

    printf("------OUTPUT READING BINER-----\n\n");
    int i = 1;
    Barang = fopen("List barang.dat", "rb"); //(D). Tentukan mode untuk read
    while (fread(&a, sizeof(a), 1, Barang) == 1) // Tentukan (E). sintaks
    {
        printf("%d.\tNama Barang\t: %s\n", i, a.name);
        printf("\tKategori\t: %s\n", a.kategori);
        printf("\tKuantitas\t\t: %d\n\n", a.qty);
        i++;
    }
    fclose(Barang);
    getch();
}
