#include <bits/stdc++.h>
using namespace std;
// assuming total course = 12, can be set any variable no in the code but minimum no is 12-->
const int NUM_COURSES = 12;
const int MAX_ITERATIONS = 3; // as in each iteration we are alloting only 0.5 of a course to each professor

    // 4 FD CDC, 4 FD Ele, 2 HD CDC, 2 HD Elc 
    // index 0- FD-CDC-1
    // index 1- FD-CDC-2
    // index 2- FD-CDC-3
    // index 3- FD-CDC-4
    // index 4- FD-ELEC-1
    // index 5- FD-ELEC-2
    // index 6- FD-ELEC-3
    // index 7- FD-ELEC-4
    // index 8- FD-CDC-1
    // index 9- FD-CDC-2
    // index 10- HD-ELEC-1
    // index 11- HD-ELEC-2

struct Faculty {
    int facultyNumber;  // Added faculty number
    double originalType;
    double type; // to keep every thing in int(1,2,3)facultytype not (0.5,1,1.5)
    vector<int> preferences;
    vector<vector<int>> allotment;

    Faculty(int number, double origType, const vector<int>& prefs)
        : facultyNumber(number), originalType(origType), type(2 * origType),
          preferences(prefs), allotment(MAX_ITERATIONS, vector<int>(NUM_COURSES, -1)) {}
};

void copyArray(const double src[][2], double dest[][2], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            dest[i][j] = src[i][j];
        }
    }
}

void copyVector(const double src[], double dest[], int size) {
    for (int i = 0; i < size; i++) {
        dest[i] = src[i];
    }
}

void printAllotment(const Faculty& faculty) {
    cout << "Faculty " << faculty.facultyNumber << ": " << endl;
    for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
        cout << "Iteration " << iteration + 1 << ": ";
        const auto& assignments = faculty.allotment[iteration];
        if (all_of(assignments.begin(), assignments.end(), [](int course) { return course == -1; })) {
            cout << "-1";  // No allotment in this iteration
        } 
        else{
            for (int course : assignments) {
                cout << (course == -1 ? -1 : course - 1) << " ";  // Print -1 if no allotment
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double courses[NUM_COURSES][2];

    for (int i = 0; i < NUM_COURSES; i++) {
        courses[i][0] = i + 1;
        courses[i][1] = 2;
    }

    int facultyCount;
    cin >> facultyCount;

    vector<Faculty> faculties;

    for (int i = 0; i < facultyCount; i++) {
        double origFacultyType;
        cin >> origFacultyType;

        vector<int> facultyPrefs(NUM_COURSES);
        for (int j = 0; j < NUM_COURSES; j++) {
            cin >> facultyPrefs[j];
        }

        faculties.emplace_back(i + 1, origFacultyType, facultyPrefs);
    }

    int randomFaculty[facultyCount];
    iota(randomFaculty, randomFaculty + facultyCount, 0);

    int cases = 0;
    for (int v = 0; cases < 5; v++) {
        double tempCourses[NUM_COURSES][2];
        copyArray(courses, tempCourses, NUM_COURSES, 2);

        vector<Faculty> tempFaculties = faculties;
        int validity = 0;

        srand(time(0));
        random_shuffle(randomFaculty, randomFaculty + facultyCount);

        for (int iteration = 0; iteration < MAX_ITERATIONS; iteration++) {
            for (int i = 0; i < facultyCount; i++) {
                int allottedSuccessfully = 0;
                for (int j = 0; allottedSuccessfully == 0 && j < NUM_COURSES; j++) {
                    int pref = tempFaculties[randomFaculty[i]].preferences[j];
                    if (tempCourses[pref][1] != 0 && tempFaculties[randomFaculty[i]].type != 0) {
                        tempFaculties[randomFaculty[i]].allotment[iteration][j] = tempCourses[pref][0];
                        tempCourses[pref][1] = tempCourses[pref][1] - 1;
                        tempFaculties[randomFaculty[i]].type = tempFaculties[randomFaculty[i]].type - 1;
                        allottedSuccessfully = 1;
                    }
                }
            }
        }

        for (int k = 0; k < NUM_COURSES; k++) {
            if (tempCourses[k][1] == 1 && (tempCourses[0][1] != 0) && (tempCourses[1][1] != 0) &&
                (tempCourses[2][1] != 0) && (tempCourses[3][1] != 0) && (tempCourses[8][1] != 0) 
                && (tempCourses[9][1] != 0)) {
                // not a valid solution
            } else {
                validity++;
            }
        }

        if (validity == NUM_COURSES) {
            cases++;
            cout << "Case: " << cases << endl;
            for (const auto& faculty : tempFaculties) {
                printAllotment(faculty);
            }
        }
    }

    return 0;
}
