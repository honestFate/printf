#include "ft_printf.h"

int main()
{
    int i = printf("%sююю\n", "123456");
    int l = ft_printf("%sююю\n", "123456");
    printf("pf - %d\nft_pf - %d\n", i, l);
}