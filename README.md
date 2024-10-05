# Disco_Project-Final-
Submitted by: Madhul Aggarwal(2022A7PS1236G), Swetank Rao(2022A7PS0434G), Arul Bhardwaj(2022A7PS1111G)



****1 Project Report****

**1.1 Problem Statement : **
We are provided with the problem statement, in which we have to design University Course Assignment System. There are ”n” faculty members categorised
into three distinct groups: ”x1,” ”x2,” and ”x3.” Faculty in each category are
assigned different course loads, with ”x1” handling 0.5 courses per semester,
”x2” taking 1 course per semester, and ”x3” handling 1.5 courses per semester.
In this system, faculty members have the flexibility to take multiple courses in a
given semester, and conversely, a single course can be assigned to multiple faculty members. When a course is shared between two professors, each professor’s
load is considered to be 0.5 courses. Moreover, each faculty member maintains
a preference list of courses, ordered by their personal preferences, with the most
preferred courses appearing at the top. Importantly, there is no prioritisation
among faculty members within the same category.

**1.2 Objective : **
To print five possible optimal cases of allotting faculties.

**1.3 Required Conditions in Constraints : **
1. The allocation of faculty is randomized and not according to the order of
faculty in the input file.
2. The minimum number of courses should be 12.
3. All the CDC’s should be compulsorily allotted.
4. None of the course should be partially filled.
5. Electives can be left empty.
6. Faculty should be allotted according to their preference list.
7. All professors should be fully allotted, in presence of desired number of
courses.

**1.4 Logic implemented : **
First we will take the number of professors in the university from the user and
we will store them in the array data structure. Now we will take the respective
faculty types and the respective preferences from the user as input. We will then
randomize the array of professors so that they can be allotted randomly. All the
data taken as input will be stored in a structure(called faculty in our code). We
will then create a function(s) which will create a copy of our vectors and arrays
which is storing our inputs so that the original data does not get tampered after
certain operations. Allotments are stored in 2D vectors as number of courses
is dependent on faculty type. Now we will allot courses to the faculty in the
following manner:
1. For getting an optimal solution, we will be allotting only 0.5 of a course
to the faculty so as to satisfy the preference of the most number of faculties.
2. This would require at max 3 iterations as maximum faculty load is 1.5 and
we are allotting 0.5 of a course per iteration.
3. We iterate through the randomized faculty list so that no faculty gets prioritised first.
4. After one complete iteration of the loop, the loop runs two more times for
complete allocation.
5. All of the data goes through a checking process where if and only if all the
constraints are satisfied, then only the program prints the output in the text
file.
6. Now we will check the remaining course load of each course, if any of the
courses is half allotted, the program will not give any output for that case.
7. We will then go forward to check to see if courses from CDC’s are filled or
not. If the latter, then the program wont print any output in this case.
8. If all the constraints are satisfied, then the program prints the output in a
text file and increases the number of cases by 1.
9. It will print outputs until the case number reaches 5.
