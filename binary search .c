#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float attendance;
};

int binarySearch(struct Student s[], int n, int key) {
    int low = 0, high = n - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (s[mid].id == key)
            return mid;
        else if (s[mid].id < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;  // not found
}

int main() {
    int n, i, id, pos;
    struct Student s[100];

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("\nEnter student details (in sorted order of ID):\n");
    for (i = 0; i < n; i++) {
        printf("\nStudent %d\n", i + 1);
        printf("Enter ID: ");
        scanf("%d", &s[i].id);
        printf("Enter Name: ");
        scanf("%s", s[i].name);
        printf("Enter Attendance Percentage: ");
        scanf("%f", &s[i].attendance);
    }

    printf("\nEnter the Student ID to search: ");
    scanf("%d", &id);

    pos = binarySearch(s, n, id);

    if (pos != -1) {
        printf("\nRecord Found!\n");
        printf("------------------------------\n");
        printf("Student ID        : %d\n", s[pos].id);
        printf("Student Name      : %s\n", s[pos].name);
        printf("Attendance        : %.2f%%\n", s[pos].attendance);

        if (s[pos].attendance >= 90)
            printf("Remarks           : Excellent\n");
        else if (s[pos].attendance >= 75)
            printf("Remarks           : Good\n");
        else
            printf("Remarks           : Need Improvement\n");
    } else {
        printf("\nRecord Not Found!\n");
    }

    return 0;
}