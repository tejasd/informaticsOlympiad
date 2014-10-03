/* Algorithm : Convert each card into a number (xyy) where x denotes suite and yy denotes card number (in order i.e 1 is 2, 13 is Ace). Sequentially check for hand types and if
that type of hand is found to exist then add to priority queue a number (xyy) where x is hand type (9 is straight flush, 1 is just high card) and then finally when this is done
for both hands, remove elements from priority queue and see which is greater. */

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

int w [6], b [6], j, high_w, high_b, three_of_kind_w = 0, three_of_kind_b = 0, pair_w = 0, pair_b = 0 ; //J IS USED AS ITERATOR AS WELL AS A BOOL TYPE SWITCH TO STOP CHECKING FOR HAND TYPES
char temp1;
int kw, kb, winner, kpw, kpb; //to find which case is satisfied in two pairs and pairs :: WINNER - 1BLACK 2WHITE 0 TIE
string input_string;

void high_card (int * arrayw, int * arrayb);

int compare (const void *a , const void *b)
    {
        if (*(int*)a > *(int*)b )
        {

            return 1;
        }
        else if (*(int*)a < *(int*)b )
        {
            return -1;
        }
        else
        {
            return 0;
        }
    }

void input() //function works flwalessly also sorts these arrays
{
    //initialise arrays to zero
    for (int i = 0; i < 6; ++i )
    {
        w [i] = 0;
        b [i] = 0;
    }

    j = 0;

    for (int i = 0; i < 14; ++i) //for black
    {

        if (input_string[i] == ' ')
        {
            continue;

        }
        else
        {
            temp1 = input_string[i+1];
            switch (temp1)
            {
                case 'C' : b[j] += 100;
                break;
                case 'D' : b[j] += 200;
                break;
                case 'H' : b[j] += 300;
                break;
                default : b[j] += 400;
                break;

            }
            temp1 = input_string [i];

            switch (temp1)
            {
                case '2' : b[j] += 1;
                break;
                case '3' : b[j] += 2;
                break;
                case '4' : b[j] += 3;
                break;
                case '5' : b[j] += 4;
                break;
                case '6' : b[j] += 5;
                break;
                case '7' : b[j] += 6;
                break;
                case '8' : b[j] += 7;
                break;
                case '9' : b[j] += 8;
                break;
                case 'T' : b[j] += 9;
                break;
                case 'J' : b[j] += 10;
                break;
                case 'Q' : b[j] += 11;
                break;
                case 'K' : b[j] += 12;
                break;
                default : b[j] += 13;
                break;
            }
            ++j;
            ++i;
        }
    }
    j = 0;
    for (int i = 15; i < 29; ++i) //for white
    {

        if (input_string[i] == ' ')
        {
            continue;

        }
        else
        {
            temp1 = input_string[i+1];
            switch (temp1)
            {
                case 'C' : w [j] += 100;
                break;
                case 'D' : w [j] += 200;
                break;
                case 'H' : w [j] += 300;
                break;
                default : w [j] += 400;
                break;

            }
            temp1 = input_string [i];

            switch (temp1)
            {
                case '2' : w[j] += 1;
                break;
                case '3' : w[j] += 2;
                break;
                case '4' : w[j] += 3;
                break;
                case '5' : w[j] += 4;
                break;
                case '6' : w[j] += 5;
                break;
                case '7' : w[j] += 6;
                break;
                case '8' : w[j] += 7;
                break;
                case '9' : w[j] += 8;
                break;
                case 'T' : w[j] += 9;
                break;
                case 'J' : w[j] += 10;
                break;
                case 'Q' : w[j] += 11;
                break;
                case 'K' : w[j] += 12;
                break;
                default : w[j] += 13;
                break;
            }
            ++j;
            ++i;
        }
    }

    //sort


    //debugging code begins
    for (int i = 0; i < 5; ++i)
    {
        cout << b[i] << " " << w[i] << endl;
    }
    //debugging code ends

    //sort these arrays

    qsort (w, 5, sizeof(int), compare);
    qsort (b, 5, sizeof(int), compare);
    cout << "after sorting \n";
    for (int i = 0; i < 5; ++i)
    {
        cout << b[i] << " " << w[i] << endl;
    }


}

