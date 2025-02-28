Level 4
Visit departments
Jang keeps visiting and helping a number of departments right after he comes to work.

There is a rule in his movement. He stays at a department exactly for 10 minutes.

You are given a probability graph of their movements. Fig. 1 is an example graph.

 






Jang stays at dept. 1 for 10 minutes; then he moves to dept. 2 with a probability of 0.3 (then stays there for 10 minutes) or moves to dept. 3 with a probability of 0.7 (then stays there for 10 minutes). We do not consider the time for moving between departments.

There may be more than one outgoing arrow from a department; the sum of the chances of outgoing arrows from a department should be always 1.

The first department which he visit is always dept. 1.

Given a probability graph and a time T(in minutes), generate a program that finds the department at which Jang stays with the highest chance at time T.

In addition you have to report the corresponding probability.








In the Fig. 1 above, the department with the highest chance at time 10 is dept. 3 and the chance is 0.7. At time 9, Jang does not start moving; so he is at dept. 1 with a probability of 1.

Look at the situation at time 20. The chance of being at dept. 1 or dept. 2 is 0. He leaves dept. 1 exactly at time 10, and if he moves to dept. 2 then he leaves dept. 2 exactly at time 20.

The chance of being at dept. 4 at time 20 is 0.3*1.0+0.7*0.8=0.86.

When he arrives at a department without any outgoing arrow, the department becomes the last one that he finally visits; he stays at the department for 10 minutes and leaves work.

With the graph of Fig. 2, Jang is not in work at time 50; in case of Fig. 1, he may stay at work forever if he keeps staying at the same department with a loop probability, e.g, departments 3, 4, or 6

In addition, there is another person, Kang, who moves in the same way as  Jang.

Jang always comes to work at time 0, but Kang comes at another time later than time 0. You also have to report the same type of contents for Kang.

If Kang’s arrival time is 4, answers related to him is computed exactly the same principle as  Jang’s except he starts working 4 minutes later than Jang; in this case with Fig. 2, Kang stays at dept. 1 from time 4 to time 13 while Jang stays at dept. 1 from time 0 to time 9.

 

[Input]

 

10 test cases are given. Each case is given in two lines. Thus the input needs totally 20 lines.

 

For each case, the first line provides N (the number of departments), E (the number of arrows), K (Kang’s arrival time), and T (the time in minutes).

1<=N<=100. 1<=E<=200. 1<=K<=1000. 0<=T<=1000. K<=T.

The next line enumerates E arrows. Each arrow is denoted by “source-dept destination-dept probability”. The index for source dept. or destination dept. is an integer in 1 through 100, inclusive.

The time integer K and T are in minutes. For example, if the time T is 8, you have to determine the departments at which Jang and Kang, respectively, stay with the highest probabilities at time 8. The elements in the same line are separated by a space. There is no special order in which the arrows are enumerated.

[Output]

You write the 10 answers in 10 lines.

Each line starts with “#x” (Here, x means the case index.), puts a space, and writes the answer.

The answer consists of the department index with the highest chance followed by the corresponding probability. The dept. index is an integer and the probability is a real number, separated by a space.

If there is more than one department with the highest chance, you write the dept. of the lowest index.

If  Jang is not at any department at the specified time, you write just “0 0.000000”. The probability is a real number in 0 through 1, inclusive; it should be accurate to six decimal places.

Another set of a department and the corresponding probability has to be provided for  Kang. Thus the answer consists of four numbers in total.

Jang thường xuyên đến thăm và giúp đỡ một số phòng ban ngay sau khi đến làm việc.

Có một quy tắc trong cách di chuyển của anh ấy. Anh ấy ở lại một phòng ban đúng 10 phút.

Bạn được cung cấp một biểu đồ xác suất về chuyển động của chúng. Hình 1 là một biểu đồ ví dụ.

 






Jang ở lại phòng ban 1 trong 10 phút; sau đó anh ấy chuyển sang phòng ban 2 với xác suất là 0,3 (sau đó ở lại đó trong 10 phút) hoặc chuyển sang phòng ban 3 với xác suất là 0,7 (sau đó ở lại đó trong 10 phút). Chúng tôi không xem xét thời gian di chuyển giữa các phòng ban.

Có thể có nhiều hơn một mũi tên đi ra từ một phòng ban; tổng số cơ hội của các mũi tên đi ra từ một phòng ban phải luôn bằng 1.

Khoa đầu tiên anh ấy đến thăm luôn là khoa 1.

