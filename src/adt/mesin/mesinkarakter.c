#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void START(string file)
{
    pita = fopen(file, "r");
    ADV();
}

void ADV()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);

        EOP = (feof(pita));
        if (IsEOP())
        {
            fclose(pita);
        }
    }
}

char GetCC()
{
    return currentChar;
}

boolean IsEOP()
{
    return EOP;
}

void startInput()
{
    pita = stdin;
    ADV();
}