//Weyman Fung

#include <stdio.h>

typedef struct 
{
  char occupation_title[31];
  int employment;
  double percent_of_total_employment;	
  double median_hourly_wage;
  double mean_hourly_wage;
  double annual_mean_wage;	
} SalaryInfo;


int main()
{
  FILE * fp; int index; SalaryInfo Occ;
  fp = fopen("salaries.dat", "r");
 
  do {
  printf("Please enter an index (-1 = done): ");
  scanf("%d", &index);
  if (index == -1)
    break;
  fseek(fp, index * sizeof(SalaryInfo), SEEK_SET);
  fread(&Occ, sizeof(SalaryInfo), 1, fp);
  printf("%s: Employment: %d Percent of Employment: %.2lf%%\nMedian hourly wage: $%.2lf, Mean hourly wage: $%.2lf\nMean annual wage: $%.0lf\n\n", Occ.occupation_title, Occ.employment, (Occ.percent_of_total_employment * 100), Occ.median_hourly_wage, Occ.mean_hourly_wage, Occ.annual_mean_wage);
  } while (index != -1);


  return 0; 
}  //main



