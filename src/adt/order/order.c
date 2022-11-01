#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "order.h"

/* *** Kreator *** */
void CreateOrder(Order *o)
{
    IDX_HEAD(*o) = IDX_UNDEF;
    IDX_TAIL(*o) = IDX_UNDEF;
}

void CreateMasakan(Masakan *m, int nomor)
{
    NOMOR(*m) = nomor;
    DURASI(*m) = rand() % 5 + 1;
    KETAHANAN(*m) = rand() % 5 + 1;
    HARGA(*m) = rand() % 5001 + 10000;
}

/* ********* Prototype ********* */
boolean isEmpty(Order o)
{
    return (IDX_HEAD(o) == IDX_UNDEF) && (IDX_TAIL(o) == IDX_UNDEF);
}

boolean isFull(Order o)
{
    return (((IDX_TAIL(o) + 1) % CAPACITY) == IDX_HEAD(o));
}

int length(Order o)
{
    if (!isEmpty(o))
    {
        if (IDX_TAIL(o) > IDX_HEAD(o))
        {
            return (IDX_TAIL(o) - IDX_HEAD(o) + 1);
        }
        else
        {
            return (CAPACITY - (IDX_HEAD(o) - IDX_TAIL(o)) + 1);
        }
    }
    else
    {
        return 0;
    }
}

/* *** Primitif Add/Delete *** */
void addOrder(Order *o, Masakan val)
{
    if (isEmpty(*o))
    {
        IDX_HEAD(*o) = 0;
    }
    IDX_TAIL(*o) = (IDX_TAIL(*o) + 1) % CAPACITY;
    setMasakan(&TAIL(*o), val);

    int i = IDX_TAIL(*o);
    int j = (i + CAPACITY - 1) % CAPACITY;

    Masakan temp;
    while (i != IDX_HEAD(*o) && NOMOR(ELMT(*o, i)) < NOMOR(ELMT(*o, j)))
    {
        setMasakan(&temp, ELMT(*o, i));
        setMasakan(&ELMT(*o, i), ELMT(*o, j));
        setMasakan(&ELMT(*o, j), temp);

        i = j;
        j = (i + CAPACITY - 1) % CAPACITY;
    }
}

void deleteOrder(Order *o, Masakan *val)
{
    setMasakan(val, HEAD(*o));
    if (length(*o) == 1)
    {
        IDX_HEAD(*o) = IDX_UNDEF;
        IDX_TAIL(*o) = IDX_UNDEF;
    }
    else
    {
        for (int i = 0; i < IDX_TAIL(*o); i++)
        {
            setMasakan(&ELMT(*o, i), ELMT(*o, i + 1));
        }
        IDX_TAIL(*o) -= 1;
    }
}

void setMasakan(Masakan *m, Masakan val)
{
    NOMOR(*m) = NOMOR(val);
    DURASI(*m) = DURASI(val);
    KETAHANAN(*m) = KETAHANAN(val);
    HARGA(*m) = HARGA(val);
}

int find(Order o, int val)
{
    int i = 0;
    boolean found = false;
    while (i <= IDX_TAIL(o) && !found)
    {
        if (NOMOR(ELMT(o, i)) == val)
        {
            found = true;
        }
        else
        {
            i++;
        }
    }
    if (found)
    {
        return i;
    }
    else
    {
        return IDX_UNDEF;
    }
}

int isIn(Order o, int val)
{
    return find(o, val) != IDX_UNDEF;
}

void displayOrder(Order o)
{
    printf("Daftar Pesanan\n");
    printf("Makanan         | Durasi memasak        | Ketahanan     | Harga\n");
    printf("-----------------------------------------------------------------------\n");
    if (IDX_TAIL(o) != IDX_UNDEF)
    {
        for (int i = 0; i <= IDX_TAIL(o); i++)
        {
            printf("M%d              | %d                     | %d             | %d        \n", NOMOR(ELMT(o, i)), DURASI(ELMT(o, i)), KETAHANAN(ELMT(o, i)), HARGA(ELMT(o, i)));
        }
    }
    else
    {
        printf("                |                       |               |            ");
    }
}

void displayCooking(Order o)
{
    int count = 0;
    printf("\nDaftar Makanan yang sedang dimasak\n");
    printf("Makanan         | Sisa durasi memasak\n");
    printf("-------------------------------------\n");

    for (int i = 0; i <= IDX_TAIL(o); i++)
    {
        if (o.buffer[i].durasi > 0)
        {
            printf("M%d              | %d           \n", NOMOR(ELMT(o, i)), DURASI(ELMT(o, i)));
            count++;
        }
    }
    if (count == 0)
    {
        printf("                |              \n");
    }
}

void displayReady(Order o)
{
    int count = 0;
    printf("\nDaftar Makanan yang dapat disajikan\n");
    printf("Makanan         | Sisa ketahanan makanan\n");
    printf("----------------------------------------\n");

    for (int i = 0; i <= IDX_TAIL(o); i++)
    {
        if (DURASI(ELMT(o, i)) == 0)
        {
            printf("M%d              | %d            \n", NOMOR(ELMT(o, i)), KETAHANAN(ELMT(o, i)));
            count++;
        }
    }

    if (count == 0)
    {
        printf("                |              \n");
    }
}