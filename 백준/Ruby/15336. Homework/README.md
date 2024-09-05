# [Ruby V] Homework - 15336 

[문제 링크](https://www.acmicpc.net/problem/15336) 

### 성능 요약

메모리: 3808 KB, 시간: 8 ms

### 분류

최대 유량, 그리디 알고리즘, 최소 비용 최대 유량

### 제출 일자

2024년 9월 6일 03:31:55

### 문제 설명

<p>Taro is a student of Ibaraki College of Prominent Computing. In this semester, he takes two courses, mathematics and informatics. After each class, the teacher may assign homework. Taro may be given multiple assignments in a single class, and each assignment may have a different deadline. Each assignment has a unique ID number.</p>

<p>Everyday after school, Taro completes at most one assignment as follows. First, he decides which course’s homework to do at random by flipping a coin. Let S be the set of all the unfinished assignments of the chosen course whose deadline has not yet passed. If S is empty, he plays a video game without doing any homework on that day even if there are unfinished assignments of the other course. Otherwise, with T ⊆ S being the set of assignments with the nearest deadline among S, he completes the one with the smallest assignment ID among T.</p>

<p>The number of assignments Taro will complete until the end of the semester depends on the result of coin flips. Given the schedule of homework assignments, your task is to compute the maximum and the minimum numbers of assignments Taro will complete.</p>

### 입력 

 <p>The input consists of a single test case in the following format.</p>

<pre>n m
s<sub>1</sub> t<sub>1</sub>
.
.
.
s<sub>n</sub> t<sub>n</sub></pre>

<p>The first line contains two integers n and m satisfying 1 ≤ m < n ≤ 400. n denotes the total number of assignments in this semester, and m denotes the number of assignments of the mathematics course (so the number of assignments of the informatics course is n − m). Each assignment has a unique ID from 1 to n; assignments with IDs 1 through m are those of the mathematics course, and the rest are of the informatics course. The next n lines show the schedule of assignments. The i-th line of them contains two integers s<sub>i</sub> and t<sub>i</sub> satisfying 1 ≤ s<sub>i</sub> ≤ t<sub>i</sub> ≤ 400, which means that the assignment of ID i is given to Taro on the s<sub>i</sub>-th day of the semester, and its deadline is the end of the t<sub>i</sub>-th day.</p>

### 출력 

 <p>In the first line, print the maximum number of assignments Taro will complete. In the second line, print the minimum number of assignments Taro will complete.</p>

