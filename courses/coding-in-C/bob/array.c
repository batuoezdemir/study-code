#include <stdio.h>

int main(void) {
    int x = 10;
    int *p = &x;
    int **pp = &p;

    // TODO: complete the output statements
    printf("x = %d\n", x);
    printf("x via p = %d\n", *p);
    printf("x via pp = %d\n", **pp);

    **pp = 42;
    printf("After modifying via pp:\n");
    printf("x = %d\n", x);
    /* What are the types of the following expressions?
    x --> Wertetyp: int
    p --> Zeiger auf Adresse von x
    *p --> Zeiger auf Wert von x
    pp --> Zeiger auf Adresse von p     
    *pp --> Zeiger auf Wert von p (Adresse von x)
    **pp --> Zeiger auf Wert von x
    */
    return 0;
}