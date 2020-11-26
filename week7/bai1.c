#include <stdio.h>
#include "bai1.h"

void main()
{

    int m = 3;
    while (m)
    {
        elementype tmp1 = readNode();
        insertAfter(tmp1);
        m--;
    }

    traversingList(root);
}
