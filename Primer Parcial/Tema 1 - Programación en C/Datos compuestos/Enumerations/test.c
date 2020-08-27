#include <stdio.h>

enum week {
    Mon,
    Tue,
    Wed,
    Thur,
    Fri,
    Sat,
    Sun
};

int main() {
    enum week day;
    day = Wed;
    printf("%d\n", day);

    // Needed to access the values in the enumerations, we need to know what's saved in there
    char *week[7] = {"Mon", "Tue", "Wed", "Thur", "Fri", "Sat", "Sun"};

    int i;
    for(i = Mon; i<= Sun; i++) {
        printf("%d = %s\n", i, week[i]);
    }

    printf("\n\n");
    
    for(day = Mon; day <= Sun; ++day) {
        printf("%d = %s\n", day, week[day]);
    }
    
    return 0;
}

/*
    Prints:

    2
    0 = Mon
    1 = Tue
    2 = Wed
    3 = Thur
    4 = Fri
    5 = Sat
    6 = Sun


    0 = Mon
    1 = Tue
    2 = Wed
    3 = Thur
    4 = Fri
    5 = Sat
    6 = Sun

*/