void straight_flush_w()
{
    j = 1;
    int values;
    for (int i = 1; i < 5; ++i)
    {
        if (w[i-1] + 1 == w[i])
        {
            continue;
        }
        else
        {
            j = 0;
            break;
        }

    }
    if (j == 1)
    {
       w[5] = (900 + (w[4] % 100));
       high_w = w[4] % 100;
    }
    return;



}
void four_of_a_kind_w ()
{
    int wd[5];
    for (int i = 0; i < 5; ++i)
    {
        wd[i] = w[i] % 100;
    }
    qsort (wd, 5, sizeof(int), compare);
    j = 1;
    if (wd[0] == wd[1] )//first 4 are equal
    {
        for (int i = 2; i < 4; ++i)
        {
           if (wd[0] == wd[i])
           {
               continue;
           }
           else
           {
               j = 0;
               break;
           }
        }
    }
    else if (wd[3]== wd[4])
    {
        for (int i = 1; i < 3; ++i)
        {
            if (wd[i]== wd[4])
            {
                continue;
            }
            else
            {
                j = 0;
                break;
            }
        }
    }
    else
    {
        j = 0;
    }
    if (j == 1)
    {
       w[5] = 800 + wd[3];
    }
    return;
}
void full_house_w () // and three of a kind
{
    j = 0;
    int wd[5];
    for (int i = 0; i < 5; ++i)
    {
        wd[i] = w[i] % 100;
    }
    qsort (wd, 5, sizeof(int), compare);
    if (wd[0] == wd[1] && wd[0] == wd[2])
    {
        if (wd[3] == wd[4])
        {
            j = 1;
        }
        else
        {
            three_of_kind_w = wd[0];
        }
    }
    else if (wd[2] == wd[1] && wd[3] == wd[2])
    {
        if (wd[0] == wd[4])
        {
            j = 1;
        }
        else
        {
            three_of_kind_w = wd[2];
        }
    }
    else if (wd[2] == wd[3] && wd[4] == wd[2])
    {
        if (wd[0] == wd[1])
        {
            j = 1;
        }
        else
        {
            three_of_kind_w = wd[2];
        }
    }
    else
    {
        j = 0;
    }
    if (j == 1)
    {
        w[5] = wd[2] + 700;
    }
    return;

}

void flush_w ()
{
    int wd[5];
    for (int i = 0; i < 5; ++i)
    {
        wd[i] = w[i] / 100;
    }
    j = 1;
    for (int i = 1; i < 5; ++i)
    {
        if (wd[i] == wd[i-1])
        {
            continue;
        }
        else
        {
            j = 0;
            break;
        }
    }
    if (j == 1)
    {
        w[5] = 600 + (w[4] % 100);
    }
    return;
}

void straight_w ()
{
    j = 1;
    int wd[5];
    for (int i = 0; i < 5; ++i)
    {
        wd[i] = w[i] % 100;
    }
    qsort (wd, 5, sizeof(int), compare);

    for (int i = 1 ; i < 5; ++i)
    {
        if (wd[i] == wd [i-1] + 1)
        {
            continue;
        }
        else
        {
            j = 0;
            break;
        }
    }
    if (j == 1)
    {
        w[5] = 500 + wd[4];
    }
    return;
}

void two_pairs_w ()
{
    j = 0;

    int wd[5];
    for (int i = 0; i < 5; ++i)
    {
        wd[i] = w[i] % 100;
    }
    qsort (wd, 5, sizeof(int), compare);

    if (wd[0] == wd [1])
    {
        if (wd[2] == wd[3])
        {
            j = 1;
            kw = 1;
        }
        else if (wd[3] == wd[4])
        {
            j = 1;
            kw = 3;
        }
        else //pair also computed in this
        {
            pair_w = wd[0];
            high_w = wd[4];
            kpw = 1;
        }

    }
    else if (wd[1] == wd [2])
    {
        if (wd[3] == wd[4])
        {
           j = 1;
           kw = 2;
        }
        else
        {
            pair_w = wd[1];
            high_w = wd[4];
            kpw = 2;
        }

    }
    else
    {
        j = 0;
    }
    if (j == 1)
    {
        w[5] = 300;
        if (kw == 1)
        {
            if (wd[0] > wd [2])
            {
                w[5] += wd[0];
                high_w = wd [2];
            }
            else
            {
                w[5] += wd[2];
                high_w = wd[0];
            }

        }
        else if (kw == 2)
        {
            if (wd[1] > wd [3])
            {
                w[5] += wd[1];
                high_w = wd [3];
            }
            else
            {
                w[5] += wd[3];
                high_w = wd[1];
            }

        }
        else
        {
            if (wd[0] > wd[4])
            {
                w[5] += wd[0];
                high_w = wd[4];
            }
            else
            {
                w[5] += wd[4];
                high_w = wd[0];
            }
        }
    }

}

