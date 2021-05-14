#include <decision.h>

std::string get_letter_grade_using_if(int grade)
{
    if (grade >= 90 && grade <= 100)
    {
        return "A";
    }
    else if (grade >= 80)
    {
        return "B";
    }
    else if (grade >= 70)
    {
        return "C";
    }
    else if (grade >= 60)
    {
        return "D";
    }
    else
    {
        return "F";
    }
}

std::string get_letter_grade_using_switch(int grade)
{
    std::string letter_grade;

    switch (grade)
    {
    case 90 ... 100:
        letter_grade = "A";
        break;
    case 80 ... 89:
        letter_grade = "B";
        break;
    case 70 ... 79:
        letter_grade = "C";
        break;
    case 60 ... 69:
        letter_grade = "D";
        break;
    case 0 ... 59:
        letter_grade = "F";
        break;
    }

    return letter_grade;
}