Cho một đồ thị xác suất và thời gian T (tính bằng phút), hãy tạo một chương trình tìm khoa mà Jang có cơ hội làm việc cao nhất tại thời điểm T.

Ngoài ra bạn phải báo cáo xác suất tương ứng.








Trong Hình 1 ở trên, phòng ban có cơ hội cao nhất tại thời điểm 10 là phòng ban 3 và cơ hội là 0,7. Tại thời điểm 9, Jang không bắt đầu di chuyển; do đó anh ấy ở phòng ban 1 với xác suất là 1.

Hãy xem xét tình huống tại thời điểm 20. Xác suất ở phòng 1 hoặc phòng 2 là 0. Anh ta rời khỏi phòng 1 đúng vào thời điểm 10, và nếu anh ta chuyển đến phòng 2 thì anh ta rời khỏi phòng 2 đúng vào thời điểm 20.

Xác suất để ở mức nợ 4 tại thời điểm 20 là 0,3*1,0+0,7*0,8=0,86.

Khi anh ta đến một phòng ban mà không có mũi tên nào hướng ra ngoài, phòng ban đó sẽ là phòng ban cuối cùng mà anh ta ghé thăm; anh ta ở lại phòng ban đó trong 10 phút rồi rời khỏi nơi làm việc.

Với đồ thị của Hình 2, Jang không làm việc tại thời điểm 50; trong trường hợp của Hình 1, anh ta có thể ở lại làm việc mãi mãi nếu anh ta tiếp tục ở lại cùng một phòng ban với xác suất lặp, ví dụ, phòng ban 3, 4 hoặc 6

Ngoài ra, còn có một người nữa tên là Kang, người có cách di chuyển giống như Jang.

Jang luôn đến làm việc vào thời điểm 0, nhưng Kang lại đến vào thời điểm khác muộn hơn thời điểm 0. Bạn cũng phải báo cáo cùng loại nội dung cho Kang.

Nếu thời gian đến của Kang là 4, các câu trả lời liên quan đến anh ấy được tính theo nguyên tắc chính xác giống như của Jang, ngoại trừ việc anh ấy bắt đầu làm việc muộn hơn Jang 4 phút; trong trường hợp này với Hình 2, Kang ở lại phòng ban 1 từ thời điểm 4 đến thời điểm 13 trong khi Jang ở lại phòng ban 1 từ thời điểm 0 đến thời điểm 9.

 

[Đầu vào]

 

Có 10 trường hợp thử nghiệm được đưa ra. Mỗi trường hợp được đưa ra trên hai dòng. Do đó, đầu vào cần tổng cộng 20 dòng.

 

Đối với mỗi trường hợp, dòng đầu tiên cung cấp N (số phòng ban), E (số mũi tên), K (thời gian đến của Kang) và T (thời gian tính bằng phút).

1<=N<=100. 1<=E<=200. 1<=K<=1000. 0<=T<=1000. K<=T.

Dòng tiếp theo liệt kê E mũi tên. Mỗi mũi tên được biểu thị bằng “xác suất nguồn-phòng ban đích-phòng ban”. Chỉ số cho phòng ban nguồn hoặc phòng ban đích là một số nguyên từ 1 đến 100, bao gồm.

Số nguyên thời gian K và T tính bằng phút. Ví dụ, nếu thời gian T là 8, bạn phải xác định các khoa mà Jang và Kang, tương ứng, ở lại với xác suất cao nhất tại thời điểm 8. Các phần tử trên cùng một dòng được phân tách bằng một khoảng trắng. Không có thứ tự đặc biệt nào trong đó các mũi tên được liệt kê.

[Đầu ra]

Bạn viết 10 câu trả lời trong 10 dòng.

Mỗi dòng bắt đầu bằng “#x” (Ở đây, x có nghĩa là chỉ số trường hợp), đặt một khoảng trắng và viết câu trả lời.

Câu trả lời bao gồm chỉ số khoa có cơ hội cao nhất theo sau là xác suất tương ứng. Chỉ số khoa là một số nguyên và xác suất là một số thực, được phân tách bằng dấu cách.

Nếu có nhiều hơn một khoa có cơ hội cao nhất, bạn hãy viết khoa có chỉ số thấp nhất.

Nếu Jang không có mặt ở bất kỳ phòng ban nào vào thời điểm đã chỉ định, bạn chỉ cần viết “0 0.000000”. Xác suất là một số thực từ 0 đến 1, bao gồm cả 0 và 1; xác suất này phải chính xác đến sáu chữ số thập phân.

