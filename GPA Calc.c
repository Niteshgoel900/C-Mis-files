//Homework 3 - Question 5
#include <stdio.h>

int main(void) {
int grade, hours; 
int cum_hours=0;
float gpa;
float cum_gpa_pts=0;
//ask the user the grade
printf("Enter grade, -1 to end:");
scanf("%d",&grade);
//ask the user the hours for the course
printf("Enter the semester hours for this course: ");
scanf("%d",&hours);

 //the while loop will work until grade isn't -1
 while(grade!=-1)
 {
  if(grade>=93)
   if(grade<=100){
      printf("A\n");
      gpa=4.00;
    }
   if(grade>=90)
    if(grade<=92){
      printf("A-\n");
      gpa=3.75;
    }
   if(grade>=86)
    if(grade<=89){
      printf("B+\n");
      gpa=3.25;
    }
   if(grade>=83)
    if(grade<=85){
      printf("B\n");
      gpa=3.00;
    }
   if(grade>=80)
    if(grade<=82){
      printf("B-\n");
      gpa=2.75;
    }
   if(grade>=76)
    if(grade<=79){
      printf("C+\n");
      gpa=2.25;
    }
   if(grade>=73)
    if(grade<=75){
      printf("C\n");
      gpa=2.00;
    }
   if(grade>=70)
    if(grade<=72){
      printf("C-\n");
      gpa=1.75;
    }
   if(grade>=66)
    if(grade<=69){
      printf("D+\n");
      gpa=1.25;
    }
   if(grade>=63)
    if(grade<=65){
      printf("D\n");
      gpa=1.00;
    }
   if(grade>=60)
    if(grade<=62){
      printf("D-\n");
      gpa=0.75;
    }
   if(grade<60){
    printf("F\n");
    gpa=0.00;
    }

    //Calulates the cumulative semester hours
    cum_hours=cum_hours+hours;
    //Calulates the cumulative GPA points
    cum_gpa_pts=cum_gpa_pts+(hours*gpa);
    printf("Cumulative Semester Hours: %d", cum_hours);
    printf("\tCumulative GPA Points %.3f\n\n",cum_gpa_pts);

    printf("%s","\nEnter grade, -1 to end: ");
    scanf("%d",&grade);
    //if grade isn't -1 the while loop will continue again
    if (grade!=-1){
      printf("Enter the semester hours for this course: ");
      scanf("%d",&hours);
    }
 }
 //calculates the gpa
 gpa=cum_gpa_pts/cum_hours;
 printf("GPA is %.3f\n", gpa);


  return 0;
}