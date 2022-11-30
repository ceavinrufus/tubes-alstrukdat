#include <stdio.h>
#include <stdlib.h>
#include "interface.h"
#include <time.h>

void sleep(int milidetik)
{
    clock_t start_time = clock();

    while (clock() < start_time + milidetik)
    {
    }
}

void clear()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void loadingGame(Word gameName)
{
    clear();
    int i = 0;
    while (i < 25)
    {
        printf("Loading ");
        printWord(gameName);
        printf("...\n");
        printf("[");
        for (int j = 0; j < i; j++)
        {
            printf("=");
        }
        for (int j = 0; j < 25 - i; j++)
        {
            printf(" ");
        }

        printf("]");
        printf(" %d%%", i * 4);
        i++;
        clear();
    }
}

void skippingGame(Word gameName)
{
    printf("Skipping ");
    printWord(gameName);
    for (int i = 0; i < 3; i++)
    {
        printf(".");
        sleep(100);
    }
    sleep(1000);
    printf("\n");
}

void gambarBNMO()
{
    printf("                  .______   .__   __. .___  ___.   ______      \n");
    printf("                  |   _  \\  |  \\ |  | |   \\/   |  /  __  \\ \n");
    printf("                  |  |_)  | |   \\|  | |  \\  /  | |  |  |  |  \n");
    printf("                  |   _  <  |  . `  | |  |\\/|  | |  |  |  |   \n");
    printf("                  |  |_)  | |  |\\   | |  |  |  | |  `--'  |   \n");
    printf("                  |______/  |__| \\__| |__|  |__|  \\______/   \n");
}

void gambarKarakterBNMO()
{
    printf("                          @                                                  \n");
    printf("                  @@******************@@@@.                              \n");
    printf("         @#*************************************@@@               \n");
    printf("  @*********************************@&//////////////              \n");
    printf(" @*************************@%%////////////@@.     @//              \n");
    printf(" #((((((((((((((((((@//////////&@*.             .//@         \n");
    printf(" (.................(////@               @@@     .@//             \n");
    printf("@.....@@@@@@@@@@...(////@.     @@@      @@@     .@//             \n");
    printf(" (....@@..@@..@@...(////@.     @@@             .@//%%            \n");
    printf(" @.....@@@@@@@@....(@////.         *****       ..//@             \n");
    printf(" @.....@@@@@@@@@...(&////@                  @//////@            \n");
    printf(" @........@@@......((/////.        @///////////////@            \n");
    printf(" @.....@@@@@@@@@...((@//////////////@@@@@@///@@////@@      $$\n");
    printf(" #.....@@@@@@@@@....((/////@@@@@@@/////////////////@/@    @//@\n");
    printf("  &.........@@@@.....(//////////////////@/////@@///@//@   @//@\n");
    printf("  @.........@@@@.....(@////////////////@@@///@@@@//@@///////@ \n");
    printf("  @....@@@@@@@@@.....(//////@@////////////@@//@@///@  @///@  \n");
    printf("  *......@@@@@.......(@/////@@//////////@@@@@@/////@   @@@       \n");
    printf("   (...@@/////@@.....(@/////////////////@@@@@@////@             \n");
    printf("   @...@@/////@@.....(//////////@@@@//////@@////@               \n");
    printf("   @...(@((//@.......((//@@@@///////////////@@                   \n");
    printf("    @...(@///@........(@//////////////&@                        \n");
    printf("      @.(@///@........(@////////////@(((                         \n");
    printf("         @///@@@@@((((((((@//       @(((                             \n");
    printf("         @///    @(((               @(((@@(                          \n");
    printf("          @@&    @(((                                              \n");
    printf("                 @(((@@@                                              \n");
}

