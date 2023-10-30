#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define     Fn      static
#define     In      inline
#define     F32     float
#define     U0      void

Fn In U0
Calculate(F32 Salary, F32 *Taxes, float Floor, float Ceiling, F32 TaxRate)
{
    F32 Taxable_Salary, Subtract;

    if (Salary < Ceiling)
        Subtract = Salary;
    else
        Subtract = Ceiling;

    Taxable_Salary = (Subtract - Floor);

    *Taxes += TaxRate * Taxable_Salary;
}

int
main(void)
{
    F32     Salary, Taxes = 0;

    scanf("%f", &Salary);
    Taxes = 0;

    if (Salary > 4500.f)
        Calculate   (Salary, &Taxes, 4500.f, Salary, 0.28);

    if (Salary > 3000.f)
        Calculate   (Salary, &Taxes, 3000.f, 4500.f, 0.18);

    if (Salary > 2000.f)
    {
        Calculate   (Salary, &Taxes, 2000.f, 3000.f, 0.08);
        printf      ("R$ %.2f\n", Taxes);
    }
    else
        printf("Isento\n");

    return 0;
}

