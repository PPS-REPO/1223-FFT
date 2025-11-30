## 문제

Samplrate가 주어집니다. 단위는 ```Sample/sec```입니다.<br>
BufferSize 주어집니다.<br>
시간에 대한 파동의 진폭값이 주어집니다. 각 값들을 Sample이라고 부릅니다. 샘플의 개수는 ```1000ms*Samplrate```입니다.<br>
<br>
Samplrate 위에서 매 Implus마다 주어진 파동의 FFT결과를 출력합니다. FFT를 위한 Sample의 개수는 BufferSize입니다. 샘플이 부족하다면 0으로 채운 뒤 사용합니다.<br>
<br>
예를 들어서 Samplerate가 8, BufferSize가 2인 상황에서 Sample이 {s<sub>1</sub>, s<sub>2</sub>, s<sub>3</sub>, s<sub>4</sub>, s<sub>5</sub>, s<sub>6</sub>, s<sub>7</sub>, s<sub>8</sub>}처럼 주어졌다면, {s<sub>1</sub>, s<sub>2</sub>}, {s<sub>2</sub>, s<sub>3</sub>}, {s<sub>3</sub>, s<sub>4</sub>}, {s<sub>4</sub>, s<sub>5</sub>}, {s<sub>5</sub>, s<sub>6</sub>}, {s<sub>6</sub>, s<sub>7</sub>}, {s<sub>7</sub>, s<sub>8</sub>}, {s<sub>8</sub>, 0}을 각각 FFT한 후 결과를 출력하면 됩니다.<br>

## 입력

첫째줄에 자연수인 샘플레이트가 주어집니다. 샘플레이트는 1이상 768000이하 입니다.<br>
둘째줄에 자연수인 버퍼 사이즈가 주어집니다. 버퍼 사이즈는 1이상 1024이하의 2의 거듭제곱수 입니다.<br>
셋째줄에 ```1000ms*샘플레이트```개의 샘플이 공백으로 구분되어 주어집니다. 각 샘플들은 소수점 이하 4째 자리까지 주어지며, 절댓값은 1이하 입니다.<br>

## 출력

각 줄에 걸쳐 매 Implus에 대한 FFT 결과를 출력합니다. ```실수부 허수부```꼴로 출력합니다. 한 줄 내에서 각 값들은 공백으로 구분하며, 출력의 절대/상대 오차는 1e-4까지 허용합니다.<br>