void gambarDinerDash()
{
    printf("                                                                                      \n");
    printf("                                                                                      \n");
    printf("&(,,##&&&&&&&##,./&,                                                                   \n");
    printf("##.                .#*  ,,,,,,,,,,,                                                   \n");
    printf("(%%.    #@@@@@@&*,   .,@ %%.       .@( @@.(    (*. .@. ,,,,,,,,,@@  ,,,,,,,,,,,,        \n");
    printf("*&,....#%%////&@@@/....,&&(// ..(##@@(. .,@@  **  .&@ **...*.. ./( /%%/.       .*#      \n");
    printf(".&,....##      *@@,....&*@@*...(@@@@,...,@@. ,/..,&@.#.....,*///@.&. ./(##%%#/* ..(    \n");
    printf(".@*,,,,#%%       &&,,,,*@  @,..,#@@ @*...../%%  #..,&@.#...(&#*,/@@.&,../@@@@@@@,..(&   \n");
    printf(" @*,,,,(&       @*,,,,%%( .&,,,,%%@@ @/,.,,.,.#&%%.,,%%@.#.......,/@. %%*..*@   *&.../&@   \n");
    printf(" @/***,(@     ##****,&&  ,%%,,,*&@%% &/,,,&&.,,,#,,*%%@,#,,,(@@@@@@. #/,,*(/,,,,,/&@@,   \n");
    printf(" @(****(@  *&******(@(   /#***,@@# %%(,**%%@@&,*,*,*%%@,%%,,,(@(/#%%#*&#(,*,,,*/,,,,#&     \n");
    printf(" @(****(&(*******#@&  *%%*********@@@(***%%@%%,@@****#@,%%*********,*%%@#***%%@@@&(*,**##   \n");
    printf(" &#/////**/**/%%@@(     @%%&&&@@@@@@@@#***#@%%   @@**#@,%%**/(##&@@@@@@#***#&  @@%%/*(%%@/  \n");
    printf(" %%%%//////#&@@@*                     &@@@@@%%     %%@#@,@@@@@@@#*    (%%%%%%#%%&    &@@@*    \n");
    printf(" #%%%%&&@@@(                                        #@,              (((((.             \n");
    printf("  .                                                                                   \n");
    printf("              ,,.,*/((/*...,           #%%%%                                  \n");
    printf("            #.              *%%,       && .@    @@(#**%%#(*#&/ /#%%&&(      .*(\n");
    printf("            #.    ..,....  .  . %%    (@.  .@  #%% .  ........@* ..,@ ,@# ...@\n");
    printf("            (,    *@@@@@@@&*, .. (* .@,.....@@&... @@@@@@@#*&%%...,@@%%%%# .,.@\n");
    printf("            /*....*&    ,%%@@@,....%%,@(..*%%..,&@&,.,...*#&@@&%%&.,,.@@%%%%#.,,,&\n");
    printf("            **....*&       &@(..../@%%...@&(..*@@@@#//*,,,,,,*&/,,,@@%%%%%%.,,,&\n");
    printf("            ,(,,,,*@       *@*,,,,&@,,,,,,,,,,*@@@@@@@@,,,,,,&@*,,#*,*,**,,&\n");
    printf("            ,#,,,,*@      .@**,,,#@,*,,&@@@%%,***@,@@$@@%%@@****@****/%%@%%,***&\n");
    printf("            .%%****/@.    %%#*****%%@/***&@/&@&#****@****@@#&****@/***@&%%#,***&\n");
    printf("            .&****/@. #&,*****(@@(**,%%@   @&@(***(@*********/@&****@%%%%#*/*/&\n");
    printf("            .@/***/#/*******#@%%@@@@@@#     @@@#@@@@@@@@@@@@@@%%&@@@@@%%%%&@@@@@\n");
    printf("             @/////////*(&@@,               (*,..           .      ......   \n");
    printf("             @////*(%%&@@%%                                                   \n");
    printf("             @%%@@@@(.                                                       \n");
    printf("                                                                            \n");
}

void gambarHangman(int kesempatan)
{
}