void pairs_w ()
{
    j = 0;
    int wd[5];
    for (int i = 0; i < 5; ++i)
    {
        wd[i] = w[i] % 100;
    }
    qsort (wd, 5, sizeof(int), compare);

        if (wd[0] == wd[1])
        {
            j = 1;
            w[5] = 200 + wd[0];
            high_w = wd[4];
            kpw = 1;
        }
        else if (wd[1] == wd[2])
        {
            j = 1;
            w[5] = 200 + wd[2];
            high_w = wd[4];
            kpw = 2;
        }

    else if (wd[2] == wd[3])
    {
        j = 1;
        w[5] = 200 + wd[2];
        high_w = wd[4];
        kpw = 3;
    }
    else if (wd[3] == wd[4])
    {
        j = 1;
        w[5] = 200 + wd[3];
        high_w = wd[2];
        kpw = 4;
    }
    else
    {
        j = 0;
    }
    return;
}




void straight_flush_b()
{
    j = 1;
    int values;
    for (int i = 1; i < 5; ++i)
    {
        if (b[i-1] + 1 == b[i])
        {
            continue;
        }
        else
        {
            j = 0;
            break;
        }

    }
    if (j == 1)
    {
       b[5] = (900 + (b[4] % 100));
       high_b = b[4] % 100;
    }
    return;



}
void four_of_a_kind_b ()
{
    int bd[5];
    for (int i = 0; i < 5; ++i)
    {
        bd[i] = b[i] % 100;
    }
    qsort (bd, 5, sizeof(int), compare);
    j = 1;
    if (bd[0] == bd[1] )//first 4 are equal
    {
        for (int i = 2; i < 4; ++i)
        {
           if (bd[0] == bd[i])
           {
               continue;
           }
           else
           {
               j = 0;
               break;
           }
        }
    }
    else if (bd[3]== bd[4])
    {
        for (int i = 1; i < 3; ++i)
        {
            if (bd[i]== bd[4])
            {
                continue;
            }
            else
            {
                j = 0;
                break;
            }
        }
    }
    else
    {
        j = 0;
    }
    if (j == 1)
    {
       b[5] = 800 + bd[3];
    }
    return;
}
void full_house_b () // and three of a kind
{
    j = 0;
    int bd[5];
    for (int i = 0; i < 5; ++i)
    {
        bd[i] = b[i] % 100;
    }
    qsort (bd, 5, sizeof(int), compare);
    if (bd[0] == bd[1] && bd[0] == bd[2])
    {
        if (bd[3] == bd[4])
        {
            j = 1;
        }
        else
        {
            three_of_kind_b = bd[0];
        }
    }
    else if (bd[2] == bd[1] && bd[3] == bd[2])
    {
        if (bd[0] == bd[4])
        {
            j = 1;
        }
        else
        {
            three_of_kind_b = bd[2];
        }
    }
    else if (bd[2] == bd[3] && bd[4] == bd[2])
    {
        if (bd[0] == bd[1])
        {
            j = 1;
        }
        else
        {
            three_of_kind_b = bd[2];
        }
    }
    else
    {
        j = 0;
    }
    if (j == 1)
    {
        b[5] = bd[2] + 700;
    }
    return;

}

void flush_b ()
{
    int bd[5];
    for (int i = 0; i < 5; ++i)
    {
        bd[i] = b[i] / 100;
    }
    j = 1;
    for (int i = 1; i < 5; ++i)
    {
        if (bd[i] == bd[i-1])
        {
            continue;
        }
        else
        {
            j = 0;
            break;
        }
    }
    if (j == 1)
    {
        b[5] = 600 + (b[4] % 100);
    }
    return;
}

void straight_b ()
{
    j = 1;
    int bd[5];
    for (int i = 0; i < 5; ++i)
    {
        bd[i] = b[i] % 100;
    }
    qsort (bd, 5, sizeof(int), compare);

    for (int i = 1 ; i < 5; ++i)
    {
        if (bd[i] == bd[i-1] + 1)
        {
            continue;
        }
        else
        {
            j = 0;
            break;
        }
    }
    if (j == 1)
    {
        b[5] = 500 + bd[4];
    }
    return;
}

