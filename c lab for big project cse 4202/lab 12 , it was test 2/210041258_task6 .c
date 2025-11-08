// Define a structure to store student data
struct _student {
    char nickname[16];
    float attendance_percentage;
    float quiz[3];
    float mid;
    float fin;
    float grade;
}Student;


float calculateGrade(struct Student *s) {
    float quiz_grade = 0.0;
    int min_quiz_score = s->quiz[0];

    // Calculate the total quiz score and find the minimum quiz score
    for (int i = 0; i < 3; i++) {
        quiz_grade += s->quiz[i];
        if (s->quiz[i] < min_quiz_score) {
            min_quiz_score = s->quiz[i];
        }
    }

    // Subtract the minimum quiz score and calculate the quiz average
    quiz_grade -= min_quiz_score;
    float quiz_average = quiz_grade / 3.0;

    // Calculate the overall attendance grade
    float attendance_grade = s->attendance_percentage / 10.0;

    // Calculate the mid and fin exam grades
    float mid_grade = s->mid / 75.0 * 25.0;
    float fin_grade = s->fin / 150.0 * 50.0;

    // Calculate the total grade for the student
    float total_grade = attendance_grade + quiz_average + mid_grade + fin_grade;
    return total_grade;
}

int compareStudents(const void* a, const void* b) {
    Student* s1 = (Student*)a;
    Student* s2 = (Student*)b;

    // If grades are different, sort by grade in descending order
    if (s1->grade != s2->grade) {
        return s2->grade - s1->grade;
    }
    // If grades are the same, sort by nickname in ascending order
    else {
        return strcmp(s1->nickname, s2->nickname);
    }
}

int main() {
    int num_students;
    scanf("%d", &num_students);
    Student* students = (Student*)malloc(num_students * sizeof(Student));

    // Read data for each student and calculate their grades
    for (int i = 0; i < num_students; i++) {
        scanf("%s %f %f %f %f %f", students[i].nickname, &students[i].attendance_percentage,
              &students[i].quiz[0], &students[i].quiz[1], &students[i].quiz[2], &students[i].quiz[3],
              &students[i].mid, &students[i].fin);
        students[i].grade = calculateGrade(students[i]);
    }

    qsort(students, num_students, sizeof(Student), compareStudents);

    // Print the sorted list of students
    for (int i = 0; i < num_students; i++) {
        printf("%s %.2f\n", students[i].nickname, students[i].grade);
    }

    // Free the allocated memory
    free(students);
    return 0;
}