Một tập hợp khác của một bộ phận và xác suất tương ứng phải được cung cấp cho Kang. Do đó, câu trả lời bao gồm tổng cộng bốn số.


Input

6 7 100 100

1 2 0.3 1 3 0.7 2 4 1.0 3 4 0.7 3 6 0.3 4 5 1.0 5 6 1.0

6 7 1 23

1 2 0.3 1 3 0.7 2 4 1.0 3 4 0.7 3 6 0.3 4 5 1.0 5 6 1.0

6 10 8 40

1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

6 10 10 10

1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

 

6 10 9 20

1 2 0.3 1 3 0.7 3 3 0.2 3 4 0.8 2 4 1 4 5 0.9 4 4 0.1 5 6 1.0 6 3 0.5 6 6 0.5

Output

#1 0 0.000000 1 1.000000

#2 4 0.790000 4 0.790000

#3 6 0.774000 5 0.774000

#4 3 0.700000 1 1.000000

#5 4 0.860000 3 0.700000


#1 1 1.000000 1 1.000000
#2 11 1.000000 18 1.000000
#3 4 0.386860 4 0.386860
#4 10 0.946340 10 0.851171 (so thap phan dau sai do lam tron) // loi output => dung float
#5 3 0.150855 1 1.000000
#6 15 0.284926 7 0.505935
#7 4 0.118507 4 0.118507
#8 5 0.121474 5 0.121474
#9 3 0.591954 3 0.637576
#10 7 0.314579 6 0.280350

#1 1 1.000000 1 1.000000
#2 11 1.000000 18 1.000000
#3 4 0.386860 4 0.386860
#4 10 0.946341 10 0.851171
#5 3 0.150855 1 1.000000
#6 15 0.284926 7 0.505935
#7 4 0.118507 4 0.118507
#8 5 0.121474 5 0.121474
#9 3 0.591954 3 0.637576
#10 7 0.314579 6 0.280350
Time: 0.04600 s.
#include <iostream>
#include <time.h>

using namespace std;

int oo = 2000000000;

int T = 10, n, e, t, k;
int ans[2];
double result[2], prv[101], curr[101], mp[101][101];

void calcChance(int index, int start){
	if(start > t) return;
	int timei = start;
	while(timei <= t){
		if(timei == start){
			curr[1] = 1.0;
		} else{
			for(int i = 1; i <= n; i++){
				prv[i] = curr[i];
				curr[i] = 0;
			}
			int cnt = 0;
			for(int i = 1; i <= n; i++){
				if(prv[i] != 0.0){
					for(int j = 1; j <= n; j++){
						curr[j] += mp[i][j]*prv[i];
					}
				} else{
					cnt++;
				}
			}
			if(cnt == n){
				return;
			}
		}

		timei += 10;
	}
	result[index] = 0.0, ans[index] = 0;
	for(int i = 1; i <= n; i++){
		if(result[index] < curr[i]){
			result[index] = curr[i];
			ans[index] = i;
		}
	}
}

int main(){
	// read input
	freopen("input.txt", "r", stdin);

	//calc time
	clock_t tStart, tStop;
	tStart = clock();

	//cin >> T;
	
	for(int tc = 1; tc <= T; tc++){
		// input and initial
		cin >> n;
		cin >> e;
		cin >> k;
		cin >> t;

		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				mp[i][j] = 0.0;
			}
			prv[i] = 0.0;
			curr[i] = 0.0;
		}

		for(int i = 0; i < e; i++){
			int x, y;
			cin >> x >> y;
			cin >> mp[x][y];
		}
		ans[0] = 0, ans[1] = 0;
		result[0] = 0.0, result[1] = 0.0;

		// solve problem
		calcChance(0, 0);

			//reset chance arr
		for(int i = 1; i <= n; i++) prv[i] = 0.0, curr[i] = 0.0;
		calcChance(1, k);

		// output
		cout.setf(ios::fixed);
		cout.precision(6);
		cout << "#" << tc << " ";
		cout << ans[0] << " " << result[0] << " ";
		cout << ans[1] << " " << result[1] << "\n"; 
	}


	//calc time
	tStop = clock();
	cout.setf(ios::fixed);
	cout.precision(5);
	cout << "Time: " << double(tStop - tStart) / CLOCKS_PER_SEC << " s." << endl;

	return 0;
}