void two_pairs_b ()
{
    j = 0;

    int bd[5];
    for (int i = 0; i < 5; ++i)
    {
        bd[i] = b[i] % 100;
    }
    qsort (bd, 5, sizeof(int), compare);

    if (bd[0] == bd[1])
    {
        if (bd[2] == bd[3])
        {
            j = 1;
            kb = 1;
        }
        else if (bd[3] == bd[4])
        {
            j = 1;
            kb = 3;
        }
        else //pair also computed in this
        {
           j = j;
        }

    }
    else if (bd[1] == bd[2])
    {
        if (bd[3] == bd[4])
        {
           j = 1;
           kb = 2;
        }
        else
        {
            j = j;
        }

    }
    else
    {
        j = 0;
    }
    if (j == 1)
    {
        b[5] = 300;
        if (kb == 1)
        {
            if (bd[0] > bd[2])
            {
                b[5] += bd[0];
                high_b = bd[2];
            }
            else
            {
                b[5] += bd[2];
                high_b = bd[0];
            }

        }
        else if (kb == 2)
        {
            if (bd[1] > bd[3])
            {
                b[5] += bd[1];
                high_b = bd[3];
            }
            else
            {
                b[5] += bd[3];
                high_b = bd[1];
            }

        }
        else
        {
            if (bd[0] > bd[4])
            {
                b[5] += bd[0];
                high_b = bd[4];
            }
            else
            {
                b[5] += bd[4];
                high_b = bd[0];
            }
        }
    }

}

void pairs_b ()
{



        int bd[5];
        for (int i = 0; i < 5; ++i)
        {
            bd[i] = b[i] % 100;
        }
        qsort (bd, 5, sizeof(int), compare);

        if (bd[0] == bd[1])
        {
            j = 1;
            b[5] = 200 + bd[0];
            high_b = bd[4];
            kpb = 1;
        }
        else if (bd[1] == bd[2])
        {
            j = 1;
            b[5] = 200 + bd[2];
            high_b = bd[4];
            kpb = 2;
        }
        else if (bd[2] == bd[3])
        {
            j = 1;
            b[5] = 200 + bd[2];
            high_b = bd[4];
            kpb = 3;

        }
        else if (bd[3] == bd[4])
        {
            j = 1;
            b[5] = 200 + bd[3];
            high_b = bd[2];
            kpb = 4;
        }
        else
        {
            j = 0;
        }


    return;
}



