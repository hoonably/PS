# [Gold III] UNIST는 무엇의 약자일까? - 17841 

[문제 링크](https://www.acmicpc.net/problem/17841) 

### 성능 요약

메모리: 51116 KB, 시간: 588 ms

### 분류

다이나믹 프로그래밍

### 제출 일자

2024년 1월 20일 21:33:13

### 문제 설명

<p>UNIST는 Ulsan National Institute of Science and Technology의 약자이다. 어느 날 원이는 약자가 UNIST가 되는 다른 단어가 있는지에 대해 궁금해졌다.</p>

<p>단어 a의 길이를 len(a)로 표기하자. N개의 단어 W<sub>1</sub>, W<sub>2</sub>, ..., W<sub>N</sub>이 주어질 때, 단어 W<span style="font-size: 10.8333px;">i</span> (1 ≤ i ≤ N)로부터 앞에서 0글자 이상 len(W<sub>i</sub>)글자 이하 택해서 만든 문자열을 P<sub>i</sub>라 하자. 다시 말해, P<sub>i</sub>는 W<sub>i</sub>의 길이 len(P<sub>i</sub>)인 접두사이다.</p>

<p>P<sub>i</sub> (1 ≤ i ≤ N)들을 적당히 잘 정하여, P<sub>1</sub>+P<sub>2</sub>+...+P<sub>N</sub>이 UNIST가 되도록 하는 경우의 수를 구해보자. 단, 연산 +는 문자열 연결(string concatenation) 연산이다.</p>

### 입력 

 <p>첫 줄에 단어의 수 N이 주어진다.</p>

<p>이후 N개의 줄에 한 줄에 하나씩 N개의 단어 W<sub>1</sub>, W<sub>2</sub>, ..., W<sub>N</sub>가 주어진다.</p>

<p>W<sub>i</sub> (1 ≤ i ≤ N)는 1개 이상의 영문 대문자로만 이루어진 문자열이다.</p>

### 출력 

 <p>P<sub>1</sub>+P<sub>2</sub>+...+P<sub>N</sub>이 UNIST가 되도록 P<sub>1</sub>, P<sub>2</sub>, ..., P<sub>N</sub>을 결정하는 경우의 수를 1,000,000,007로 나눈 나머지를 출력한다.</p>