void check_winner()
{
    int bd[5], wd[5], wp1, wp2, bp1, bp2; //p1 p2 are variables for which two are pairs in pair case
    for (int i = 0; i < 5; ++i)
    {
        bd[i] = b[i] % 100;
    }
    qsort (bd, 5, sizeof(int), compare);

    for (int i = 0; i < 5; ++i)
    {
        wd[i] = w[i] % 100;
    }
    qsort (wd, 5, sizeof(int), compare);
    cout << "bd and wd\n";
    for (int i = 0; i < 5; ++i)
    {
        cout << bd[i] << " " << wd[i] << endl;
    }
    cout << "over\n";

    int tempw, tempb;
    if (w[5] > b[5])
    {
        winner = 2;
    }
    else if (w[5] < b[5])
    {
        winner = 1;
    }
    else
    {
        if (w[5]/100 == 3)
        {
            if (high_b > high_w)
            {
                winner = 1;
            }
            else if (high_b < high_w)
            {
                winner = 2;
            }
            else
            {
                //check for remaining one
                switch(kw)
                {
                    case 1 : tempw = wd[4];
                    break;
                    case 2 : tempw = wd[0];
                    break;
                    default : tempw = wd[2];
                    break;
                }
                switch(kb)
                {
                    case 1 : tempb = bd[4];
                    break;
                    case 2 : tempb = bd[0];
                    break;
                    default : tempb = bd[2];
                    break;
                }
                cout << "tempw and tempb are " << tempb << " " << tempw << endl;
                if (tempb > tempw)
                {
                    winner = 1;
                }
                else if (tempb < tempw)
                {
                    winner = 2;
                }
                else
                {
                    winner = 0;
                }
            }

        }
        else if (w[5]/100 == 2)
        {
            if (high_b > high_w)
            {
                winner = 1;
            }
            else if (high_w > high_b)
            {
                winner = 2;
            }
            else
            {
                switch(kpb)
                {
                    case 1 : {bp1 = 0;
                    bp2 = 1;
                    break;}
                    case 2 : {bp1 = 1;
                    bp2 = 2;
                    break;}
                    case 3 : {bp1 = 2;
                    bp2 = 3;
                    break;}
                    default : {bp1 = 3;
                    bp2 = 4;
                    break;}

                }
                switch(kpw)
                {
                    case 1 : {wp1 = 0;
                    wp2 = 1;
                    break;}
                    case 2 : {wp1 = 1;
                    wp2 = 2;
                    break;}
                    case 3 : {wp1 = 2;
                    wp2 = 3;
                    break;}
                    default : {wp1 = 3;
                    wp2 = 4;
                    break;}

                }
                wd[wp1] = 0;
                wd[wp2] = 0;
                bd[bp1] = 0;
                bd[bp2] = 0;
                qsort (bd, 5, sizeof(int), compare);
                qsort (wd, 5, sizeof(int), compare);
                cout << "Pair sorted\n";
                for (int a = 0; a < 5; ++a)
                {
                    cout << bd[a] <<" " << wd[a] << endl;
                }
                //insert high card function here
                winner = 0;
                for (int i = 4; i >= 0 ; --i )
                {
                    if (bd[i] > wd[i])
                    {
                        winner = 1;
                        break;
                    }
                    if (bd[i] < wd[i])
                    {
                        winner = 2;
                        break;
                    }
                }

            }

        }
        else if (w[5]/100 == 6)
        {
            //high card function here
            high_card (&wd[4], &bd[4]);
        }
        else if (w[5] == 0)
        {
            //high card
            high_card (&wd[4], &bd[4]);
        }
        else
        {
            if (high_b > high_w)
            {
                winner = 1;
            }
            else if (high_w > high_b)
            {
                winner = 2;
            }
            else
            {
                winner = 0;
            }
        }
    }
}

void high_card (int * arrayw, int * arrayb)
{
    int a = 0;
    for (int i = 0; i < 5 ; ++i)
    {
        if (*arrayb > *arrayw)
        {
            winner = 1;

            return;
        }
        else if (*arrayw > *arrayb)
        {
            winner = 2;

            return;
        }
        else
        {
            i = i;
        }
        --arrayb;
        --arrayw;
    }
    winner = 0;
    return;

}

int main()
{
    for (;;)
    {
        j = 0;
        high_b = 0;
        high_w = 0;
        three_of_kind_b = 0;
        three_of_kind_w = 0;
        pair_b = 0;
        pair_w = 0;
        kw = 0;
        kb = 0;
        winner = 0;
        kpb = 0;
        kpw = 0;
        getline (cin, input_string);
        if (input_string.size() == 0)
        {
            break;
        }
        input();
        //check for types black
        straight_flush_b();
        if (j == 0)
        {
            four_of_a_kind_b();
        }
        if (j == 0)
        {
            full_house_b();
        }
        if (j == 0)
        {
            flush_b();
        }
        if (j == 0)
        {
            straight_b();
        }
        if (j == 0)
        {
            if (three_of_kind_b > 0)
            {
                b[5] = 400 + three_of_kind_b;
                j = 1;
            }

        }
        if (j == 0)
        {
            two_pairs_b();
        }
        if (j == 0)
        {
            pairs_b();
        }
        //end of check for types

        //check for types white
        straight_flush_w();
        if (j == 0)
        {
            four_of_a_kind_w();
        }
        if (j == 0)
        {
            full_house_w();
        }
        if (j == 0)
        {
            flush_w();
        }
        if (j == 0)
        {
            straight_w();
        }
        if (j == 0)
        {
            if (three_of_kind_w > 0)
            {
                b[5] = 400 + three_of_kind_w;
                j = 1;
            }
            else
            {
                j = 0;
            }

        }
        if (j == 0)
        {
            two_pairs_w();
        }
        if (j == 0)
        {
            pairs_w();
        }
        //end of check for types white


        check_winner();
        cout << b[5] << " " << w[5] << endl;

        if (winner == 0)
        {
            cout << "Tie." << endl;
        }
        else if (winner == 1)
        {
            cout << "Black wins." << endl;
        }
        else
        {
            cout << "White wins." << endl;
        }


    }

    return 0;

}








